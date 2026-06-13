#!/bin/bash

echo "========== CPU =========="
lscpu

echo
echo "========== MEM =========="
free -h

echo
echo "========== FD LIMIT =========="
ulimit -n

echo
echo "========== TCP =========="
sysctl net.ipv4.ip_local_port_range

echo
echo "========== SOMAXCONN =========="
sysctl net.core.somaxconn

echo
echo "========== SYN BACKLOG =========="
sysctl net.ipv4.tcp_max_syn_backlog