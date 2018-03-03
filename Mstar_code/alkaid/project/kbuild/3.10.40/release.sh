while getopts "k:l:n:c:b:" opt; do
  case $opt in
    k)
		KERNEL_DIR=$OPTARG
		;;
	l)
		C_LIB_TYPE=$OPTARG
		;;
	n)
		TOOL_VER=$OPTARG
		;;
	c)
		CHIP_NAME=$OPTARG
		;;
	b)
		BOARD_NAME=$OPTARG
		;;
	\?)
	  echo "Invalid option: -$OPTARG" >&2
	  ;;
  esac
done
cp ${KERNEL_DIR}/arch/arm/boot/uImage ../../release/${CHIP_NAME}/${BOARD_NAME}/${C_LIB_TYPE}/${TOOL_VER}/bin/kernel/nand/uImage -v
cp ${KERNEL_DIR}/.config ./configs/${CHIP_NAME}/${BOARD_NAME}/${C_LIB_TYPE}/.config -v
cp ${KERNEL_DIR}/Module.symvers ./configs/${CHIP_NAME}/${BOARD_NAME}/${C_LIB_TYPE}/Module.symvers -v
cp ${KERNEL_DIR}/include/config/auto.conf ./configs/${CHIP_NAME}/${BOARD_NAME}/${C_LIB_TYPE}/include/config/auto.conf -v
cp ${KERNEL_DIR}/include/generated/ ./configs/${CHIP_NAME}/${BOARD_NAME}/${C_LIB_TYPE}/include/ -rfv
