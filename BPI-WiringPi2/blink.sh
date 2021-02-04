#!/bin/bash
echo 39 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio39/direction
echo 1 > /sys/class/gpio/gpio39/active_low
echo 0 > /sys/class/gpio/gpio39/value
echo "Start blink"
for ((a=1; a<=5 ; a++))
do
echo 1 > /sys/class/gpio/gpio39/value
sleep 0.5
echo 0 > /sys/class/gpio/gpio39/value
sleep 0.2
done
echo 0 > /sys/class/gpio/gpio39/value
echo 39 > /sys/class/gpio/unexport
echo "End blink"