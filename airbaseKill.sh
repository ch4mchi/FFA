#!/bin/bash 

ifconfig at0 0.0.0.0 down
brctl delif $1 at0
brctl delif $1 eth0
killall airbase-ng
airmon-ng stop mon0
