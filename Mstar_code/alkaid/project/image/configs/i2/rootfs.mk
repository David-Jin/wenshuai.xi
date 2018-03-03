.PHONY: rootfs

rootfs:
	cd rootfs; tar xf rootfs.tar.gz -C $(OUTPUTDIR)
	tar xf busybox/$(BUSYBOX).tar.gz -C $(OUTPUTDIR)/rootfs
	tar xf $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/lib/package/$(LIBC).tar.gz -C $(OUTPUTDIR)/rootfs/lib
	cp $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/lib/dynamic/*.so $(OUTPUTDIR)/rootfs/lib/

	mkdir -p $(OUTPUTDIR)/tvconfig/config
	cp -rf $(PROJ_ROOT)/board/ini/* $(OUTPUTDIR)/tvconfig/config
	cp -rf $(PROJ_ROOT)/board/$(CHIP)/$(BOARD_NAME)/config/* $(OUTPUTDIR)/tvconfig/config
	cp -vf $(PROJ_ROOT)/board/$(CHIP)/mmap/$(MMAP) $(OUTPUTDIR)/tvconfig/config/mmap.ini
	cp -rvf $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/bin/config_tool/* $(OUTPUTDIR)/tvconfig/config
	cd $(OUTPUTDIR)/tvconfig/config; chmod +x config_tool; ln -sf config_tool dump_config; ln -sf config_tool dump_mmap
	cp -rf $(PROJ_ROOT)/board/$(CHIP)/pq $(OUTPUTDIR)/tvconfig/config/
	find  $(OUTPUTDIR)/tvconfig/config/pq/ -type f ! -name "Main.bin" -type f ! -name "Main_Ex.bin" -type f ! -name "Bandwidth_RegTable.bin"| xargs rm -rf
	cp -rvf $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/bin/AHDInit/* $(OUTPUTDIR)/tvconfig/config

	mkdir -p $(OUTPUTDIR)/rootfs/config
#	cp -rf $(OUTPUTDIR)/tvconfig/config/* $(OUTPUTDIR)/rootfs/config
	cp -rf etc/* $(OUTPUTDIR)/rootfs/etc
#	cp -rf $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/bin/verify/* $(OUTPUTDIR)/rootfs/bin
	mkdir -p $(OUTPUTDIR)/rootfs/lib/modules/
	mkdir -p $(OUTPUTDIR)/tvconfig/config/modules/$(KERNEL_VERSION)

	echo export PATH=\$$PATH:/config >> ${OUTPUTDIR}/rootfs/etc/profile
	sed -i '/^mount.*/d' $(OUTPUTDIR)/rootfs/etc/profile
	echo mkdir -p /dev/pts >> ${OUTPUTDIR}/rootfs/etc/profile
	echo mount -t sysfs none /sys >> $(OUTPUTDIR)/rootfs/etc/profile
	echo mount -t tmpfs mdev /dev >> $(OUTPUTDIR)/rootfs/etc/profile
	echo mount -t debugfs none /sys/kernel/debug/ >>  $(OUTPUTDIR)/rootfs/etc/profile

	if [ "$(FLASH_TYPE)"x = "spinand"x  ]; then \
		cp $(PROJ_ROOT)/tools/$(TOOLCHAIN)/iperf $(OUTPUTDIR)/tvconfig/config ; \
		echo mount -t ubifs ubi0:DATA /config >> $(OUTPUTDIR)/rootfs/etc/profile ; \
		echo mount -t ubifs ubi0:customer /customer >> $(OUTPUTDIR)/rootfs/etc/profile ; \
	else \
		echo mount -t jffs2 mtd:DATA /config >> $(OUTPUTDIR)/rootfs/etc/profile ; \
	fi;

	chmod 755 $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/bin/debug/*
	cp -rf $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/bin/debug/* $(OUTPUTDIR)/tvconfig/config

#	echo mount -t jffs2 /dev/mtdblock3 /config >> $(OUTPUTDIR)/rootfs/etc/profile
	ln -fs /config/modules/$(KERNEL_VERSION) $(OUTPUTDIR)/rootfs/lib/modules/
	find $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/lib/modules/$(KERNEL_VERSION) -name "*.ko" -exec cp {} $(OUTPUTDIR)/tvconfig/config/modules/$(KERNEL_VERSION) \;
	find $(OUTPUTDIR)/tvconfig/config/modules/$(KERNEL_VERSION) -type f | xargs $(TOOLCHAIN_REL)strip  --strip-unneeded
	echo insmod /config/modules/$(KERNEL_VERSION)/utpa2k.ko >> $(OUTPUTDIR)/rootfs/etc/profile
	echo insmod /config/modules/$(KERNEL_VERSION)/mhal.ko >> $(OUTPUTDIR)/rootfs/etc/profile
	cat $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/lib/modules/$(KERNEL_VERSION)/misc_mod_list | sed 's#\(.*\)#insmod /config/modules/$(KERNEL_VERSION)/\1.ko#' >> $(OUTPUTDIR)/rootfs/etc/profile
	cat $(PROJ_ROOT)/release/$(CHIP)/$(BOARD)/$(TOOLCHAIN)/$(TOOLCHAIN_VERSION)/lib/modules/$(KERNEL_VERSION)/.mods_depend | sed 's#\(.*\)#insmod /config/modules/$(KERNEL_VERSION)/\1.ko#' >> $(OUTPUTDIR)/rootfs/etc/profile
	echo insmod /config/modules/$(KERNEL_VERSION)/mstar_fbdev.ko >> $(OUTPUTDIR)/rootfs/etc/profile
	echo mdev -s >> $(OUTPUTDIR)/rootfs/etc/profile
	echo mkdir -p /dev/pts >> $(OUTPUTDIR)/rootfs/etc/profile
	echo mount -t devpts devpts /dev/pts >> $(OUTPUTDIR)/rootfs/etc/profile
	echo "busybox telnetd&" >> $(OUTPUTDIR)/rootfs/etc/profile
	echo "if [ -e /config/demo.sh ]; then" >> ${OUTPUTDIR}/rootfs/etc/profile
	echo "    /config/demo.sh" >> ${OUTPUTDIR}/rootfs/etc/profile
	echo "fi;" >> ${OUTPUTDIR}/rootfs/etc/profile
	mkdir -p $(OUTPUTDIR)/vendor
	mkdir -p $(OUTPUTDIR)/customer
	mkdir -p $(OUTPUTDIR)/rootfs/vendor
	mkdir -p $(OUTPUTDIR)/rootfs/customer
