#!/usr/bin/python

import serial
import argparse
import sys

parser = argparse.ArgumentParser(description='Setup Kp, Ki and Kd parameters for PID Controller.')
parser.add_argument("-P", "--proportional", help="set Kp parameter")
parser.add_argument("-I", "--integral", help="set Ki parameter")
parser.add_argument("-D", "--derivative", help="set Kd paramter")

args = parser.parse_args()

print(args)

ser = serial.Serial('/dev/ttyACM0', 115200)
print(ser.name)

size = 15
arr = bytearray(size)
ser.write(size.to_bytes(1, 'little'))

