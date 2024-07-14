#!/bin/sh
while [ -z "$(getprop sys.boot_completed)" ]; do
	sleep 5
done
sleep 15
/data/adb/modules/ACT/main
