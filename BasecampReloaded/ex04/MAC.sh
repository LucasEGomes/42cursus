#!/bin/sh
ifconfig -a |
grep -e "^\s*ether" |
sed "s/^\s*ether\s*//;s/\s.*//"