#!/bin/sh
SKIPMOUNT=false
PROPFILE=false
POSTFSDATA=false
LATESTARTSERVICE=true
REPLACE="
"
ui_print ""
ui_print "*****************************************"
ui_print "*      RiProG Open Source @RiOpSo       *"
ui_print "*****************************************"
ui_print "*                                       *"
ui_print "*             Muhammad Rizki            *"
ui_print "* Telegram: @RiProG | Github: RiProG-id *"
ui_print "*                                       *"
ui_print "*****************************************"
ui_print ""
unzip -o "$ZIPFILE" 'source.c' -d "$MODPATH" >&2
unzip -o "$ZIPFILE" 'main' -d "$MODPATH" >&2
chmod +x "$MODPATH/main"
ui_print ""
kcal_1="/sys/devices/platform/kcal_ctrl.0"
kcal_2="$(find /sys/module/msm_drm/parameters/ -maxdepth 1 -type f -name 'kcal_*')" >/dev/null 2>&1
if [ -d "$kcal_1" ]; then
	ui_print "kcal Mode"
elif [ -n "$kcal_2" ]; then
	ui_print "msm_drm Mode"
else
	ui_print "surfaceflinger Mode"
fi
ui_print ""
