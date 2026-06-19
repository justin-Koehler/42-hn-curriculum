# How – Quick Command Help

Simple help pages accessed with the `how` command.

## Quick Install

```
./scripts/install.sh
```

Then use it:

```
how git clone
```

## Uninstall

```
./scripts/uninstall.sh
```

## Structure

- how/ — Help pages (plain text, one per command)
- scripts/ — install/uninstall helpers
- scripts/how — The `how` command itself

## Notes

Help pages are installed into:

```
~/.local/share/how
```

The `how` command is installed into:

```
~/.local/bin/how
```

Make sure `~/.local/bin` is in your PATH.
