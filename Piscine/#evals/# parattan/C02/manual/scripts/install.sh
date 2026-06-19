#!/usr/bin/env bash

# Install how - Help system
# Works for any user who clones the repo

# Find script directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"

SCRIPT_SOURCE="$SCRIPT_DIR/how"
SCRIPT_DEST="$HOME/.local/bin/how"
HELP_SOURCE="$REPO_DIR/how"
HELP_DEST="$HOME/.local/share/how"

mkdir -p "$HOME/.local/bin"
mkdir -p "$HELP_DEST"

# Copy help files
cp "$HELP_SOURCE"/* "$HELP_DEST/" 2>/dev/null

# Copy and make script executable
cp "$SCRIPT_SOURCE" "$SCRIPT_DEST"
chmod +x "$SCRIPT_DEST"

echo "✓ Installed: 'how' command"
echo "✓ Help files: $HELP_DEST"
echo ""
echo "Usage:"
echo "  how index          # See all topics"
echo "  how git clone"
echo "  how git status"
echo "  how git add"
echo "  how git commit"
