
CPU_FREQ_600MHZ = 0x5C28F4
CPU_FREQ_700MHZ = 0x4EFE88
CPU_FREQ_800MHZ = 0x451EB7
CPU_FREQ_900MHZ = 0x3D70A3
CPU_FREQ_1000MHZ = 0x374BC6
CPU_FREQ_1100MHZ = 0x3244E2
CPU_FREQ_1200MHZ = 0x2E147A

// init demod_atop (xtal / dmpll)
WREG (REG_ADDR_BASE + (0x101e38 <<1 )) , 0x0000
WREG_B (REG_ADDR_BASE + (0x102102 <<1 )+1) , 0x00
WREG (REG_ADDR_BASE + (0x11286a <<1 )) , 0x1e03
WREG (REG_ADDR_BASE + (0x11286a <<1 )) , 0x0603
WREG (REG_ADDR_BASE + (0x112866 <<1 )) , 0x1201
WREG (REG_ADDR_BASE + (0x112860 <<1 )) , 0x1c00
WREG (REG_ADDR_BASE + (0x112840 <<1 )) , 0x0000
WREG_B (REG_ADDR_BASE + (0x112878 <<1 )+1) , 0x00
WREG (REG_ADDR_BASE + (0x101e38 <<1 )) , 0x0300

// Turn on xtal
WREG (REG_ADDR_BASE + (0x000e7a <<1 )) , 0x0000

//
//CPU freq setting
//

// MIPSPLL disable
WREG_B (REG_ADDR_BASE + ((0x110a22 <<1) + 1)) , 0x09

.if (CONFIG_CPU_600MHZ == 1)
WREG (REG_ADDR_BASE + (0x110ac0 <<1 )) , (CPU_FREQ_600MHZ & 0xffff)
WREG (REG_ADDR_BASE + (0x110ac2 <<1 )) , (CPU_FREQ_600MHZ >> 16)
.endif

.if (CONFIG_CPU_800MHZ == 1)
WREG (REG_ADDR_BASE + (0x110ac0 <<1 )) , (CPU_FREQ_800MHZ & 0xffff)
WREG (REG_ADDR_BASE + (0x110ac2 <<1 )) , (CPU_FREQ_800MHZ >> 16)
.endif

.if (CONFIG_CPU_1000MHZ == 1)
WREG (REG_ADDR_BASE + (0x110ac0 <<1 )) , (CPU_FREQ_1000MHZ & 0xffff)
WREG (REG_ADDR_BASE + (0x110ac2 <<1 )) , (CPU_FREQ_1000MHZ >> 16)
.endif

.if (CONFIG_CPU_1200MHZ == 1)
WREG (REG_ADDR_BASE + (0x110ac0 <<1 )) , (CPU_FREQ_1200MHZ & 0xffff)
WREG (REG_ADDR_BASE + (0x110ac2 <<1 )) , (CPU_FREQ_1200MHZ >> 16)
.endif

WREG (REG_ADDR_BASE + (0x110ac4 <<1 )) , 0x0001

// bit0: MIPSPLL disable
WREG_B (REG_ADDR_BASE + ((0x110a22 <<1) + 1)) , 0x08