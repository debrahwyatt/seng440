#!/usr/bin/sh

git fetch --all
git branch backup-master
git reset --hard origin/master

chmod 777 reset.sh
chmod 777 compile.sh
