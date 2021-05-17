#!/usr/bin/sh

git fetch --all
git reset --hard
git pull

chmod 777 /tmp/deb/seng440/scripts/linux/reset.sh
chmod 777 /tmp/deb/seng440/scripts/linux/compile.sh
