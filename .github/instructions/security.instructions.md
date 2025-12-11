# 🔒 Security Guidelines

This document provides comprehensive security guidelines for the Ominous Industries repository. Following these practices helps protect the project, contributors, and end users.

---

## Overview

Security is everyone's responsibility. Even for a static content repository, there are important security considerations to ensure safe and trustworthy content delivery.

---

## Golden Rules

1. **Never commit secrets** - No API keys, passwords, or tokens in code
2. **Validate all inputs** - Never trust user-provided data
3. **Escape all outputs** - Prevent XSS and injection attacks
4. **Keep dependencies updated** - Regularly check for security patches
5. **Follow least privilege** - Only request necessary permissions

---

## Credential and Secret Management

### What NOT to Commit

| Type | Examples | Risk |
|------|----------|------|
| **API Keys** | `OPENAI_API_KEY=sk-...` | Service abuse, billing |
| **Passwords** | `password123` | Account compromise |
| **Tokens** | `ghp_xxxx` | Repository access |
| **Private Keys** | `.pem`, `.key` files | Impersonation |
| **Database URLs** | `mongodb://user:pass@...` | Data breach |
| **Service Configs** | `.env` files | Multiple vectors |

### Safe Practices

```bash
# Use environment variables
export API_KEY="your-key-here"

# Reference in code (don't hardcode)
const key = process.env.API_KEY;
```

### GitHub Secrets

For workflows, use GitHub Secrets:

```yaml
env:
  API_KEY: ${{ secrets.API_KEY }}
```

### If You Accidentally Commit a Secret

1. **Immediately revoke** the exposed credential
2. **Generate new credentials**
3. **Remove from history** (requires advanced git operations)
4. **Report the incident** to repository maintainers

---

## Cross-Site Scripting (XSS) Prevention

### Understanding XSS

XSS attacks inject malicious scripts into web pages. This is critical for HTML content in `/static/`.

### Dangerous Patterns

```javascript
// ❌ NEVER do this
document.innerHTML = userInput;
element.innerHTML = folder + "/" + file;

// ❌ NEVER do this
var data = ${JSON.stringify(userInput)};  // In template
```

### Safe Patterns

```javascript
// ✅ Use textContent for plain text
element.textContent = userInput;

// ✅ Use proper escaping function
function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}

// ✅ Use type="application/json" for JSON data
<script id="data" type="application/json">DATA_HERE</script>
<script>
    const data = JSON.parse(document.getElementById('data').textContent);
</script>
```

### Current Implementation

The workflow uses XSS-safe JSON embedding:

```javascript
// Safe pattern from static.yml
const fileData = JSON.parse(document.getElementById('file-data').textContent);

// HTML escaping for display
function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}
```

---

## URL and Path Safety

### URL Encoding

Always encode URL components:

```javascript
// ✅ Safe
const url = `${encodeURIComponent(folder)}/${encodeURIComponent(file)}`;

// ❌ Unsafe
const url = folder + "/" + file;
```

### Path Traversal Prevention

Prevent `../` path traversal attacks:

```python
# ✅ Validate paths are within expected directory
import os

def safe_path(base_dir, user_path):
    # Resolve to absolute path
    full_path = os.path.abspath(os.path.join(base_dir, user_path))
    # Verify it's still within base directory
    if not full_path.startswith(os.path.abspath(base_dir)):
        raise ValueError("Invalid path")
    return full_path
```

---

## Content Security

### Safe HTML Practices

```html
<!-- ✅ Use Content Security Policy -->
<meta http-equiv="Content-Security-Policy" 
      content="default-src 'self'; script-src 'self' 'unsafe-inline'; style-src 'self' 'unsafe-inline';">

<!-- ✅ Specify charset -->
<meta charset="UTF-8">

<!-- ✅ Use referrer policy -->
<meta name="referrer" content="strict-origin-when-cross-origin">
```

### External Links

```html
<!-- ✅ Use noopener for external links -->
<a href="https://external.com" target="_blank" rel="noopener noreferrer">Link</a>
```

This prevents:
- `window.opener` exploitation
- Referrer information leakage

---

## GitHub Actions Security

### Secure Workflow Practices

```yaml
# ✅ Pin action versions
- uses: actions/checkout@v4

# ❌ Don't use @main or @latest
- uses: actions/checkout@main  # Risky!
```

### Minimal Permissions

```yaml
# ✅ Request only needed permissions
permissions:
  contents: read
  pages: write
  id-token: write
```

### Third-Party Actions

Before adding new actions:

1. **Check the source** - Is it from a trusted organization?
2. **Review the code** - What does it actually do?
3. **Check for vulnerabilities** - Any known issues?
4. **Pin to specific version** - Prevent supply chain attacks

