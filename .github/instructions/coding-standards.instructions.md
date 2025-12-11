# 💻 Coding Standards Guidelines

This document defines the coding standards and best practices for all code within the Ominous Industries repository. Following these standards ensures consistency, maintainability, and quality across all contributions.

---

## Overview

The repository primarily contains:
- **HTML** - Static web pages and demos
- **CSS** - Styles and layouts
- **JavaScript** - Interactive functionality
- **Python** - Build scripts in workflows
- **YAML** - GitHub Actions workflows

Each language has specific conventions outlined below.

---

## HTML Standards

### Document Structure

Every HTML file should include:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page Title - Ominous Industries</title>
    <!-- Styles here -->
</head>
<body>
    <!-- Content here -->
    <!-- Scripts at end of body -->
</body>
</html>
```

### Required Meta Tags

```html
<!-- Character encoding -->
<meta charset="UTF-8">

<!-- Responsive viewport -->
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

### Recommended Meta Tags

```html
<!-- Page description -->
<meta name="description" content="Brief description of the page">

<!-- Author -->
<meta name="author" content="Bijan Bowen">

<!-- Theme color (for mobile browsers) -->
<meta name="theme-color" content="#E07B39">
```

### Indentation and Formatting

```html
<!-- ✅ Consistent 4-space indentation -->
<div class="container">
    <header>
        <h1>Title</h1>
    </header>
    <main>
        <p>Content</p>
    </main>
</div>

<!-- ❌ Inconsistent/no indentation -->
<div class="container">
<header>
<h1>Title</h1>
</header>
</div>
```

### Attribute Ordering

Order attributes consistently:

1. `id`
2. `class`
3. `data-*`
4. `src`, `href`, `action`
5. `type`, `name`, `value`
6. `aria-*`, `role`
7. Event handlers (`onclick`, etc.)

```html
<input 
    id="searchInput"
    class="search-box"
    data-field="search"
    type="text"
    name="query"
    placeholder="Search..."
    aria-label="Search files"
>
```

### Self-Closing Tags

Use self-closing format consistently:

```html
<!-- ✅ Preferred (no trailing slash in HTML5) -->
<meta charset="UTF-8">
<link rel="stylesheet" href="styles.css">
<img src="image.png" alt="Description">
<input type="text">
<br>
<hr>

<!-- ❌ Avoid XHTML-style closing -->
<br />
<input type="text" />
```

---

## CSS Standards

### File Organization

```css
/* ================================
   1. CSS Variables
   ================================ */
:root {
    --color-primary: #E07B39;
    --bg-primary: #FDF8F3;
}

/* ================================
   2. Reset / Base Styles
   ================================ */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

/* ================================
   3. Typography
   ================================ */
body {
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
}

/* ================================
   4. Layout
   ================================ */
.container {
    max-width: 1200px;
    margin: 0 auto;
}

/* ================================
   5. Components
   ================================ */
.button { }
.card { }

/* ================================
   6. Utilities
   ================================ */
.hidden { display: none; }

/* ================================
   7. Responsive
   ================================ */
@media (max-width: 768px) { }
```

### Naming Conventions

Use lowercase kebab-case for class names:

```css
/* ✅ Good */
.folder-card { }
.file-list { }
.search-box { }
.btn-primary { }

/* ❌ Avoid */
.folderCard { }      /* camelCase */
.folder_card { }     /* snake_case */
.FolderCard { }      /* PascalCase */
.FOLDER-CARD { }     /* UPPERCASE */
```

### Property Ordering

Group properties logically:

```css
.element {
    /* 1. Positioning */
    position: relative;
    top: 0;
    left: 0;
    z-index: 1;
    
    /* 2. Display & Box Model */
    display: flex;
    width: 100%;
    padding: 1rem;
    margin: 0;
    border: 1px solid var(--border-color);
    border-radius: 8px;
    
    /* 3. Color & Background */
    color: var(--text-color);
    background: var(--bg-card);
    box-shadow: var(--shadow-sm);
    
    /* 4. Typography */
    font-size: 1rem;
    font-weight: 500;
    line-height: 1.5;
    text-align: left;
    
    /* 5. Animation */
    transition: all 0.2s ease;
    
    /* 6. Other */
    cursor: pointer;
}
```

