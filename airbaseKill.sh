#!/bin/bash 

killall airbase-ng
airmon-ng stop mon0
echo 0 > /proc/sys/net/ipv4/ip_forward
kill $(cat /var/run/dhcpd/dhcpd.pid)

