#!/bin/sh

/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S /tmp/dev/seng440/main.c
arm-linux-gcc -static -o /tmp/dev/seng440/main.exe /tmp/seng440/main.s
lftp -c "open -u user4,q6coHjd7P arm; put main.exe"
