cmd_drivers/mmc/card/mmc_block.ko := arm-linux-gnueabihf-ld -EL -r  -T ./scripts/module-common.lds --build-id  -o drivers/mmc/card/mmc_block.ko drivers/mmc/card/mmc_block.o drivers/mmc/card/mmc_block.mod.o