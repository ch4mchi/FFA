#!/bin/sh

brctl addbr $1 
brctl addif $1 eth0
brctl addif $1 at0
ifconfig eth0 0.0.0.0 up
ifconfig at0 0.0.0.0 up
dhclient $1
echo 1 > /proc/sys/net/ipv4/ip_forward
