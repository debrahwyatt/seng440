#!/bin/sh

/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S /tmp/dev/seng440/neon.c
arm-linux-gcc -static -o /tmp/dev/seng440/neon.exe /tmp/dev/seng440/neon.s
lftp -c "open -u user3,q6coHjd7P arm; put neon.exe"
