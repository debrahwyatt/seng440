#!/usr/bin/sh

git fetch --all
git reset --hard
git pull

chmod 777 . -R


if [ "$1" = "-c" ]; then
  /opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 -S /tmp/seng440/main.c
  arm-linux-gcc -static -o /tmp/seng440/main.exe /tmp/seng440/main.s
  lftp -c "open -u user4,q6coHjd7P arm; put /tmp/seng440/main.exe"
fi
