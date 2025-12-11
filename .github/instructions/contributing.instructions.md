# 🤝 Contributing Guidelines

Welcome to the Ominous Industries repository! This document provides comprehensive guidelines for contributing to the project. Whether you're adding new demos, fixing bugs, or improving documentation, we appreciate your contribution.

---

## Overview

This repository hosts static content for Bijan Bowen's YouTube channel, including interactive demos, code examples, and supplementary materials for AI-focused videos.

---

## Getting Started

### Prerequisites

- Git installed on your machine
- Text editor (VS Code, Sublime Text, etc.)
- Web browser for testing
- Basic knowledge of HTML, CSS, and JavaScript

### Clone the Repository

```bash
git clone https://github.com/guthabbr0/Ominous_Industries_BijanBowenTestingFiles.git
cd Ominous_Industries_BijanBowenTestingFiles
```

---

## Contribution Types

### 1. Adding New Demo Content

Add files for new YouTube videos in the `/static/` directory.

**Steps**:
1. Create a folder matching the video title
2. Add your HTML, CSS, and JS files
3. Test locally in a browser
4. Submit a pull request

### 2. Fixing Bugs

Found something not working? Fix it!

**Steps**:
1. Create an issue describing the bug
2. Fork and create a fix branch
3. Implement the fix
4. Test thoroughly
5. Submit a pull request

### 3. Improving Documentation

Help improve these instruction files or the README.

**Steps**:
1. Identify areas needing clarification
2. Write clear, helpful documentation
3. Submit a pull request

### 4. Style Updates

Update styling to align with the style guide (calm, orangey tones).

**Steps**:
1. Review `style.instructions.md`
2. Implement consistent styling
3. Test on multiple devices
4. Submit a pull request

---

## Workflow

### Branch Strategy

```
main                    # Production branch
  └── feature/name      # New features
  └── fix/name          # Bug fixes
  └── docs/name         # Documentation updates
```

### Creating a Branch

```bash
# Create and switch to a new branch
git checkout -b feature/your-feature-name

# Work on your changes...

# Commit your changes
git add .
git commit -m "Add: description of changes"

# Push to your fork
git push origin feature/your-feature-name
```

---

## Commit Guidelines

### Commit Message Format

```
Type: Brief description

Optional longer description explaining the what and why.
```

### Types

| Type | Usage |
|------|-------|
| `Add` | New feature or content |
| `Fix` | Bug fix |
| `Update` | Modification to existing content |
| `Remove` | Deletion of content |
| `Docs` | Documentation changes |
| `Style` | Formatting, styling (no code change) |
| `Refactor` | Code restructuring |

### Examples

```bash
# Good
git commit -m "Add: demo files for GPT-5 comparison video"
git commit -m "Fix: broken link in index navigation"
git commit -m "Style: update header gradient to orangey tones"

# Bad
git commit -m "updates"
git commit -m "fixed stuff"
git commit -m "wip"
```

---

## Pull Request Process

### Before Submitting

1. **Test your changes** - Open HTML files in multiple browsers
2. **Check styling** - Follow the style guide (no purples, warm tones)
3. **Validate HTML** - No broken tags or syntax errors
4. **Review guidelines** - Ensure you followed all relevant instruction files

### Creating a Pull Request

1. Push your branch to GitHub
2. Navigate to the repository
3. Click "Compare & pull request"
4. Fill out the PR template:

```markdown
## Description
What does this PR add or fix?

## Type of Change
- [ ] New demo content
- [ ] Bug fix
- [ ] Style update
- [ ] Documentation
- [ ] Other (describe)

## Testing
How did you test these changes?

## Checklist
- [ ] My code follows the style guide
- [ ] I have tested locally
- [ ] I have updated documentation if needed
- [ ] No broken links or errors
```

### After Submitting

- Respond to review comments
- Make requested changes
- Push additional commits as needed
- Wait for approval and merge

---

## Code Standards

### HTML

```html
<!-- ✅ Good -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page Title - Ominous Industries</title>
</head>
<body>
    <!-- Content -->
</body>
</html>
```

### CSS

Follow the color palette from `style.instructions.md`:

```css
/* ✅ Good - Warm, orangey tones */
:root {
    --primary: #E07B39;
    --bg: #FDF8F3;
}

/* ❌ Bad - Purple/dark tones */
:root {
    --primary: #6366f1;
    --bg: #0f172a;
}
```

### JavaScript

```javascript
// ✅ Good - Use escaping functions
element.textContent = userInput;

// ❌ Bad - XSS vulnerability
element.innerHTML = userInput;
```

---

## Testing Guidelines

### Local Testing

1. **Open in Browser**
   - Open HTML files directly
   - Check console for errors (F12 → Console)

2. **Test Responsiveness**
   - Resize browser window
   - Use device emulation in dev tools

3. **Check Links**
   - Verify all links work
   - Check navigation

4. **Validate Colors**
   - Ensure warm, orangey palette
   - No purples or dark backgrounds

### Cross-Browser Testing

Test in at least:
- Chrome
- Firefox
- Safari (if available)
- Edge

### Accessibility Testing

- Check color contrast
- Verify keyboard navigation
- Test with screen reader (if possible)

---

## File Naming Conventions

| Type | Convention | Example |
|------|------------|---------|
| HTML | lowercase-kebab | `demo-page.html` |
| CSS | lowercase | `styles.css` |
| JS | camelCase or kebab | `app.js` |
| Folders | Match video titles | `GPT-5.1 Pro vs...` |

---

## What We Look For

### ✅ Good Contributions

- Clean, well-formatted code
- Follows style guide (orangey, not purple)
- Descriptive commit messages
- Tested before submitting
- Documentation updated if needed

### ❌ Issues to Avoid

- Broken HTML/CSS/JS
- Purple or dark color schemes
- Untested code
- Large binary files
- Missing meta tags

---

## Style Guide Quick Reference

### Colors to Use

| Color | Hex | Use |
|-------|-----|-----|
| Warm Orange | `#E07B39` | Primary |
| Soft Coral | `#E8A87C` | Secondary |
| Warm White | `#FDF8F3` | Background |
| Warm Charcoal | `#3D3936` | Text |

### Colors to Avoid

❌ `#6366f1` (Purple)
❌ `#0f172a` (Dark Slate)
❌ Any purple/violet shades
❌ Dark backgrounds

---

## Getting Help

### Questions?

- Create an issue with the `question` label
- Check existing issues and documentation first
- Be specific about what you need help with

### Stuck on Something?

1. Check the instruction files in `.github/instructions/`
2. Review existing code for examples
3. Create an issue describing your challenge

---

## Recognition

We appreciate all contributions! Contributors may be:

- Mentioned in release notes
- Listed in acknowledgments
- Thanked in video descriptions

---

## Code of Conduct

### Be Respectful

- Treat everyone with respect
- Be patient with newcomers
- Give constructive feedback

### Be Collaborative

- Help others when you can
- Share knowledge generously
- Welcome different perspectives

### Be Professional

- Keep discussions focused
- Avoid personal attacks
- Accept decisions gracefully

---

## Quick Checklist

Before contributing:

- [ ] I've read the style guide
- [ ] I've read the security guidelines
- [ ] I've tested my changes locally
- [ ] My code uses warm, orangey colors (no purple/dark)
- [ ] I've written a clear commit message
- [ ] I'm ready to respond to feedback

---

*Thank you for contributing to Ominous Industries! 🧡*

*Last updated: December 2024*
