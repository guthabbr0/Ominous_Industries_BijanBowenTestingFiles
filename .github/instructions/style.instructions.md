# 🎨 Style Guide Instructions

This document defines the visual and design standards for the Ominous Industries repository. All contributions must adhere to these guidelines to maintain a consistent, welcoming aesthetic.

---

## Color Philosophy

The visual identity of this project is inspired by warmth, approachability, and calm. We embrace:

- **Warm, inviting tones** that feel welcoming and trustworthy
- **Light backgrounds** with gentle contrast
- **Earthy, natural colors** that reduce eye strain
- **Accessibility-first** color choices

---

## Official Color Palette

### Primary Colors

| Name | Hex Code | RGB | Usage |
|------|----------|-----|-------|
| **Warm Orange** | `#E07B39` | `224, 123, 57` | Primary accents, buttons, links |
| **Soft Coral** | `#E8A87C` | `232, 168, 124` | Secondary accents, highlights |
| **Burnt Sienna** | `#C2703F` | `194, 112, 63` | Hover states, emphasis |
| **Peach** | `#F5D0C5` | `245, 208, 197` | Subtle backgrounds, cards |

### Background Colors

| Name | Hex Code | RGB | Usage |
|------|----------|-----|-------|
| **Warm White** | `#FDF8F3` | `253, 248, 243` | Main page background |
| **Cream** | `#FBF4ED` | `251, 244, 237` | Card backgrounds |
| **Soft Sand** | `#F7EDE5` | `247, 237, 229` | Secondary sections |
| **Light Terracotta** | `#F2E4D9` | `242, 228, 217` | Borders, dividers |

### Text Colors

| Name | Hex Code | RGB | Usage |
|------|----------|-----|-------|
| **Warm Charcoal** | `#3D3936` | `61, 57, 54` | Primary text |
| **Coffee Brown** | `#5C524A` | `92, 82, 74` | Secondary text |
| **Muted Brown** | `#8B7D73` | `139, 125, 115` | Captions, hints |

### Accent Colors

| Name | Hex Code | RGB | Usage |
|------|----------|-----|-------|
| **Sage Green** | `#9CAF88` | `156, 175, 136` | Success states |
| **Terracotta** | `#C97B5D` | `201, 123, 93` | Warnings |
| **Dusty Rose** | `#D4A5A5` | `212, 165, 165` | Error states (soft) |

---

## Colors to AVOID

The following colors are **NOT** to be used in this project:

### ❌ Purples and Violets
- No `#6366f1`, `#8b5cf6`, `#a855f7` or any purple/violet shades
- No indigo (`#4f46e5`, `#6366f1`)
- No magenta or fuchsia tones

### ❌ Dark Backgrounds
- No dark slate (`#0f172a`, `#1e293b`)
- No navy or dark blue backgrounds
- No black or near-black backgrounds

### ❌ Cool-Toned Grays
- Avoid blue-tinted grays (`#94a3b8`, `#334155`)
- Use warm grays or browns instead

### ❌ Neon or High-Saturation Colors
- No electric blues, hot pinks, or lime greens
- Keep saturation levels moderate

---

## CSS Variables Template

```css
:root {
    /* Primary Palette */
    --color-primary: #E07B39;
    --color-primary-light: #E8A87C;
    --color-primary-dark: #C2703F;
    --color-primary-subtle: #F5D0C5;
    
    /* Backgrounds */
    --bg-primary: #FDF8F3;
    --bg-secondary: #FBF4ED;
    --bg-tertiary: #F7EDE5;
    --bg-card: #FBF4ED;
    --border-color: #F2E4D9;
    
    /* Text */
    --text-primary: #3D3936;
    --text-secondary: #5C524A;
    --text-muted: #8B7D73;
    
    /* States */
    --color-success: #9CAF88;
    --color-warning: #C97B5D;
    --color-error: #D4A5A5;
    
    /* Shadows */
    --shadow-sm: 0 2px 8px rgba(224, 123, 57, 0.08);
    --shadow-md: 0 4px 16px rgba(224, 123, 57, 0.12);
    --shadow-lg: 0 8px 32px rgba(224, 123, 57, 0.16);
    
    /* Gradients */
    --gradient-primary: linear-gradient(135deg, #E07B39 0%, #E8A87C 100%);
    --gradient-subtle: linear-gradient(135deg, #FDF8F3 0%, #F7EDE5 100%);
}
```

---

## Typography Guidelines

### Font Stack

```css
font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 
             'Oxygen', 'Ubuntu', 'Cantarell', 'Fira Sans', 'Droid Sans', 
             'Helvetica Neue', sans-serif;
```

### Font Sizes

| Element | Size | Weight | Line Height |
|---------|------|--------|-------------|
| H1 | `2.5rem` (40px) | 700 | 1.2 |
| H2 | `2rem` (32px) | 700 | 1.3 |
| H3 | `1.5rem` (24px) | 600 | 1.4 |
| H4 | `1.25rem` (20px) | 600 | 1.4 |
| Body | `1rem` (16px) | 400 | 1.6 |
| Small | `0.875rem` (14px) | 400 | 1.5 |
| Caption | `0.75rem` (12px) | 400 | 1.5 |

### Text Styling

- **Headings**: Use `--text-primary` color
- **Body text**: Use `--text-secondary` color
- **Captions and hints**: Use `--text-muted` color
- **Links**: Use `--color-primary` with underline on hover

---

## Component Styling

### Buttons

