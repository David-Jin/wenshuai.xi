# <- this is for comment / total file size must be less than 4KB

mxp  t.init
tftp 0x21000000 MXP_SF.bin
mxp  t.update 0x21000000
mxp  t.load
sf probe 0
sf erase 0xC000 0x1000
sf write 0x21000000 0xC000 0x1000

% <- this is end of file symbol