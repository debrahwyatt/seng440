# seng440


## matrix inversion
calculates inverse of 2x2 matrix 

## matrix determinant
 - WIP - 
 calculates determinant of nxn matrix which is needed to find the inverse of an nxn matrix

## Compile and run on Windows
    - gcc mat_inv.c -o mat_inv.exe ; .\mat_inv.exe

## To install on ARM
    - log into UVic VPN
    - ssh seng440.ece.uvic.ca
    - login using your uvic credentials
    - cd / ; mkdir tmp/dev ; cd tmp/dev/ ; git clone https://github.com/debrahwyatt/seng440.git ; chmod 777 ./seng440 -R ; cd ./seng440 ; ./scripts/linux/compile.sh
    -  git stash ; git pull ; chmod 777 . -R ; ./scripts/linux/compile.sh

## Reset on linux
    - ./scripts/linux/reset

## Simulate ARM
    - qemu-arm main.exe

## Login to ARM
    - log into the lab computer
    - telnet arm
    - username: user3
    - password: q6coHjd7P
    - chmod 777 neon.exe ; ./neon.exe ; rm neon.exe

## Pipeline Commands
    - git commit -m "testing" -a | git push
    - git stash ; git pull ; chmod 777 . -R ; ./scripts/linux/compile.sh


## VM Instructions
    - qemu-system-arm -m 4G -smp 2 -hda Fedora-Minimal-armhfp-29-1.2-sda.qcow2 -machine virt-2.11 -kernel vmlinuz-4.18.16-300.fc29.armv7hl -initrd initramfs-4.18.16-300.fc29.armv7hl.img  -append "console=ttyAMA0 rw root=LABEL=_/ rootwait ipv6.disable=1" -nographic -netdev user,id=seng440,hostfwd=tcp::2222-:22 -device virtio-net-pci,netdev=seng440
    - Username: root
    - Password: seng440
    - git pull ; gcc test_neon2.c -mfpu=neon -march=armv7-a -o mytest ; ./mytest