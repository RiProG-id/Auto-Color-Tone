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
