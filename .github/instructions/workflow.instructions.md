# ⚙️ Workflow and CI/CD Guidelines

This document provides comprehensive guidance on GitHub Actions workflows, continuous integration, and deployment practices for the Ominous Industries repository.

---

## Overview

The repository uses GitHub Actions to automate deployment of static content to GitHub Pages. This ensures content is always up-to-date and accessible.

---

## Current Workflow

### `static.yml` - Deploy Static Content to Pages

**Location**: `.github/workflows/static.yml`

**Purpose**: Automatically builds and deploys all static content to GitHub Pages whenever changes are pushed to the main branch.

**Triggers**:
- Push to `main` branch
- Manual workflow dispatch

---

## Workflow Structure Explained

### Permissions Block

```yaml
permissions:
  contents: read      # Read repository content
  pages: write        # Write to GitHub Pages
  id-token: write     # Required for Pages deployment
```

### Concurrency Settings

```yaml
concurrency:
  group: "pages"
  cancel-in-progress: false  # Don't cancel ongoing deployments
```

This prevents multiple simultaneous deployments while allowing each to complete.

---

## Key Workflow Steps

### 1. Checkout Code

```yaml
- name: Checkout
  uses: actions/checkout@v4
```

Downloads the repository code to the runner.

### 2. Generate Index HTML

The workflow dynamically generates an `index.html` in the `/static/` directory:

- Scans all subdirectories in `/static/`
- Creates a searchable, sortable file index
- Uses the style guide color palette (see style.instructions.md)
- Employs XSS-safe JSON embedding techniques

### 3. Configure Pages

```yaml
- name: Setup Pages
  uses: actions/configure-pages@v5
```

Prepares GitHub Pages for deployment.

### 4. Upload Artifact

```yaml
- name: Upload artifact
  uses: actions/upload-pages-artifact@v3
  with:
    path: '.'
```

Packages the entire repository for deployment.

### 5. Deploy to Pages

```yaml
- name: Deploy to GitHub Pages
  id: deployment
  uses: actions/deploy-pages@v4
```

Publishes the content to GitHub Pages.

---

## Index Page Generation Details

### Features

| Feature | Description |
|---------|-------------|
| **Folder Cards** | Collapsible cards for each folder |
| **File Listings** | Files shown with icons and extensions |
| **Search** | Real-time filtering by name |
| **Sort** | Alphabetical sorting (A-Z / Z-A) |
| **Responsive** | Works on mobile and desktop |

### Security Features

1. **XSS-Safe JSON Embedding**
   ```html
   <script id="file-data" type="application/json">DATA</script>
   <script>
       const data = JSON.parse(document.getElementById('file-data').textContent);
   </script>
   ```

2. **HTML Escaping** for folder/file names

3. **URL Encoding** for file paths

### Color Theme

The index page should use the warm, orangey color palette defined in `style.instructions.md`:

```css
:root {
    --primary-color: #E07B39;      /* Warm Orange */
    --bg-color: #FDF8F3;           /* Warm White */
    --card-bg: #FBF4ED;            /* Cream */
    --text-color: #3D3936;         /* Warm Charcoal */
    --accent-gradient: linear-gradient(135deg, #E07B39 0%, #E8A87C 100%);
}
```

---

## Modifying the Workflow

### When to Modify

- Adding new build steps
- Changing deployment configuration
- Adding notifications or integrations
- Updating action versions

### Modification Guidelines

1. **Test in a branch first** - Don't modify main directly
2. **Use specific version tags** - e.g., `@v4` instead of `@latest`
3. **Add comments** - Document non-obvious steps
4. **Keep it minimal** - Only add what's necessary

### Action Version Maintenance

Current versions used:

| Action | Version | Purpose |
|--------|---------|---------|
| `actions/checkout` | v4 | Repository checkout |
| `actions/configure-pages` | v5 | Pages configuration |
| `actions/upload-pages-artifact` | v3 | Artifact upload |
| `actions/deploy-pages` | v4 | Pages deployment |

**Maintenance**: Review GitHub's release notes periodically for security updates.

---

## Adding New Workflows

