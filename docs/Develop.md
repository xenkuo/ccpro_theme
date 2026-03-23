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

#### Step 3: Build and Package

```bash
# Switch to Node.js 20 (only for packaging)
nvm use 20

# Build first (optional, if you made changes)
npm run build

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

## Build System

### Architecture

The theme uses a modular approach with separated customization files:

**Source Files:**
1. **Base Theme** - `src/dracula-base.json`
   - Official Dracula theme (version 2.24.2)
   - Provides base colors, token colors, and semantic tokens

2. **Token Customizations** - `src/customizations.json`
   - Your C/C++ specific textmate token customizations

3. **Semantic Token Customizations** - `src/semantic-customizations.json`
   - Your C/C++ specific semantic token customizations

**Build Output:**
- **Final Theme** - `themes/ccpro_theme.json` (GENERATED - do not edit manually)

**Build Script:**
- **Merge Script** - `src/merge-themes.js`

### File Structure

```
ccpro_theme/
├── themes/
│   ├── ccpro_theme.json               # ⚠️ GENERATED
│   └── ccpro_theme_light.json         # Light theme
├── src/
│   ├── dracula-base.json             # Base Dracula (v2.24.2)
│   ├── merge-themes.js               # Build script
│   ├── customizations.json           # Your tokens
│   └── semantic-customizations.json  # Semantic tokens
├── color-table.md                    # Color reference
└── package.json                      # Extension manifest
```

### Build Commands

```bash
# Build the theme
npm run build

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

**Semantic Token Colors: Key-Based Override**
- Custom semantic tokens override base tokens by key name
- New semantic tokens are added

### Why Modular?

**Benefits:**
- ✅ Easier updates - Update base Dracula without losing customizations
- ✅ Clearer maintenance - See exactly what you've changed
- ✅ Better version control - Separate concerns in commits
- ✅ Reusability - Apply customizations to other base themes

**Before:** 1564 lines monolithic file  
**After:** Base theme untouched + ~380 lines of your changes

### Troubleshooting

**Build fails with JSON error:**
- Check for trailing commas, proper quote escaping, valid JSON syntax
- Use VS Code's built-in JSON validation

**Changes not appearing:**
1. Run `npm run build` again
2. Reload VS Code window (`Ctrl+Shift+P` → "Reload Window")
3. Ensure you're using "C/C++ Pro Theme" (not Light variant)

**Scope conflicts:**
- Verify scope matches exactly
- Some scopes might be semantic, not textmate
- Use developer tools to inspect token scopes

> ⚠️ **Never edit `themes/ccpro_theme.json` directly** - it will be overwritten on next build. Always edit the customization files instead.

---

## Technical Reference

### Token Format

`(*|tokenType)(.tokenModifier)*(:tokenLanguage)?`

### References

- [The Semantic Highlight Guide from VSCode](https://code.visualstudio.com/api/language-extensions/semantic-highlight-guide)
