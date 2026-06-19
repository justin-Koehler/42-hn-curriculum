#!/usr/bin/env bash

# Uninstall how

SCRIPT_DEST="$HOME/.local/bin/how"
HELP_DEST="$HOME/.local/share/how"

rm -f "$SCRIPT_DEST"
rm -rf "$HELP_DEST"

echo "✓ Deinstalliert: 'how' Kommando"
