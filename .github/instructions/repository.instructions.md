# 📂 Repository Structure Guidelines

This document provides comprehensive guidance on the organization, naming conventions, and structure of the Ominous Industries repository. Following these guidelines ensures consistency and maintainability.

---

## Directory Structure Overview

```
Ominous_Industries_BijanBowenTestingFiles/
├── .github/
│   ├── instructions/           # Copilot and contribution guidelines
│   │   └── *.instructions.md   # Instruction files
│   └── workflows/              # GitHub Actions workflows
│       └── static.yml          # Pages deployment workflow
├── static/                     # Static files for GitHub Pages
│   └── [Video Title]/          # Content folders per video
│       └── [files]             # HTML, CSS, JS, etc.
├── .gitignore                  # Git ignore rules
└── README.md                   # Project overview
```

---

## Directory Purposes

### `.github/` Directory

This directory contains GitHub-specific configurations:

| Subdirectory | Purpose |
|--------------|---------|
| `instructions/` | Copilot instructions and contribution guidelines |
| `workflows/` | GitHub Actions CI/CD workflows |
| `ISSUE_TEMPLATE/` | Issue templates (if added) |
| `PULL_REQUEST_TEMPLATE/` | PR templates (if added) |

### `static/` Directory

The main content directory containing all static assets:

- **Purpose**: Houses all files deployed to GitHub Pages
- **Auto-indexed**: The workflow automatically generates an index.html
- **Organization**: One subdirectory per video/project

---

## Folder Naming Conventions

### Video Content Folders

Folders in `/static/` should match YouTube video titles:

```
✅ Good Examples:
- GPT-5.1 Pro vs Gemini 3 Deep Think – Head-to-Head Testing!
- Gemini 3 Pro Deep Think FULL Test – Hands-On With Google's BEST Model!

❌ Avoid:
- video_1
- untitled_folder
- test
```

### General Naming Rules

| Rule | Good Example | Bad Example |
|------|--------------|-------------|
| Use descriptive names | `user-authentication/` | `auth/` |
| Keep names readable | `AI Model Comparison` | `ai_mdl_cmp` |
| Match video titles exactly | `GPT-5.1 Pro vs...` | `GPT5 comparison` |
| Avoid special characters | `Test Results 2024` | `Test&Results@2024` |

---

## File Naming Conventions

### HTML Files

```
✅ Good:
- index.html
- demo-interactive.html
- hypnotoad-transmission.html
- geminievo.html

❌ Avoid:
- Index.HTML (inconsistent case)
- my file.html (spaces in name)
- page1.html (non-descriptive)
```

### CSS Files

```
✅ Good:
- styles.css
- main.css
- components.css

❌ Avoid:
- style.css.bak
- styles (1).css
```

### JavaScript Files

```
✅ Good:
- app.js
- main.js
- utils.js
- file-manager.js

❌ Avoid:
- script.js.old
- myScript.JS
```

### Naming Pattern Guidelines

| File Type | Pattern | Example |
|-----------|---------|---------|
| HTML | `lowercase-kebab.html` | `demo-page.html` |
| CSS | `lowercase.css` | `styles.css` |
| JavaScript | `camelCase.js` or `kebab-case.js` | `fileManager.js` |
| Images | `descriptive-name.ext` | `logo-dark.png` |
| Markdown | `UPPERCASE.md` or `kebab-case.md` | `README.md` |

---

## File Organization Within Folders

### Recommended Structure Per Video Folder

```
static/[Video Title]/
├── index.html          # Main entry point
├── styles.css          # Styles (if separate)
├── script.js           # JavaScript (if separate)
├── assets/             # Images, fonts, media
│   ├── images/
│   └── fonts/
└── data/               # JSON, configuration files
```

### Single-File Approach

For simple demos, a single HTML file with embedded CSS/JS is acceptable:

```html
<!DOCTYPE html>
<html>
<head>
    <style>/* embedded CSS */</style>
</head>
<body>
    <script>/* embedded JS */</script>
</body>
</html>
```

---

## README Files

### Root README.md

The root README should contain:

