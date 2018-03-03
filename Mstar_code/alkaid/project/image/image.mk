FSIMAGE_LIST:=$(filter-out $(patsubst %_fs__,%,$(filter %_fs__, $(foreach n,$(IMAGE_LIST),$(n)_fs_$($(n)$(FSTYPE))_))),$(IMAGE_LIST))
TARGET_FSIMAGE:=$(foreach n,$(FSIMAGE_LIST),$(n)_$(FLASH_TYPE)_$($(n)$(FSTYPE))_fsimage)
TARGET_NOFSIMAGE:=$(foreach n,$(filter-out $(FSIMAGE_LIST), $(IMAGE_LIST)),$(n)_nofsimage)

images: $(TARGET_FSIMAGE) $(TARGET_NOFSIMAGE)

%_ext4_fsimage : ./build/make_ext4fs
	@echo [[$@]]
	./build/make_ext4fs -S ./build/file_contexts -l $($(patsubst %_ext4_fsimage,%,$@)$(PATSIZE)) -b 1024 $(IMAGEDIR)/$(patsubst %_ext4_fsimage,%,$@).img $($(patsubst %_ext4_fsimage,%,$@)$(RESOUCE))

#the system can't bootup while use mkquashfs_xz compress.
%_nor_squashfs_fsimage: ./build/mksquashfs_xz
	@echo [[$@]]
	./build/mksquashfs_xz $($(patsubst %_nor_squashfs_fsimage,%,$@)$(RESOUCE)) $(IMAGEDIR)/$(patsubst %_nor_squashfs_fsimage,%,$@).sqfs -comp xz -all-root

%_nand_squashfs_fsimage: ./build/mksquashfs_xz
	@echo [[$@]]
	./build/mksquashfs_xz $($(patsubst %_nand_squashfs_fsimage,%,$@)$(RESOUCE)) $(IMAGEDIR)/$(patsubst %_nand_squashfs_fsimage,%,$@).sqfs -noappend -all-root

%_nor_jffs2_fsimage: ./build/mkfs.jffs2
	@echo [[$@]]
	./build/mkfs.jffs2  $($(patsubst %_nor_jffs2_fsimage,%,$@)$(PATSIZE)) --pad=$($(patsubst %_nor_jffs2_fsimage,%,$@)$(PATSIZE)) --eraseblock=0x10000 -d $($(patsubst %_nor_jffs2_fsimage,%,$@)$(RESOUCE)) -o $(IMAGEDIR)/$(patsubst %_nor_jffs2_fsimage,%,$@).jffs2

# ubifs default settings
#ifeq ($(UBI_MLC_TYPE), 0)
ERASE_BLOCK_SIZE0   :=0x20000
NAND_PAGE_SIZE0     :=0x800
UBI_LEB_SIZE0       :=126976
RESERVED_SIZE0      :=0
#else ifeq ($(UBI_MLC_TYPE), 1)
ERASE_BLOCK_SIZE1   :=0x40000
NAND_PAGE_SIZE1     :=0x1000
UBI_LEB_SIZE1       :=253952
RESERVED_SIZE1      :=4
#else ifeq ($(UBI_MLC_TYPE), 2)
ERASE_BLOCK_SIZE2   :=0x100000
NAND_PAGE_SIZE2     :=0x2000
UBI_LEB_SIZE2       :=1032192
RESERVED_SIZE2      :=0
#else
ERASE_BLOCK_SIZE    :=0x20000
NAND_PAGE_SIZE      :=0x800
UBI_LEB_SIZE        :=126976
RESERVED_SIZE       :=0
#endif

%_nand_ubifs_fsimage: ./build/mkfs.ubifs
	@echo [[$@]]
	./build/mkfs.ubifs -r $($(patsubst %_nand_ubifs_fsimage,%,$@)$(RESOUCE)) -o $(IMAGEDIR)/$(patsubst %_nand_ubifs_fsimage,%,$@).ubifs -m $(NAND_PAGE_SIZE$(UBI_MLC_TYPE)) -e $(UBI_LEB_SIZE$(UBI_MLC_TYPE)) -c `./build/calc_nand_mfs.sh $(patsubst %_nand_ubifs_fsimage,%,$@) $(NAND_PAGE_SIZE$(UBI_MLC_TYPE)) $(ERASE_BLOCK_SIZE$(UBI_MLC_TYPE)) $(RESERVED_SIZE$(UBI_MLC_TYPE)) $($(patsubst %_nand_ubifs_fsimage,%,$@)$(PATSIZE))`

%_nofsimage:
	@echo [[$@]]
	cp -rvf $($(patsubst %_nofsimage,%,$@)$(RESOUCE)) $(IMAGEDIR)/$(patsubst %_nofsimage,%,$@)

%_spinand_ubifs_fsimage: ./build/mkfs.ubifs
	@echo [[$@]]
	./build/mkfs.ubifs -r $($(patsubst %_spinand_ubifs_fsimage,%,$@)$(RESOUCE)) -o $(IMAGEDIR)/$(patsubst %_spinand_ubifs_fsimage,%,$@).ubifs -m $(NAND_PAGE_SIZE$(UBI_MLC_TYPE)) -e $(UBI_LEB_SIZE$(UBI_MLC_TYPE)) -c `./build/calc_nand_mfs.sh $(patsubst %_spinand_ubifs_fsimage,%,$@) $(NAND_PAGE_SIZE$(UBI_MLC_TYPE)) $(ERASE_BLOCK_SIZE$(UBI_MLC_TYPE)) $(RESERVED_SIZE$(UBI_MLC_TYPE)) $($(patsubst %_spinand_ubifs_fsimage,%,$@)$(PATSIZE))`