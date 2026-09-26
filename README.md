# Oplus Dock Grid

KernelSU + Zygisk scaffold for OnePlus OplusLauncher 16.4.24_9f0537d_260727.

This repository intentionally does not contain an unverified ART/Zygisk hook. It is a safe scaffold until the exact runtime hook is validated against the supplied OplusLauncher APK.

Configuration: config/dock.conf with DOCK_COUNT=5, 6, 7, or 8. Default is 5.

Emergency disable: adb shell su -c 'touch /data/adb/modules/oplus_dock_grid/disable' then reboot.