### Use CSS Variables

```css
/* ✅ Use variables for consistency */
.button {
    background: var(--color-primary);
    color: white;
    border-radius: var(--radius-md);
}

/* ❌ Avoid hardcoded values */
.button {
    background: #E07B39;
    border-radius: 8px;
}
```

### Responsive Design

Use mobile-first approach:

```css
/* Base styles (mobile) */
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

### Avoid Deep Nesting

```css
/* ✅ Shallow nesting */
.folder-card { }
.folder-card.active { }
.folder-header { }
.folder-title { }

/* ❌ Avoid deep specificity */
.folder-list .folder-card .folder-header .folder-title span { }
```

---

## JavaScript Standards

### General Principles

1. **Use modern ES6+ syntax**
2. **Prefer `const` over `let`, avoid `var`**
3. **Use meaningful variable names**
4. **Keep functions small and focused**

### Variable Declarations

```javascript
// ✅ Good
const MAX_ITEMS = 100;
let currentPage = 1;
const items = [];

// ❌ Avoid
var x = 100;
var arr = [];
```

### Function Declarations

```javascript
// ✅ Use arrow functions for callbacks
const files = folders.filter(folder => folder.active);
const names = items.map(item => item.name);

// ✅ Use named functions for clarity
function renderFolders(data, sortOrder = 'asc') {
    // Implementation
}

// ❌ Avoid anonymous functions without context
folders.forEach(function(f) { /* ... */ });
```

### String Handling

```javascript
// ✅ Use template literals
const message = `Found ${count} files in ${folder}`;
const html = `<div class="item">${escapeHtml(name)}</div>`;

// ❌ Avoid string concatenation
const message = 'Found ' + count + ' files in ' + folder;
```

### DOM Manipulation

```javascript
// ✅ Safe - Use textContent for plain text
element.textContent = userData;

// ✅ Safe - Create elements programmatically
const div = document.createElement('div');
div.textContent = content;
parent.appendChild(div);

// ❌ Dangerous - Never inject untrusted HTML
element.innerHTML = userData;  // XSS VULNERABILITY!
```

### Event Handling

```javascript
// ✅ Use addEventListener
document.getElementById('searchInput').addEventListener('input', (e) => {
    filterContent(e.target.value.toLowerCase());
});

// ✅ Use delegation for dynamic content
document.querySelector('.container').addEventListener('click', (e) => {
    if (e.target.matches('.folder-header')) {
        e.target.parentElement.classList.toggle('collapsed');
    }
});
```

### Error Handling

```javascript
// ✅ Handle errors gracefully
try {
    const data = JSON.parse(jsonString);
    processData(data);
} catch (error) {
    console.error('Failed to parse data:', error);
    showUserMessage('Unable to load data. Please refresh.');
}
```

### Comments

```javascript
// ✅ Explain WHY, not WHAT
// Escape </ to prevent breaking out of script tag
const safeJson = json.replace('</', '<\\/');

// ❌ Unnecessary comments
// Loop through array
array.forEach(item => { /* ... */ });
```

---

## Python Standards (Workflow Scripts)

### General Style

Follow PEP 8 guidelines:

```python
# ✅ Good
import os
import json

def process_files(directory):
    """Process files in the given directory."""
    data = {}
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        if os.path.isdir(item_path):
            data[item] = get_file_list(item_path)
    return data


def get_file_list(path):
    """Get list of files in a directory."""
    return sorted([
        f for f in os.listdir(path)
        if os.path.isfile(os.path.join(path, f))
    ])
```

### Naming Conventions

| Type | Convention | Example |
|------|------------|---------|
| Variables | snake_case | `file_path` |
| Functions | snake_case | `process_files()` |
| Constants | UPPER_SNAKE | `MAX_SIZE` |
| Classes | PascalCase | `FileProcessor` |

### String Formatting

```python
# ✅ Use f-strings (Python 3.6+)
message = f"Found {count} files in {folder}"

# ❌ Avoid older styles
message = "Found {} files in {}".format(count, folder)
message = "Found %d files in %s" % (count, folder)
```

---

## YAML Standards (Workflows)

### Structure

```yaml
# ✅ Consistent formatting
name: Workflow Name

