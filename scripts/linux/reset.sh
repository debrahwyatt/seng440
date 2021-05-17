#!/usr/bin/sh

git fetch --all
git reset --hard
git pull

chmod 777 /tmp/deb/seng440/scripts/linux/reset.sh
chmod 777 /tmp/deb/seng440/scripts/linux/compile.sh

if [ "$1" -eq "-c" ]
then
  /opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S /tmp/deb/seng440/main.c
  arm-linux-gcc -static -o /tmp/deb/seng440/main.exe /tmp/deb/seng440/main.s
  lftp -c "open -u user4,q6coHjd7P arm; put /tmp/deb/seng440/main.exe"
fi