```css
.btn-primary {
    background: var(--color-primary);
    color: white;
    padding: 0.75rem 1.5rem;
    border: none;
    border-radius: 8px;
    font-weight: 600;
    cursor: pointer;
    transition: all 0.2s ease;
}

.btn-primary:hover {
    background: var(--color-primary-dark);
    transform: translateY(-1px);
    box-shadow: var(--shadow-md);
}
```

### Cards

```css
.card {
    background: var(--bg-card);
    border: 1px solid var(--border-color);
    border-radius: 12px;
    padding: 1.5rem;
    box-shadow: var(--shadow-sm);
    transition: all 0.3s ease;
}

.card:hover {
    border-color: var(--color-primary-light);
    box-shadow: var(--shadow-md);
}
```

### Input Fields

```css
input, textarea, select {
    background: var(--bg-primary);
    border: 2px solid var(--border-color);
    border-radius: 8px;
    padding: 0.75rem 1rem;
    color: var(--text-primary);
    font-size: 1rem;
    transition: all 0.2s ease;
}

input:focus, textarea:focus, select:focus {
    outline: none;
    border-color: var(--color-primary);
    box-shadow: 0 0 0 3px rgba(224, 123, 57, 0.15);
}
```

---

## Iconography

### Preferred Emoji Style

Use simple, warm-toned emoji that align with the calm aesthetic:

| Purpose | Emoji |
|---------|-------|
| Folders | 📁 |
| Files | 📄 |
| Settings | ⚙️ |
| Success | ✓ or 🌿 |
| Warning | ⚠️ |
| Info | 💡 |
| Search | 🔍 |
| Home | 🏠 |
| Star | ⭐ |

### Icon Colors

When using custom icons, prefer warm-toned colors from the primary palette. Avoid cool blues or purples in iconography.

---

## Spacing System

Use a consistent spacing scale based on 4px units:

| Token | Value | Usage |
|-------|-------|-------|
| `--space-1` | 4px | Minimal spacing |
| `--space-2` | 8px | Tight spacing |
| `--space-3` | 12px | Default spacing |
| `--space-4` | 16px | Standard spacing |
| `--space-5` | 24px | Comfortable spacing |
| `--space-6` | 32px | Section spacing |
| `--space-8` | 48px | Large spacing |
| `--space-10` | 64px | Hero/header spacing |

---

## Border Radius

```css
--radius-sm: 4px;   /* Small elements */
--radius-md: 8px;   /* Buttons, inputs */
--radius-lg: 12px;  /* Cards */
--radius-xl: 16px;  /* Large cards, modals */
--radius-full: 9999px;  /* Pills, avatars */
```

---

## Animation Guidelines

### Timing

- **Fast**: 150ms (micro-interactions)
- **Normal**: 200ms (buttons, hovers)
- **Slow**: 300ms (cards, modals)
- **Very Slow**: 500ms (page transitions)

### Easing

```css
--ease-default: ease;
--ease-in-out: cubic-bezier(0.4, 0, 0.2, 1);
--ease-spring: cubic-bezier(0.34, 1.56, 0.64, 1);
```

### Animation Principles

1. **Subtle over dramatic** - Animations should be barely noticeable
2. **Purposeful** - Every animation should have meaning
3. **Consistent** - Same elements animate the same way
4. **Interruptible** - Allow users to continue without waiting

---

## Responsive Design

### Breakpoints

```css
--breakpoint-sm: 640px;
--breakpoint-md: 768px;
--breakpoint-lg: 1024px;
--breakpoint-xl: 1280px;
--breakpoint-2xl: 1536px;
```

### Mobile-First Approach

Always design for mobile first, then enhance for larger screens:

```css
/* Mobile default */
.container {
    padding: 1rem;
}

/* Tablet and up */
@media (min-width: 768px) {
    .container {
        padding: 2rem;
    }
}

/* Desktop and up */
@media (min-width: 1024px) {
    .container {
        max-width: 1200px;
        margin: 0 auto;
    }
}
```

---

## Dark Mode Considerations

If implementing dark mode in the future, use warm dark tones instead of cool grays:

```css
@media (prefers-color-scheme: dark) {
    :root {
        --bg-primary: #2A2520;
        --bg-secondary: #352F2A;
        --text-primary: #F5EDE6;
        --text-secondary: #D4C9BE;
    }
}
```

---

## Accessibility Requirements

1. **Color Contrast**: Minimum 4.5:1 for normal text, 3:1 for large text
2. **Focus States**: Always visible, use `--color-primary` for focus rings
3. **Touch Targets**: Minimum 44x44px for interactive elements
4. **Font Size**: Never smaller than 14px for body text
5. **Motion**: Respect `prefers-reduced-motion` preference

```css
@media (prefers-reduced-motion: reduce) {
    * {
        animation-duration: 0.01ms !important;
        transition-duration: 0.01ms !important;
    }
}
```

---

## Examples

### ✅ Correct Usage

```html
<header style="background: linear-gradient(135deg, #E07B39 0%, #E8A87C 100%); color: white;">
    <h1>🏭 Ominous Industries</h1>
</header>
```

### ❌ Incorrect Usage

```html
<!-- DO NOT USE -->
<header style="background: linear-gradient(135deg, #6366f1 0%, #a855f7 100%); color: white;">
    <h1>🏭 Ominous Industries</h1>
</header>
```

---

## Checklist for Contributors

Before submitting visual changes, verify:

- [ ] All colors are from the approved palette
- [ ] No purple, violet, or dark backgrounds used
- [ ] Warm, orangey tones are consistent
- [ ] Text contrast meets accessibility standards
- [ ] Hover and focus states are implemented
- [ ] Animations are subtle and purposeful
- [ ] Design works on mobile devices

---

*Last updated: December 2024*
