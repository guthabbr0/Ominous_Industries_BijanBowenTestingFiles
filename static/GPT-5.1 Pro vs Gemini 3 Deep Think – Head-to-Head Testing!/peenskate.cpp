/*******************************************************************************************
*
* SKATE_GAME.CPP - A self-contained 3D skateboarding game
*
* CONTROLS:
* [W/S] or [UP/DOWN] : Accelerate / Brake
* [A/D] or [LEFT/RIGHT] : Turn
* [SPACE] : Ollie (Jump)
* [J] : Kickflip
* [K] : Heelflip
* [L] : Pop Shove-it
* [R] : Reset Player
*
* GAMEPLAY:
* - Skate around the park.
* - Jump onto the RED/GOLD RAILS to grind (must be falling downwards).
* - Hit ramps to get air.
* - Perform tricks while airborne to build combos.
*
********************************************************************************************/

#include "raylib.h"
#include "rlgl.h" // Required for matrix transformations
#include "raymath.h"
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

// ----------------------------------------------------------------------------------
// Configuration & Constants
// ----------------------------------------------------------------------------------
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// Physics Constants
const float MAX_SPEED = 22.0f;
const float ACCEL = 15.0f;
const float TURN_SPEED = 3.5f;
const float FRICTION = 0.98f;
const float GRAVITY = 35.0f;
const float JUMP_FORCE = 13.0f;
const float RAIL_SNAP_DIST = 1.5f; // Distance to snap to rail

// ----------------------------------------------------------------------------------
// Types
// ----------------------------------------------------------------------------------
enum State {
    STATE_GROUND,
    STATE_AIR,
    STATE_GRIND
};

struct Rail {
    Vector3 start;
    Vector3 end;
    float height;
    Color color;
};

struct Ramp {
    Vector3 pos;   // Center of the base
    Vector3 size;  // Width, Height, Length
    float rotation; // Rotation in degrees
    Color color;
};

struct Player {
    Vector3 pos;
    Vector3 vel;
    float rot;      // Facing direction (degrees)
    State state;

    // Visuals / Animation
    float boardRotX; // Kickflip axis
    float boardRotZ; // Shuvit axis
    float lean;      // Turning lean

    // Scoring
    int score;
    int comboScore;
    int comboMult;
    std::string trickText;
    float messageTimer;
};

// ----------------------------------------------------------------------------------
// Global Game State
// ----------------------------------------------------------------------------------
Player player;
Camera3D camera;
std::vector<Rail> rails;
std::vector<Ramp> ramps;

// ----------------------------------------------------------------------------------
// Math Helpers
// ----------------------------------------------------------------------------------

// Get the point on line segment AB that is closest to point P
Vector3 ClosestPointOnSegment(Vector3 p, Vector3 a, Vector3 b) {
    Vector3 ab = Vector3Subtract(b, a);
    float t = Vector3DotProduct(Vector3Subtract(p, a), ab) / Vector3DotProduct(ab, ab);
    t = Clamp(t, 0.0f, 1.0f);
    return Vector3Add(a, Vector3Scale(ab, t));
}

float Deg2Rad(float deg) { return deg * (PI / 180.0f); }

// Helper to darken a color (0.0 to 1.0 factor)
// FIX: Added this missing function
Color Darken(Color color, float factor) {
    unsigned char r = (unsigned char)((float)color.r * (1.0f - factor));
    unsigned char g = (unsigned char)((float)color.g * (1.0f - factor));
    unsigned char b = (unsigned char)((float)color.b * (1.0f - factor));
    return (Color){r, g, b, color.a};
}

