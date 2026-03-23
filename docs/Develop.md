# Development Guide

## Quick Start

### Test and Debug the Theme

1. `code .` under the repo's root folder
2. Press `F5` to start the debug mode

### Package the Theme

**Note**: `vsce` requires Node.js >= 20. Use NVM (Node Version Manager) to temporarily switch versions while keeping your global Node.js unchanged.

#### Step 1: Install NVM for Windows

1. Download from: https://github.com/coreybutler/nvm-windows/releases
2. Extract and run `nvm-setup.exe`
3. Follow the installation wizard
4. Restart your terminal after installation

#### Step 2: Set Up Node.js Versions

```bash
# Install Node.js 20 (for packaging)
nvm install 20

# Verify installation
nvm list
```

#### Step 3: Package

```bash
# Switch to Node.js 20 (only for packaging)
nvm use 20

# Package the extension
npm install --save-dev @vscode/vsce
npx vsce package
```

This will create a `.vsix` file in the project root.

#### Step 4: Switch Back to Your Default Version

```bash
# Switch back to your default Node.js version (e.g., v16)
nvm use 16

# Verify
node --version
```

---

## Theme Structure

The theme uses a simple structure with a single theme file:

**Theme File:**
- **themes/ccpro_theme.json** - The main dark theme file (manually maintained)

**Other Files:**
- **themes/ccpro_theme_light.json** - Light theme (separate file)
- **color-table.md** - Color reference
- **package.json** - Extension manifest

### File Structure

```
ccpro_theme/
├── themes/
│   ├── ccpro_theme.json               # Dark theme
│   └── ccpro_theme_light.json         # Light theme
├── image/                             # Theme icons
├── color-table.md                     # Color reference
└── package.json                       # Extension manifest
```

### Build Commands

```bash
# No build step needed - theme files are used directly

# This merges base + customizations → themes/ccpro_theme.json
```

### Development Workflow

1. **Modify** your customizations in `src/customizations.json` or `src/semantic-customizations.json`
2. **Build**: `npm run build`
3. **Test**: Reload VS Code window to see changes
4. **Repeat** until satisfied

### Merge Strategy

**Token Colors: Scope-Based Override**
- When customization scopes overlap with base tokens, customization completely replaces base
- Non-overlapping tokens from both files are preserved

### Theme Maintenance

Since the theme files are now simple and not generated, you can edit them directly:

**To customize:**
- Edit `themes/ccpro_theme.json` directly for dark theme
- Edit `themes/ccpro_theme_light.json` directly for light theme

**Benefits:**
- ✅ Simple structure - no build process
- ✅ Direct editing - see changes immediately
- ✅ Full control - modify any aspect without constraints

### Troubleshooting

**Changes not appearing:**
1. Reload VS Code window (`Ctrl+Shift+P` → "Reload Window")
2. Ensure you're using "C/C++ Pro Theme" (not Light variant)
3. Check JSON syntax in the theme file

**Scope conflicts:**
- Verify scope matches exactly
- Some scopes might be semantic, not textmate
- Use developer tools to inspect token scopes

---

## Technical Reference

### Token Format

`(*|tokenType)(.tokenModifier)*(:tokenLanguage)?`

### References

- [The Semantic Highlight Guide from VSCode](https://code.visualstudio.com/api/language-extensions/semantic-highlight-guide)
