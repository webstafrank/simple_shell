#!/bin/bash
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Max PID value is: $pid_max"
