# Ominous Industries - Copilot Instructions

This repository hosts static content for Bijan Bowen's YouTube channel, including interactive demos and supplementary materials for AI-focused videos. The content is automatically deployed to GitHub Pages.

## Quick Start

- **Language**: HTML, CSS, JavaScript (client-side only)
- **Build**: No build step required - static content only
- **Deploy**: Automatic via GitHub Actions on push to `main`
- **Test**: Open HTML files in a browser to verify functionality

## Repository Structure

```
/
├── .github/
│   ├── instructions/        # Detailed guidelines (see below)
│   └── workflows/          # GitHub Actions (static.yml)
├── static/                 # Main content directory
│   └── [Video Title]/     # One folder per YouTube video
│       └── [demo files]   # HTML, CSS, JS files
└── index.html             # Root index (auto-generated)
```

## Development Workflow

1. **Adding New Content**:
   - Create a folder in `/static/` matching the YouTube video title
   - Add HTML, CSS, and JavaScript files
   - Test locally by opening HTML files in a browser
   - Commit and push to `main` branch

2. **Automatic Deployment**:
   - GitHub Actions workflow (`.github/workflows/static.yml`) runs on push
   - Generates an index.html with folder/file listings
   - Deploys to GitHub Pages automatically

3. **No Build Commands**: This is a static content repository with no build step

## Essential Guidelines

### 🎨 Color Palette (CRITICAL)

**ALWAYS use warm, orangey tones - NEVER use purples, violets, or dark backgrounds:**

```css
/* ✅ CORRECT - Warm orangey palette */
:root {
    --color-primary: #E07B39;        /* Warm Orange */
    --bg-primary: #FDF8F3;           /* Warm White */
    --bg-card: #FBF4ED;              /* Cream */
    --text-primary: #3D3936;         /* Warm Charcoal */
}

/* ❌ FORBIDDEN - Never use these */
--primary: #6366f1;                  /* Purple - NO! */
--bg: #0f172a;                       /* Dark slate - NO! */
--accent: #8b5cf6;                   /* Violet - NO! */
```

**Colors to AVOID**:
- ❌ Purple/violet shades (`#6366f1`, `#8b5cf6`, `#a855f7`)
- ❌ Dark backgrounds (`#0f172a`, `#1e293b`)
- ❌ Cool-toned grays (`#94a3b8`, `#334155`)

See `.github/instructions/style.instructions.md` for complete color guidelines.

### 🔒 Security Requirements

1. **Prevent XSS**: Use `textContent` instead of `innerHTML` for user data
2. **Safe JSON**: Use `<script type="application/json">` for data embedding
3. **Escape outputs**: Always escape HTML when displaying dynamic content
4. **URL encoding**: Use `encodeURIComponent()` for URLs

Example of safe JSON embedding:
```html
<script id="data" type="application/json">
    DATA_HERE
</script>
<script>
    const data = JSON.parse(document.getElementById('data').textContent);
</script>
```

See `.github/instructions/security.instructions.md` for full security guidelines.

### 📝 Code Standards

- **HTML**: 4-space indentation, semantic elements, proper meta tags
- **CSS**: Use CSS variables, mobile-first responsive design
- **JavaScript**: ES6+ syntax, `const`/`let` (not `var`), descriptive names
- **Naming**: kebab-case for CSS classes, camelCase for JS variables

See `.github/instructions/coding-standards.instructions.md` for detailed standards.

### 📂 File Organization

- Folder names should match YouTube video titles exactly
- Use descriptive file names: `index.html`, `demo.html`, not `page1.html`
- One folder per video in `/static/` directory

See `.github/instructions/repository.instructions.md` for file organization details.

## GitHub Actions Workflow

The `.github/workflows/static.yml` workflow:
1. Checks out the repository
2. Generates `static/index.html` with folder/file listings
3. Deploys everything to GitHub Pages

**Important**: The generated index.html MUST use the warm orangey color palette, not purple/dark themes.

See `.github/instructions/workflow.instructions.md` for workflow details.

## Testing Your Changes

Since this is a static content repository:

1. **Local testing**: Open HTML files directly in your browser
2. **Check console**: Open browser DevTools (F12) and check for JavaScript errors
3. **Test responsiveness**: Resize browser window or use device emulation
4. **Verify colors**: Ensure warm orangey palette is used (no purples/dark themes)
5. **Check links**: Verify all internal links work correctly

## Common Tasks

### Fix Style Issues
If you see purple colors or dark backgrounds, update to use:
- Primary: `#E07B39` (warm orange)
- Background: `#FDF8F3` (warm white)
- Text: `#3D3936` (warm charcoal)

### Add New Demo
1. Create folder in `/static/` with video title
2. Add your HTML/CSS/JS files
3. Test locally in browser
4. Commit and push to `main`

### Update Documentation
Documentation files are in `.github/instructions/` - update as needed.

## Detailed Guidelines

For comprehensive guidance on specific topics, see:

- **Style Guide**: `.github/instructions/style.instructions.md` - Visual design, color palette
- **Security**: `.github/instructions/security.instructions.md` - XSS prevention, safe practices
- **Repository Structure**: `.github/instructions/repository.instructions.md` - Organization, naming
- **Coding Standards**: `.github/instructions/coding-standards.instructions.md` - Code quality, formatting
- **Workflow**: `.github/instructions/workflow.instructions.md` - CI/CD, GitHub Actions
- **Contributing**: `.github/instructions/contributing.instructions.md` - How to contribute
- **License**: `.github/instructions/license.instructions.md` - Licensing information
- **Gameplan**: `.github/instructions/gameplan.instructions.md` - Project roadmap

## Key Principles

1. **Warm, welcoming aesthetic** - Use orangey tones, light backgrounds
2. **Security first** - Prevent XSS, escape outputs, validate inputs
3. **Simple and static** - No build process, no dependencies
4. **Mobile-friendly** - Responsive design for all devices
5. **Accessible** - Clear contrast, semantic HTML, keyboard navigation

## What to Do Before Committing

- [ ] Colors follow warm orangey palette (NO purples or dark backgrounds)
- [ ] HTML validates (proper structure, no syntax errors)
- [ ] JavaScript has no console errors
- [ ] Files tested in browser
- [ ] Security: outputs are escaped, no XSS vulnerabilities
- [ ] Mobile responsive (tested at different screen sizes)

## Questions?

Create an issue or check the detailed instruction files in `.github/instructions/` for specific guidance.

---

*Website*: https://www.bijanbowen.com/  
*YouTube*: https://www.youtube.com/@Bijanbowen
