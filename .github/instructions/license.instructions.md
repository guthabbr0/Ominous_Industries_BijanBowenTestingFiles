# 📜 License Guidelines

This document provides comprehensive guidance on licensing and intellectual property considerations for the Ominous Industries repository.

---

## Overview

All content in this repository is owned by **Bijan Bowen** and the Ominous Industries project. These guidelines help contributors understand how to handle licensing, attribution, and intellectual property matters.

---

## Repository Content Types

### 1. Static Web Content

Files in the `/static` directory are primarily:
- HTML demonstration files
- CSS stylesheets
- JavaScript code
- Associated assets

**Default License**: All Rights Reserved unless otherwise specified.

### 2. GitHub Actions Workflows

Files in `/.github/workflows/` are:
- Automation scripts
- CI/CD configurations
- Build and deployment processes

**License Consideration**: These may be adapted from open-source templates with proper attribution.

### 3. Documentation

Files like README.md and instruction files are:
- Project documentation
- Guidelines and standards
- Educational content

---

## Attribution Requirements

### When Using Third-Party Code

If you incorporate third-party code or resources, you MUST:

1. **Verify License Compatibility**
   - Check that the license allows the intended use
   - Verify commercial use permissions if applicable
   - Confirm modification rights

2. **Provide Proper Attribution**
   ```markdown
   <!-- Example attribution comment -->
   <!--
   Portions of this code adapted from [Project Name]
   Original author: [Author Name]
   License: [License Type]
   Source: [URL]
   -->
   ```

3. **Include License Files**
   - Copy the full license text when required
   - Place in appropriate location (usually `/licenses/` directory)

4. **Update NOTICE Files**
   - Maintain a NOTICE.md or ATTRIBUTIONS.md file
   - List all third-party components

### Attribution Template

```markdown
## Third-Party Attributions

### [Component Name]
- **Source**: [URL]
- **Author**: [Author Name]
- **License**: [License Type]
- **Modifications**: [Brief description of changes]
```

---

## Open Source License Compatibility

### Permissive Licenses (Generally Safe to Use)

| License | Commercial Use | Modification | Attribution Required |
|---------|---------------|--------------|---------------------|
| MIT | ✅ Yes | ✅ Yes | ✅ Yes |
| Apache 2.0 | ✅ Yes | ✅ Yes | ✅ Yes |
| BSD 2-Clause | ✅ Yes | ✅ Yes | ✅ Yes |
| BSD 3-Clause | ✅ Yes | ✅ Yes | ✅ Yes |
| ISC | ✅ Yes | ✅ Yes | ✅ Yes |
| Unlicense | ✅ Yes | ✅ Yes | ❌ No |

### Copyleft Licenses (Use with Caution)

| License | Commercial Use | Modification | Share-Alike |
|---------|---------------|--------------|-------------|
| GPL v2/v3 | ✅ Yes | ✅ Yes | ⚠️ Required |
| LGPL | ✅ Yes | ✅ Yes | ⚠️ Modified files |
| AGPL | ✅ Yes | ✅ Yes | ⚠️ Network use |
| MPL 2.0 | ✅ Yes | ✅ Yes | ⚠️ Modified files |

### Creative Commons for Assets

| License | Commercial | Modifications | Attribution |
|---------|------------|---------------|-------------|
| CC0 | ✅ Yes | ✅ Yes | ❌ No |
| CC BY | ✅ Yes | ✅ Yes | ✅ Yes |
| CC BY-SA | ✅ Yes | ✅ Yes | ✅ Yes + Share-Alike |
| CC BY-NC | ❌ No | ✅ Yes | ✅ Yes |
| CC BY-ND | ✅ Yes | ❌ No | ✅ Yes |

---

## Fonts and Typography

### Licensing Considerations

1. **System Fonts** - Always safe to use
   ```css
   font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
   ```

2. **Google Fonts** - Check individual font licenses (most are OFL)

3. **Custom Fonts** - Verify license allows web embedding

### Font License Types