### File Naming Convention

```
.github/workflows/[purpose].yml
```

Examples:
- `static.yml` - Static deployment
- `lint.yml` - Code linting
- `test.yml` - Testing
- `notify.yml` - Notifications

### Workflow Template

```yaml
name: Workflow Name

on:
  push:
    branches: ["main"]
  pull_request:
    branches: ["main"]
  workflow_dispatch:

permissions:
  # Define minimal required permissions
  contents: read

jobs:
  job-name:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v4
      
      # Add your steps here
```

---

## Best Practices

### Security

1. **Minimal Permissions** - Only request what's needed
2. **Pin Action Versions** - Use specific version tags
3. **No Secrets in Logs** - Use GitHub Secrets
4. **Review Third-Party Actions** - Check before adding

### Performance

1. **Use Caching** - Cache dependencies when possible
2. **Parallel Jobs** - Run independent jobs concurrently
3. **Skip Unnecessary Runs** - Use path filters

### Path Filtering Example

```yaml
on:
  push:
    paths:
      - 'static/**'
      - '.github/workflows/static.yml'
```

This runs the workflow only when relevant files change.

---

## Troubleshooting

### Common Issues

#### Deployment Fails

**Symptoms**: Workflow fails at deploy step

**Solutions**:
1. Check Pages is enabled in repository settings
2. Verify permissions block is correct
3. Check artifact upload succeeded

#### Index Not Updating

**Symptoms**: New folders don't appear in index

**Solutions**:
1. Verify folder is in `/static/` directory
2. Check folder contains at least one file
3. Ensure folder name doesn't start with `.`

#### Python Script Fails

**Symptoms**: Generate Index HTML step fails

**Solutions**:
1. Check for syntax errors in Python
2. Verify file permissions
3. Check for special characters in folder names

### Debugging Steps

1. **Check workflow logs** - GitHub Actions tab
2. **Add debug output** - `echo "Debug: $variable"`
3. **Run locally** - Test scripts on your machine
4. **Check event payload** - Verify trigger conditions

---

## Environment Variables

### Available Variables

| Variable | Description |
|----------|-------------|
| `GITHUB_REPOSITORY` | `owner/repo` |
| `GITHUB_REF` | Branch or tag ref |
| `GITHUB_SHA` | Commit SHA |
| `GITHUB_ACTOR` | User triggering workflow |
| `GITHUB_RUN_ID` | Unique run identifier |

### Using Secrets

```yaml
- name: Use secret
  env:
    API_KEY: ${{ secrets.API_KEY }}
  run: echo "Using secret..."
```

Never log secret values or expose them in outputs.

---

## Manual Workflow Dispatch

The workflow supports manual triggering:

1. Go to **Actions** tab
2. Select **Deploy static content to Pages**
3. Click **Run workflow**
4. Select branch (usually `main`)
5. Click **Run workflow** button

This is useful for:
- Force redeployment
- Testing after Pages configuration changes
- Debugging issues

---

## Monitoring and Notifications

### Checking Workflow Status

1. **GitHub Actions tab** - See all runs
2. **Commit status** - Check marks on commits
3. **Deployments** - View in repository settings

### Optional: Add Notifications

```yaml
- name: Notify on failure
  if: failure()
  uses: actions/github-script@v7
  with:
    script: |
      console.log('Deployment failed!');
      // Add notification logic
```

---

## Future Improvements

Consider adding these workflows:

| Workflow | Purpose |
|----------|---------|
| **Linting** | HTML/CSS/JS validation |
| **Link Checking** | Verify all links work |
| **Security Scan** | Check for vulnerabilities |
| **Preview** | Preview PRs before merge |
| **Notifications** | Slack/Discord alerts |

---

## Checklist for Workflow Changes

Before modifying workflows:

- [ ] Tested changes in a feature branch
- [ ] Action versions are pinned
- [ ] Permissions are minimal and correct
- [ ] No secrets exposed in logs
- [ ] Workflow has descriptive name
- [ ] Steps have clear names
- [ ] Comments explain complex logic

---

*Last updated: December 2024*
