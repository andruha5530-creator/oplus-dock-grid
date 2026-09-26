#!/system/bin/sh
MODDIR=${0%/*}
CONF="$MODDIR/config/dock.conf"
STATE="/data/adb/oplus_dock_grid"
mkdir -p "$STATE"
COUNT="$(sed -n 's/^DOCK_COUNT=\([0-9][0-9]*\)$/\1/p' "$CONF" 2>/dev/null | head -n 1)"
case "$COUNT" in 5|6|7|8) ;; *) COUNT=5; printf '%s\n' 'DOCK_COUNT=5' > "$CONF";; esac
printf '%s\n' "$COUNT" > "$STATE/current_count"
exit 0