---

## Dependency Security

### No Runtime Dependencies

Currently, this repository has no npm/pip dependencies, which is a security advantage. If dependencies are added:

1. **Keep them minimal** - Only add what's necessary
2. **Use lockfiles** - `package-lock.json` or `requirements.txt` with hashes
3. **Audit regularly** - Use `npm audit` or `pip audit`
4. **Update promptly** - Apply security patches quickly

### Checking for Vulnerabilities

```bash
# For npm projects
npm audit

# For Python projects
pip audit

# For general scanning
snyk test
```

---

## File Upload and Processing

### If Accepting File Uploads

Even for static content preparation, validate:

```python
# ✅ Validate file types
ALLOWED_EXTENSIONS = {'html', 'css', 'js', 'png', 'jpg', 'gif', 'svg'}

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS
```

### File Size Limits

```python
# ✅ Limit file sizes
MAX_FILE_SIZE = 10 * 1024 * 1024  # 10 MB
```

---

## SVG Security

SVG files can contain JavaScript. Be cautious:

```xml
<!-- ❌ Dangerous SVG -->
<svg onload="alert('XSS')">
    <script>maliciousCode()</script>
</svg>
```

### Safe SVG Handling

1. **Sanitize SVGs** before serving
2. **Serve with proper headers** - `Content-Type: image/svg+xml`
3. **Consider CSP restrictions** - Disable scripts in SVGs

---

## Form and Input Handling

Even for static demos that include forms:

### Client-Side Validation

```html
<!-- ✅ Use HTML5 validation -->
<input type="email" required pattern="[^@]+@[^@]+\.[^@]+">

<!-- ✅ Add maxlength -->
<input type="text" maxlength="100">
```

### Never Trust Client-Side Validation Alone

If forms submit to any backend, always validate server-side too.

---

## Error Handling

### Safe Error Messages

```javascript
// ❌ Exposing internal details
catch (error) {
    alert(error.stack);  // Shows internal paths, versions
}

// ✅ User-friendly message
catch (error) {
    console.error(error);  // Log for debugging
    alert("An error occurred. Please try again.");  // Show generic message
}
```

---

## Security Headers (For Reference)

If you control the server configuration, consider these headers:

```
Content-Security-Policy: default-src 'self'
X-Content-Type-Options: nosniff
X-Frame-Options: DENY
X-XSS-Protection: 1; mode=block
Referrer-Policy: strict-origin-when-cross-origin
Permissions-Policy: geolocation=(), camera=(), microphone=()
```

Note: GitHub Pages has limited header configuration options.

---

## Incident Response

### If You Discover a Security Issue

1. **Don't publicize** - Report privately first
2. **Document details** - What, where, how discovered
3. **Contact maintainers** - Via private channel if possible
4. **Wait for fix** - Allow time for remediation

### Security Contact

For security issues, contact repository maintainers directly rather than creating public issues.

---

## Security Review Checklist

### Before Each Commit

- [ ] No secrets or credentials in code
- [ ] User inputs are validated
- [ ] Outputs are properly escaped
- [ ] External links use `noopener`
- [ ] Action versions are pinned
- [ ] No unnecessary permissions

### Periodic Review

- [ ] Check for dependency updates
- [ ] Review action security advisories
- [ ] Audit GitHub permissions
- [ ] Review access tokens and their scopes

---

## Common Vulnerabilities Reference

| Vulnerability | Risk | Prevention |
|---------------|------|------------|
| **XSS** | Script injection | Escape outputs, CSP |
| **CSRF** | Unauthorized actions | Tokens, SameSite cookies |
| **Path Traversal** | File access | Validate paths |
| **Dependency** | Supply chain | Audit, pin versions, use lockfiles, regular security updates |
| **Secrets** | Credential exposure | Environment variables |
| **Injection** | Command execution | Parameterized queries |

---

## Resources

### Learning

- [OWASP Top 10](https://owasp.org/www-project-top-ten/)
- [GitHub Security Guides](https://docs.github.com/en/security)
- [Web Security Academy](https://portswigger.net/web-security)

### Tools

- [GitHub Secret Scanning](https://docs.github.com/en/code-security/secret-scanning)
- [Dependabot](https://docs.github.com/en/code-security/dependabot)
- [npm audit](https://docs.npmjs.com/cli/v8/commands/npm-audit)

---

## Quick Security Wins

1. ✅ Use `textContent` instead of `innerHTML`
2. ✅ Encode URLs with `encodeURIComponent`
3. ✅ Add `rel="noopener"` to external links
4. ✅ Pin GitHub Actions versions
5. ✅ Use minimal workflow permissions
6. ✅ Keep the `.gitignore` comprehensive

---

*Last updated: December 2024*
