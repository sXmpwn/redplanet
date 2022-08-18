#!/bin/bash

BOOTF=boot/x86

nasm $BOOTF/boot.asm -felf32 -o boot.o
i686-elf-gcc -c main.c -o main.o -Iinclude -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T $BOOTF/linker.ld -o redplanet.bin -ffreestanding -O2 -nostdlib boot.o main.o -lgcc

rm *.o

mv redplanet.bin iso/boot/
grub-mkrescue -o redplanet.iso iso

qemu-system-i386 redplanet.iso

rm redplanet.iso
