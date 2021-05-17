#!/usr/bin/sh

git fetch --all
git reset --hard
git pull

chmod 777 /tmp/deb/seng440/scripts/linux/reset.sh
chmod 777 /tmp/deb/seng440/scripts/linux/compile.sh

/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S main.c
arm-linux-gcc -static -o main.exe main.s
lftp -c "open -u user4,q6coHjd7P arm; put main.exe"
