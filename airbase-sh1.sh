#!/bin/sh

airmon-ng start wlan0
airbase-ng -e $1 -c 5 mon0
