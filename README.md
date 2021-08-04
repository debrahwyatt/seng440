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
    - username: user4
    - password: q6coHjd7P
    - chmod 777 main.exe ; ./main.exe ; rm main.exe

## Pipeline Commands
    - git commit -m "testing" -a | git push
    - git stash ; git pull ; chmod 777 . -R ; ./scripts/linux/compile.sh