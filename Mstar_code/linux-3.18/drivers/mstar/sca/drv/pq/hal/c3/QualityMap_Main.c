// $Change: 616729 $
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2008-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////


#define PQTABLE_NAME    MAIN                // table config parameter
#if defined(MSOS_TYPE_LINUX_KERNEL)
#include <linux/string.h>
#include <linux/kernel.h>
#else
#include <string.h>
#endif

#include "MsTypes.h"
#include "MsCommon.h"
#include "drvXC_IOPort.h"
#include "apiXC.h"

#include "color_reg.h"
#include "color_sc1_reg.h"
#include "color_sc2_reg.h"
#include "drvPQ_Define.h"
#include "drvPQ_Declare.h"
#include "drvPQ.h"
#include "hwreg_utility2.h"

#define PQTBL_REGTYPE       PQTBL_NORMAL    // table config parameter

#if(PQ_ONLY_SUPPORT_BIN == 0)

    #include "Cedric_Main.c"                  // table config parameter
    #include "Cedric_Main_1366.c"             // table config parameter
    #include "Cedric_Main_1366_PIP.c"         // table config parameter
    #include "Cedric_Main_1366_POP.c"         // table config parameter
    #include "Cedric_Main_HSDRule.c"          // table config parameter
    #include "Cedric_Main_VSDRule.c"          // table config parameter
    #include "Cedric_Main_HSPRule.c"          // table config parameter
    #include "Cedric_Main_VSPRule.c"          // table config parameter
    #include "Cedric_Main_CSCRule.c"          // table config parameter
    #include "Cedric_Main_GRule.c"            // table config parameter
    #include "Cedric_Main_1366_GRule.c"       // table config parameter
    #include "Cedric_Main_1366_PIP_GRule.c"   // table config parameter
    #include "Cedric_Main_1366_POP_GRule.c"   // table config parameter
#endif

#include "QualityMode.h"
#include "drvPQ_Datatypes.h"
#include "mhal_pq.h"
#include "drvPQ_Template.h"
