# <- this is for comment / total file size must be less than 4KB
nand erase.part UBI
ubi part UBI
ubi create SYSTEM 0xE20000
tftp 0x21000000 rootfs.ubifs
ubi write 0x21000000 SYSTEM $(filesize)

#ubi create EXT 0xE20000
#tftp 0x21000000 ext.ubifs
#ubi write 0x21000000 EXT $(filesize)

ubi create DATA 0x860000
tftp 0x21000000 nvrservice.ubifs
ubi write 0x21000000 DATA $(filesize)

ubi create customer 0x4000000
tftp 0x21000000 customer.ubifs
ubi write 0x21000000 customer $(filesize)

% <- this is end of file symbol
