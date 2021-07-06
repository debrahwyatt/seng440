# seng440


## matrix inversion
calculates inverse of 2x2 matrix 

## matrix determinant
 - WIP - 
 calculates determinant of nxn matrix which is needed to find the inverse of an nxn matrix

## Compile on Windows
    - gcc main.c -o main.exe

## To run the exe on Windows
    - .\main.exe

## To install on ARM
    - log into UVic VPN
    - ssh into seng440.ece.uvic.ca
    - login using your uvic credentials
    - cd /
    - git clone https://github.com/debrahwyatt/seng440.git
    - chmod 777 ./seng440 -R
    - cd ./seng440
    - ./scripts/linux/compile.sh

## Reset on linux
    - ./scripts/linux/reset

## Simulate ARM
    - qemu-arm main.exe

## Login to ARM
    - log into the lab computer
    - telnet arm
    - username: user4
    - password: q6coHjd7P