1. **Project Title and Description**
2. **Links** (website, YouTube, etc.)
3. **Quick Start** (if applicable)
4. **License Information**

### Current Format:

```markdown
# Ominous_Industries

https://www.bijanbowen.com/ - https://www.youtube.com/@Bijanbowen
```

### Optional Sections to Add:

- Overview of hosted content
- Links to live demos
- Contact information

---

## Git Conventions

### .gitignore Rules

The current `.gitignore` includes:

```gitignore
# Object file
*.o

# Ada Library Information
*.ali
```

### Additional Recommended Ignores

```gitignore
# Dependencies
node_modules/

# Build outputs
dist/
build/
*.min.js
*.min.css

# Editor files
.vscode/
.idea/
*.swp
*.swo

# OS files
.DS_Store
Thumbs.db

# Logs
*.log
npm-debug.log*

# Environment
.env
.env.local

# Temporary files
*.tmp
*.temp
```

---

## Branch Naming Conventions

| Type | Pattern | Example |
|------|---------|---------|
| Feature | `feature/description` | `feature/add-new-demo` |
| Bugfix | `fix/description` | `fix/index-display` |
| Documentation | `docs/description` | `docs/update-readme` |
| Copilot | `copilot/description` | `copilot/fix-xxx` |

---

## Adding New Content

### Step-by-Step Process

1. **Create a new folder** in `/static/` matching the video title
   ```
   static/New Video Title - Demo/
   ```

2. **Add your files** following naming conventions
   ```
   static/New Video Title - Demo/
   ├── index.html
   └── demo.html
   ```

3. **Test locally** if possible
   - Open HTML files in a browser
   - Verify all links work

4. **Commit with descriptive message**
   ```
   Add demo files for "New Video Title" video
   ```

5. **Push to main branch** (or create PR)

6. **Automatic indexing**
   - The workflow will regenerate the index on push
   - New folder will appear in the index automatically

---

## Content Guidelines

### HTML Structure

All HTML files should include:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page Title - Ominous Industries</title>
    <!-- Follow style.instructions.md for colors/styling -->
</head>
<body>
    <!-- Content -->
</body>
</html>
```

### Required Meta Tags

```html
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

### Recommended Meta Tags

```html
<meta name="description" content="Description of the page">
<meta name="author" content="Bijan Bowen">
```

---

## Security Considerations

### Never Commit

- API keys or secrets
- Personal access tokens
- Database credentials
- Private keys
- User data or passwords

### Safe Practices

- Use environment variables for secrets
- Review code before committing
- Check for accidentally committed credentials

### If Secrets Are Committed

1. **Immediately revoke** the exposed credential
2. **Generate new credentials**
3. **Contact repository maintainers**
4. Use `git filter-branch` or BFG Repo-Cleaner (advanced)

---

## Workflow Integration

The repository uses a GitHub Pages deployment workflow:

### How It Works

1. **Push to main** triggers the workflow
2. **Index generation** scans `/static/` folders
3. **HTML index created** with folder/file listings
4. **Deployed to Pages** automatically

### What Gets Deployed

- All files in the repository root
- All files in `/static/` and subfolders
- Auto-generated `static/index.html`

---

## Maintenance Tasks

### Regular Maintenance

| Task | Frequency | Description |
|------|-----------|-------------|
| Review folder structure | Monthly | Ensure consistency |
| Update README | As needed | Keep links current |
| Clean unused files | Quarterly | Remove obsolete content |
| Check broken links | Monthly | Verify demo links work |

### Housekeeping Checklist

- [ ] All folders follow naming conventions
- [ ] No orphaned or test files
- [ ] README is accurate and up-to-date
- [ ] .gitignore covers common patterns
- [ ] No sensitive data in repository

---

## Quick Reference

### Do's ✅

- Use descriptive folder and file names
- Follow naming conventions consistently
- Keep related files together
- Add proper documentation
- Test changes before pushing

### Don'ts ❌

- Create deeply nested folder structures
- Use inconsistent naming styles
- Leave test/temporary files
- Commit large binary files
- Mix unrelated content in folders

---

*Last updated: December 2024*