// ----------------------------------------------------------------------------------
// Initialization
// ----------------------------------------------------------------------------------
void ResetGame() {
    player.pos = (Vector3){ 0.0f, 0.5f, 0.0f };
    player.vel = (Vector3){ 0.0f, 0.0f, 0.0f };
    player.rot = 0.0f;
    player.state = STATE_GROUND;
    player.boardRotX = 0;
    player.boardRotZ = 0;
    player.lean = 0;
    player.score = 0;
    player.comboScore = 0;
    player.comboMult = 1;
    player.trickText = "";
    player.messageTimer = 0.0f;

    camera.position = (Vector3){ 0.0f, 5.0f, -10.0f };
    camera.target = player.pos;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void InitLevel() {
    rails.clear();
    ramps.clear();

    // 1. Long Straight Rail (Red)
    rails.push_back({ { 5.0f, 0.0f, 10.0f }, { 5.0f, 0.0f, 40.0f }, 1.5f, RED });
    
    // 2. Cross Rail (Gold)
    rails.push_back({ { -20.0f, 0.0f, 25.0f }, { -5.0f, 0.0f, 25.0f }, 2.0f, GOLD });

    // 3. Main Kicker Ramp
    ramps.push_back({ { 0.0f, 0.0f, 25.0f }, { 8.0f, 3.0f, 10.0f }, 0.0f, BLUE });

    // 4. Side Hip Ramp
    ramps.push_back({ { -15.0f, 0.0f, 5.0f }, { 6.0f, 2.5f, 8.0f }, 90.0f, DARKBLUE });
    
    // 5. Quarter Pipe (Large Backstop)
    ramps.push_back({ { 0.0f, 0.0f, 60.0f }, { 30.0f, 8.0f, 15.0f }, 180.0f, PURPLE });
}

// ----------------------------------------------------------------------------------
// Game Logic
// ----------------------------------------------------------------------------------
void UpdateGame(float dt) {
    // --- Input ---
    if (IsKeyPressed(KEY_R)) ResetGame();

    float turnInput = 0.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) turnInput = 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) turnInput = -1.0f;

    float moveInput = 0.0f;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) moveInput = 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) moveInput = -1.0f;

    // --- Physics: Turning & Accel ---
    if (player.state != STATE_GRIND) {
        player.rot += turnInput * TURN_SPEED;
        player.lean = Lerp(player.lean, turnInput * -15.0f, 5.0f * dt);
    }

    Vector3 forward = { sinf(Deg2Rad(player.rot)), 0.0f, cosf(Deg2Rad(player.rot)) };

    if (player.state == STATE_GROUND) {
        player.vel = Vector3Add(player.vel, Vector3Scale(forward, moveInput * ACCEL * dt));
        // Friction
        player.vel.x *= FRICTION;
        player.vel.z *= FRICTION;
    }

    // Speed Cap
    if (Vector3Length(player.vel) > MAX_SPEED) {
        player.vel = Vector3Scale(Vector3Normalize(player.vel), MAX_SPEED);
    }

    // Gravity
    if (player.state != STATE_GRIND) {
        player.vel.y -= GRAVITY * dt;
    }

    // --- Interaction: Grinding ---
    // Check if we can snap to a rail
    if (player.state == STATE_AIR && player.vel.y < 0) {
        for (const auto& rail : rails) {
            Vector3 closest = ClosestPointOnSegment(player.pos, rail.start, rail.end);
            float dist = Vector3Distance(player.pos, closest);
            
            // Check proximity and height (must be falling ONTO the rail)
            if (dist < RAIL_SNAP_DIST && player.pos.y >= rail.height - 0.5f && player.pos.y <= rail.height + 1.0f) {
                // Enter Grind State
                player.state = STATE_GRIND;
                player.pos = closest;
                player.pos.y = rail.height + 0.2f; // Sit on top
                player.vel.y = 0;
                
                // Align velocity to rail direction
                Vector3 railDir = Vector3Normalize(Vector3Subtract(rail.end, rail.start));
                float currentSpeed = Vector3Length({player.vel.x, 0, player.vel.z});
                if (currentSpeed < 10.0f) currentSpeed = 10.0f; // Minimum grind speed
                
                // Grind in the direction we were moving
                if (Vector3DotProduct(player.vel, railDir) < 0) railDir = Vector3Scale(railDir, -1.0f);
                
                player.vel = Vector3Scale(railDir, currentSpeed);
                
                // Score
                player.comboScore += 50;
                player.comboMult++;
                player.trickText = "Rail Grind!";
                player.messageTimer = 1.0f;
            }
        }
    }

    // Process Grind Logic
    if (player.state == STATE_GRIND) {
        // Check if we are still on ANY rail
        bool onAnyRail = false;
        for (const auto& rail : rails) {
            Vector3 c = ClosestPointOnSegment(player.pos, rail.start, rail.end);
            if (Vector3Distance(player.pos, c) < 0.5f) onAnyRail = true;
        }

        if (!onAnyRail) {
            player.state = STATE_AIR; // Fell off end
            player.vel.y = -2.0f; // Pop down slightly
        } else {
            // Add combo score over time while grinding
            if ((int)(GetTime() * 10) % 5 == 0) player.comboScore += 1; 
        }
    }

    // --- Movement Integration ---
    player.pos = Vector3Add(player.pos, Vector3Scale(player.vel, dt));

    // --- Collision: Floor & Ramps ---
    float floorHeight = 0.0f;
    bool onRamp = false;

    for (const auto& ramp : ramps) {
        // Convert player pos to ramp-local space to handle rotation
        Vector3 d = Vector3Subtract(player.pos, ramp.pos);
        float rad = Deg2Rad(-ramp.rotation);
        float localX = d.x * cosf(rad) - d.z * sinf(rad);
        float localZ = d.x * sinf(rad) + d.z * cosf(rad);
        
        float halfW = ramp.size.x / 2;
        float halfL = ramp.size.z / 2;

        if (fabs(localX) < halfW && fabs(localZ) < halfL) {
            // Calculate height on slope (linear 0 to H)
            // Ramp goes from -halfL (height 0) to +halfL (height H) in local Z
            float t = (localZ + halfL) / ramp.size.z;
            float h = t * ramp.size.y;
            
            if (h > floorHeight) {
                floorHeight = h;
                onRamp = true;
            }
        }
    }

    // Floor Snap / Landing
    if (player.pos.y <= floorHeight) {
        player.pos.y = floorHeight;
        
        if (player.vel.y < 0) player.vel.y = 0; // Stop falling
        
        if (player.state == STATE_AIR || player.state == STATE_GRIND) {
            // Landed
            player.state = STATE_GROUND;
            player.lean = 0;
            
            // Bank Score
            if (player.comboScore > 0) {
                player.score += player.comboScore * player.comboMult;
                player.trickText = "Landed! +" + std::to_string(player.comboScore * player.comboMult);
                player.messageTimer = 2.0f;
                player.comboScore = 0;
                player.comboMult = 1;
            }
        }
    } else if (player.pos.y > floorHeight + 0.1f && player.state != STATE_GRIND) {
        player.state = STATE_AIR;
    }

    // --- Actions: Jump & Tricks ---
    if (IsKeyPressed(KEY_SPACE) && (player.state == STATE_GROUND || player.state == STATE_GRIND)) {
        player.vel.y = JUMP_FORCE;
        player.state = STATE_AIR;
        player.trickText = "Ollie";
        player.messageTimer = 1.0f;
        player.comboScore += 10;
    }

    if (player.state == STATE_AIR) {
        if (IsKeyPressed(KEY_J)) {
            player.comboScore += 100; player.comboMult++;
            player.trickText = "Kickflip"; player.messageTimer = 1.0f;
            player.boardRotX = 360.0f;
        }
        if (IsKeyPressed(KEY_K)) {
            player.comboScore += 100; player.comboMult++;
            player.trickText = "Heelflip"; player.messageTimer = 1.0f;
            player.boardRotX = -360.0f;
        }
        if (IsKeyPressed(KEY_L)) {
            player.comboScore += 150; player.comboMult++;
            player.trickText = "Pop Shuvit"; player.messageTimer = 1.0f;
            player.boardRotZ = 360.0f;
        }
    }

    // --- Animation Smoothing ---
    // Smoothly interpolate rotation back to 0
    float rotSpeed = 720.0f * dt;
    if (player.boardRotX > 0) player.boardRotX -= rotSpeed;
    if (player.boardRotX < 0) player.boardRotX += rotSpeed;
    if (player.boardRotZ > 0) player.boardRotZ -= rotSpeed;
    if (abs(player.boardRotX) < 10.0f) player.boardRotX = 0;
    if (abs(player.boardRotZ) < 10.0f) player.boardRotZ = 0;

    // --- Camera Follow ---
    Vector3 targetPos = Vector3Add(player.pos, (Vector3){0, 2.0f, 0});
    Vector3 idealCamPos = Vector3Subtract(player.pos, Vector3Scale(forward, 8.0f));
    idealCamPos.y = player.pos.y + 4.0f;
    
    // Smooth Camera
    // FIX: Changed Lerp to Vector3Lerp
    camera.position.x = Lerp(camera.position.x, idealCamPos.x, 5.0f * dt);
    camera.position.y = Lerp(camera.position.y, idealCamPos.y, 5.0f * dt);
    camera.position.z = Lerp(camera.position.z, idealCamPos.z, 5.0f * dt);
    camera.target = Vector3Lerp(camera.target, targetPos, 10.0f * dt); // Look at player

    if (player.messageTimer > 0) player.messageTimer -= dt;
    
    // Bounds Check
    if (player.pos.y < -10.0f) ResetGame();
}

