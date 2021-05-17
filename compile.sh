#!/bin/sh
# git pull
/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S main.c
arm-linux-gcc -static -o main.exe main.s
# lftp user4@arm
# q6coHjd7P
# put main.exe
# telnet arm
# user4
# q6coHjd7P
