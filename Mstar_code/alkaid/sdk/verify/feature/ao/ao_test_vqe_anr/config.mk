include clear-config.mk
COMPILE_TARGET:=bin
CFLAGS:=-O0
SRCS:=ao_test_vqe_anr.c
LIBS:=mi_sys mi_ao SRC_LINUX APC_LINUX
include add-config.mk