// ----------------------------------------------------------------------------------
// Rendering
// ----------------------------------------------------------------------------------
void DrawGame() {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    BeginMode3D(camera);
        // 1. Draw Ground
        DrawPlane((Vector3){0,0,0}, (Vector2){200, 200}, DARKGRAY);
        DrawGrid(20, 10.0f);

        // 2. Draw Rails
        for (const auto& rail : rails) {
            // Legs
            DrawCylinder((Vector3){rail.start.x, rail.height/2, rail.start.z}, 0.1f, 0.1f, rail.height, 8, BLACK);
            DrawCylinder((Vector3){rail.end.x, rail.height/2, rail.end.z}, 0.1f, 0.1f, rail.height, 8, BLACK);
            // Rail Bar
            DrawCapsule(rail.start, rail.end, 0.15f, 8, 12, rail.color);
        }

        // 3. Draw Ramps
        for (const auto& ramp : ramps) {
            rlPushMatrix();
            rlTranslatef(ramp.pos.x, ramp.pos.y, ramp.pos.z);
            rlRotatef(ramp.rotation, 0, 1, 0);

            float w = ramp.size.x / 2;
            float l = ramp.size.z / 2;
            float h = ramp.size.y;

            // Draw Wedge Shape manually
            // Vertices:
            // Base: (-w, 0, -l) to (w, 0, l)
            // Top Edge: (-w, h, l) to (w, h, l)
            
            // Slope Face
            DrawTriangle3D({-w, 0, -l}, {-w, h, l}, {w, h, l}, ramp.color);
            DrawTriangle3D({w, h, l}, {w, 0, -l}, {-w, 0, -l}, ramp.color);
            
            // Back Face
            DrawTriangle3D({-w, h, l}, {-w, 0, l}, {w, 0, l}, Darken(ramp.color, 0.2f));
            DrawTriangle3D({w, 0, l}, {w, h, l}, {-w, h, l}, Darken(ramp.color, 0.2f));

            // Sides
            DrawTriangle3D({-w, 0, -l}, {-w, 0, l}, {-w, h, l}, Darken(ramp.color, 0.3f));
            DrawTriangle3D({w, h, l}, {w, 0, l}, {w, 0, -l}, Darken(ramp.color, 0.3f));

            rlPopMatrix();
        }

        // 4. Draw Player
        rlPushMatrix();
            rlTranslatef(player.pos.x, player.pos.y, player.pos.z);
            rlRotatef(player.rot, 0, 1, 0); // Face direction
            
            // Board Group (Tricks rotate this)
            rlPushMatrix();
                rlTranslatef(0, 0.15f, 0);
                rlRotatef(player.lean, 0, 0, 1);       // Turning Lean
                rlRotatef(player.boardRotX, 1, 0, 0);  // Kickflip
                rlRotatef(player.boardRotZ, 0, 1, 0);  // Shuvit
                
                // Deck
                DrawCube({0,0,0}, 0.4f, 0.05f, 1.3f, MAROON); 
                DrawCube({0,0.03f,0}, 0.4f, 0.05f, 1.0f, BLACK); // Grip tape center
                
                // Wheels
                DrawCube({0.15f, -0.05f, 0.4f}, 0.08f, 0.08f, 0.08f, WHITE);
                DrawCube({-0.15f, -0.05f, 0.4f}, 0.08f, 0.08f, 0.08f, WHITE);
                DrawCube({0.15f, -0.05f, -0.4f}, 0.08f, 0.08f, 0.08f, WHITE);
                DrawCube({-0.15f, -0.05f, -0.4f}, 0.08f, 0.08f, 0.08f, WHITE);
            rlPopMatrix();

            // Skater Body (Simplified)
            // Only draw upright if not bailing (bail state not fully impl, but good practice)
            rlTranslatef(0, 1.0f, 0);
            DrawCube({0,0,0}, 0.4f, 1.4f, 0.25f, BEIGE); // Body
            DrawSphere({0,0.8f,0}, 0.2f, PINK);          // Head
            // Arms
            DrawCube({0.35f, 0.3f, 0}, 0.15f, 0.6f, 0.15f, BEIGE);
            DrawCube({-0.35f, 0.3f, 0}, 0.15f, 0.6f, 0.15f, BEIGE);
        rlPopMatrix();

    EndMode3D();

    // 5. Draw HUD
    DrawText("RAYLIB SKATE SIM", 20, 20, 20, DARKGRAY);
    DrawText(TextFormat("SCORE: %06i", player.score), 20, 50, 40, DARKBLUE);
    
    if (player.comboScore > 0) {
        DrawText(TextFormat("COMBO: %i x %i", player.comboScore, player.comboMult), 20, 100, 30, ORANGE);
    }
    
    if (player.messageTimer > 0) {
        int textW = MeasureText(player.trickText.c_str(), 40);
        DrawText(player.trickText.c_str(), SCREEN_WIDTH/2 - textW/2, SCREEN_HEIGHT/4, 40, PURPLE);
    }

    DrawText("WASD: Move | SPACE: Ollie | J/K/L: Tricks | R: Reset", 20, SCREEN_HEIGHT - 30, 20, DARKGRAY);

    EndDrawing();
}

// ----------------------------------------------------------------------------------
// Main
// ----------------------------------------------------------------------------------
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "C++ Skateboarding");
    SetTargetFPS(60);
    
    ResetGame();
    InitLevel();

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        UpdateGame(dt);
        DrawGame();
    }

    CloseWindow();
    return 0;
}