on:
  push:
    branches: ["main"]
  workflow_dispatch:

permissions:
  contents: read

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Descriptive Step Name
        uses: actions/checkout@v4
```

### Key Conventions

- Use 2-space indentation
- Quote strings when they contain special characters
- Use arrays for lists: `["main", "develop"]`
- Pin action versions: `@v4` not `@main`

---

## Code Quality Guidelines

### Keep It Simple

```javascript
// ✅ Simple and readable
const activeItems = items.filter(item => item.isActive);

// ❌ Overly complex
const activeItems = items.reduce((acc, item) => {
    if (item.isActive) {
        acc.push(item);
    }
    return acc;
}, []);
```

### DRY (Don't Repeat Yourself)

```javascript
// ✅ Reusable function
function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}

// Use it everywhere
const safeName = escapeHtml(folderName);
const safeFile = escapeHtml(fileName);
```

### Single Responsibility

```javascript
// ✅ Each function does one thing
function getFileIcon(filename) {
    const ext = getFileExtension(filename);
    return ICON_MAP[ext] || '📄';
}

function getFileExtension(filename) {
    const parts = filename.split('.');
    return parts.length > 1 ? parts.pop().toLowerCase() : '';
}
```

---

## Performance Considerations

### Minimize DOM Operations

```javascript
// ✅ Build HTML in memory, insert once
const html = items.map(item => `<li>${escapeHtml(item)}</li>`).join('');
container.innerHTML = html;

// ❌ Avoid multiple DOM insertions
items.forEach(item => {
    container.innerHTML += `<li>${escapeHtml(item)}</li>`;
});
```

### Use Event Delegation

```javascript
// ✅ Single listener for multiple elements
document.querySelector('.list').addEventListener('click', (e) => {
    if (e.target.matches('.item')) {
        handleItemClick(e.target);
    }
});

// ❌ Listener per element
document.querySelectorAll('.item').forEach(item => {
    item.addEventListener('click', handleItemClick);
});
```

---

## Accessibility Standards

### Semantic HTML

```html
<!-- ✅ Use semantic elements -->
<header>
    <nav>
        <ul>
            <li><a href="#">Home</a></li>
        </ul>
    </nav>
</header>
<main>
    <article>
        <h1>Title</h1>
        <p>Content</p>
    </article>
</main>
<footer>
    <p>Footer content</p>
</footer>

<!-- ❌ Avoid div soup -->
<div class="header">
    <div class="nav">
        <div class="list">
            <div class="item"><a href="#">Home</a></div>
        </div>
    </div>
</div>
```

### ARIA Labels

```html
<!-- When semantic HTML isn't enough -->
<button aria-label="Close dialog">×</button>
<div role="search">
    <input type="text" aria-label="Search files">
</div>
```

### Color Contrast

Ensure 4.5:1 contrast ratio for normal text:

```css
/* ✅ Good contrast */
color: #3D3936;        /* Dark brown text */
background: #FDF8F3;   /* Light cream background */

/* ❌ Poor contrast */
color: #E8A87C;        /* Light coral text */
background: #FDF8F3;   /* Similar light background */
```

---

## Testing Checklist

Before committing code:

- [ ] HTML is valid (use W3C validator)
- [ ] No JavaScript errors in console
- [ ] Links work correctly
- [ ] Responsive on mobile devices
- [ ] Colors match style guide (orangey, not purple)
- [ ] No accessibility issues
- [ ] No XSS vulnerabilities
- [ ] Code is properly formatted

---

## Quick Reference

### Indentation

| Language | Spaces |
|----------|--------|
| HTML | 4 |
| CSS | 4 |
| JavaScript | 4 |
| Python | 4 |
| YAML | 2 |

### Naming Conventions Summary

| Context | Convention | Example |
|---------|------------|---------|
| CSS classes | kebab-case | `.folder-card` |
| JS variables | camelCase | `folderList` |
| JS constants | UPPER_SNAKE | `MAX_ITEMS` |
| Python vars | snake_case | `file_path` |
| File names | kebab-case | `file-manager.js` |

---

*Last updated: December 2024*