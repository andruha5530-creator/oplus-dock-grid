#!/system/bin/sh
MODDIR=${0%/*}
CONF="$MODDIR/config/dock.conf"
case "$1" in 5|6|7|8) printf 'DOCK_COUNT=%s\n' "$1" > "$CONF"; echo "Dock count set to $1";; *) echo "Current: $(sed -n 's/^DOCK_COUNT=//p' "$CONF" | head -n1)"; echo "Usage: action.sh [5|6|7|8]";; esac
