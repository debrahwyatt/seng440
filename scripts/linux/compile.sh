#!/bin/sh

/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S /tmp/dev/seng440/mat_inv.c
arm-linux-gcc -static -o /tmp/dev/seng440/mat_inv.exe /tmp/dev/seng440/mat_inv.s
lftp -c "open -u user3,q6coHjd7P arm; put mat_inv.exe"
