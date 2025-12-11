# 🏭 Ominous Industries

**Static content repository for Bijan Bowen's YouTube channel**

This repository hosts interactive demos, code examples, and supplementary materials for AI-focused videos. Content is automatically deployed to GitHub Pages with a dynamically generated file index.

![Ominous Industries Index Page](https://github.com/user-attachments/assets/9122f3e4-81b5-47cb-aee0-e2e3fa61b116)

## 🌐 Links

- **Website**: [bijanbowen.com](https://www.bijanbowen.com/)
- **YouTube**: [@Bijanbowen](https://www.youtube.com/@Bijanbowen)
- **Live Demo Index**: [GitHub Pages](https://guthabbr0.github.io/Ominous_Industries_BijanBowenTestingFiles/)

## 📂 Repository Structure

```
/
├── static/              # Demo files organized by video
│   ├── [Video Title]/   # Each folder matches a YouTube video
│   │   └── [files]      # HTML, CSS, JS demos
├── index.html           # Auto-generated file index
└── .github/
    └── workflows/       # Automated deployment
```

## 🎨 Design Philosophy

The site features a **warm, welcoming aesthetic** with an orangey color palette:
- Primary: `#E07B39` (Warm Orange)
- Background: `#FDF8F3` (Warm White)
- Cards: `#FBF4ED` (Cream)
- Text: `#3D3936` (Warm Charcoal)

## 🚀 Features

- **📁 Organized Content**: One folder per YouTube video
- **🔍 Search & Filter**: Find demos quickly
- **📱 Responsive Design**: Works on all devices
- **🔄 Auto-Deploy**: Updates automatically on push
- **🎯 Clean Navigation**: Collapsible folder cards

## 🛠️ How It Works

1. Demo files are added to `/static/[Video Title]/`
2. GitHub Actions workflow automatically:
   - Scans the static directory
   - Generates a searchable index.html
   - Deploys everything to GitHub Pages
3. The index page displays all folders and files with:
   - File type icons
   - Search functionality
   - Alphabetical sorting

## 📝 Adding Content

To add new demo content:

1. Create a folder in `/static/` matching your video title
2. Add your HTML, CSS, JS, and other demo files
3. Commit and push to `main` branch
4. GitHub Actions will automatically deploy

## 🔒 Security

- XSS-safe JSON embedding with `<script type="application/json">`
- HTML escaping for all dynamic content
- URL encoding for file paths
- No secrets committed to repository

## 📄 License

All content © Bijan Bowen. See individual files for specific licensing.
