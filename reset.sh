#!/usr/bin/sh

git fetch --all
git reset --hard
git pull

chmod 777 reset.sh
chmod 777 compile.sh
