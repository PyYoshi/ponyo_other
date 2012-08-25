#!/bin/bash
ANDROID_DIR=/home/hpyu/ponyo
make -j4 ARCH=arm CROSS_COMPILE=$ANDROID_DIR/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/arm-eabi- LINUXDIR=$ANDROID_DIR/out/target/product/pana2_1/obj/KERNEL_OBJ dhd-cdc-sdmmc-gpl-debug
#make -j4 ARCH=arm CROSS_COMPILE=$ANDROID_DIR/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/arm-eabi- LINUXDIR=/home/hpyu/4130/kernel-ponyo dhd-cdc-sdmmc-gpl-debug

cp -v dhd-cdc-sdmmc-gpl-debug-2.6.35.11/dhd.ko  ~/share/

