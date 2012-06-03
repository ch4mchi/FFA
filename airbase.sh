#!/bin/sh
gnome-terminal -x airbase-ng -e $1 -c 5 mon0
sleep 3
ifconfig at0 up
ifconfig at0 192.168.2.129 netmask 255.255.255.128
route add -net 192.168.2.128 netmask 255.255.255.128 gw 192.168.2.129

mkdir -p /var/run/dhcpd && chown dhcpd:dhcpd /var/run/dhcpd
dhcpd3 -cf /etc/dhcp3/dhcpd.conf -pf /var/run/dhcpd/dhcpd.pid at0
sleep 3

iptables --flush
iptables --table nat --flush
iptables --delete-chain
iptables --table nat --delete-chain
iptables -P FORWARD ACCEPT
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE

echo 1 > /proc/sys/net/ipv4/ip_forward