- **OFL (SIL Open Font License)** - Free for web use with attribution
- **Apache 2.0** - Free with attribution
- **Commercial Fonts** - Require purchase/license

---

## Image and Media Assets

### Acceptable Sources

| Source | License Type | Attribution |
|--------|--------------|-------------|
| Unsplash | Unsplash License | Recommended |
| Pexels | Pexels License | Not required |
| Pixabay | Pixabay License | Not required |
| Your Own | Full rights | N/A |

### Image Attribution Template

```markdown
Photo by [Photographer Name](link-to-profile) on [Platform](link-to-platform)
```

### Prohibited Sources

- Random Google image search results
- Social media screenshots (without permission)
- Copyrighted promotional materials
- AI-generated images from services with restrictive terms

---

## Code Licensing Best Practices

### Including License Headers

For substantial code files, include a header comment:

```javascript
/**
 * Ominous Industries - [Component Name]
 * 
 * Copyright (c) [Year] Bijan Bowen
 * All rights reserved.
 *
 * [Additional license information if applicable]
 */
```

### Minimal Header (For short files)

```javascript
// Copyright (c) [Year] Bijan Bowen. All rights reserved.
```

---

## Emoji and Icons

### Safe to Use

- Standard Unicode emoji ✅
- System emoji fonts ✅
- Emoji from fonts like Twemoji (with attribution) ✅

### Requires Attribution

- Custom icon libraries (Font Awesome, Feather Icons)
- SVG icon sets
- Premium icon packs

### Icon Attribution Example

```html
<!-- Icons provided by Feather Icons - https://feathericons.com/ - MIT License -->
```

---

## API and Third-Party Services

### When Integrating External Services

Document in your code:

1. **Service Name and Purpose**
2. **Terms of Service URL**
3. **Any usage limitations**
4. **API key handling (never commit keys)**

### Example Documentation

```javascript
/**
 * Integration with [Service Name]
 * 
 * Terms of Service: [URL]
 * Rate Limits: [X] requests per [time period]
 * API Documentation: [URL]
 * 
 * Note: API key must be stored in environment variables,
 * never committed to repository.
 */
```

---

## YouTube Content Considerations

Since this repository hosts content related to YouTube videos by Bijan Bowen:

### Original Content

- Video demonstrations created for this channel are proprietary
- Screenshots from videos require permission for external use
- Thumbnails and branding are copyrighted

### Third-Party Content in Videos

- Product names and logos may appear for review purposes (fair use)
- Code shown in videos should be properly attributed
- AI service outputs follow their respective terms of service

---

## Contributor License Agreement

By contributing to this repository, contributors agree:

1. **Original Work**: Contributions are original or properly licensed
2. **License Grant**: Contributions are granted under the project's license
3. **No Patent Claims**: No patent infringement issues are introduced
4. **Attribution**: Proper attribution for third-party content is provided

---

## Handling License Violations

If you discover content that may violate licensing:

1. **Don't Panic** - Most issues can be resolved
2. **Document the Issue** - Note what content and what license
3. **Report Promptly** - Contact repository maintainers
4. **Don't Delete Evidence** - Let maintainers handle removal

### Reporting Template

```markdown
## License Concern Report

**File/Content**: [Path or description]
**Potential Issue**: [Description of concern]
**Original Source**: [If known]
**License Type**: [If known]
**Suggested Action**: [Remove/Attribute/Other]
```

---

## License File Location

If the project adds an explicit license file, it should be:

- Named `LICENSE` or `LICENSE.md`
- Located in the repository root
- Clear and unambiguous

---

## Questions?

For licensing questions or concerns:

1. Create an issue with the `licensing` label
2. Provide specific file paths and concerns
3. Include any relevant URLs or documentation

---

## Quick Reference Checklist

Before adding content, verify:

- [ ] You have rights to use the content
- [ ] License is compatible with project goals
- [ ] Attribution is provided where required
- [ ] No proprietary content without permission
- [ ] No API keys or secrets in code
- [ ] License files included if required

---

*Last updated: December 2024*
