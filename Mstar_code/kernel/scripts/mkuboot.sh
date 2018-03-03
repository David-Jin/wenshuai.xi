#!/bin/bash

#
# Build U-Boot image when `mkimage' tool is available.
#

MKIMAGE=$(type -path "${CROSS_COMPILE}mkimage")
MKIMAGE=arch/arm/boot/mkimage

if [ -z "${MKIMAGE}" ]; then
	MKIMAGE=$(type -path mkimage)
	if [ -z "${MKIMAGE}" ]; then
		# Doesn't exist
		echo '"mkimage" command not found - U-Boot images will not be built' >&2
		exit 1;
	fi
fi

# Call "mkimage" to create U-Boot image
if [ -f arch/arm/boot/zImage ];then
	cp -f arch/arm/boot/zImage arch/arm/boot/zImage.cp
	gzip -f -9 arch/arm/boot/zImage.cp
fi
${MKIMAGE} "$@"