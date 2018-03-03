//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
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
//==============================================================================
#ifdef STELLAR

#define _DRV_PQ_EX_C


#ifdef MSOS_TYPE_LINUX_KERNEL
#include <linux/string.h>
#else
#include <string.h>
#endif

#ifdef MSOS_TYPE_LINUX
#include <pthread.h>
#endif

#include "MsCommon.h"
//#include "MsVersion.h"
#include "MsOS.h"
#include "MsTypes.h"
#include "utopia.h"
#include "utopia_dapi.h"

#include "hwreg_utility2.h"
#include "color_reg.h"

#include "drvXC_IOPort.h"
#include "apiXC.h"
#include "apiXC_v2.h"
#include "apiXC_Ace.h"

#include "drvPQ_Define.h"
#include "drvPQ_Declare.h"
#include "drvPQ.h"
#include "drvPQ_cus.h"
#include "drvPQ_Datatypes.h"
#include "mhal_pq.h"
#include "mhal_pq_cus.h"
#include "drvPQ_Bin.h"

#include "QualityMode.h"
#include "PQ_private.h"
#include "apiPQ_v2.h"
#include "mhal_pq_adaptive.h"

//-------------------------------------------------------------------------------------------------
//  Macro and Define
//-------------------------------------------------------------------------------------------------

#ifndef UNUSED //to avoid compile warnings...
#define UNUSED(var) (void)((var) = (var))
#endif

#define PQ_EX_DBG(x)               (x)

//-------------------------------------------------------------------------------------------------
//  Local Variable
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//  Function
//-------------------------------------------------------------------------------------------------
MS_BOOL MDrv_PQ_EX_Ctrl_U2(void* pInstance,MS_U32 u32Cmd,void *pbuf,MS_U32 u32BufSize)
{
    if ((pbuf == NULL)  || (u32BufSize == 0))
    {
        printf(" %s %d: invalid input parameters of Cmd(%u). return  \n", __FUNCTION__,  __LINE__,u32Cmd);
        return FALSE;
    }
    switch(u32Cmd)
    {
        case E_PQ_CMD_EX_SET_ICC_REGION:
            PQ_EX_DBG(printf("\33[1;32m [PQ_EX] %s %d: E_PQ_CMD_EX_SET_ICC_REGION 	\33[m \n", __FUNCTION__,  __LINE__));
            Hal_PQ_set_sram_icc_crd_table(pInstance,SC_FILTER_SRAM_ICC_CRD, pbuf);
            break;
        case E_PQ_CMD_EX_SET_IHC_REGION:
            PQ_EX_DBG(printf("\33[1;32m [PQ_EX] %s %d: E_PQ_CMD_EX_SET_IHC_REGION 	\33[m \n", __FUNCTION__,  __LINE__));
            Hal_PQ_set_sram_ihc_crd_table(pInstance,SC_FILTER_SRAM_IHC_CRD, pbuf);
            break;
        case E_PQ_CMD_EX_DUMP_CUS_TABLE:
            PQ_EX_DBG(printf("\33[1;32m [PQ_EX] %s %d: E_PQ_CMD_EX_DUMP_CUS_TABLE 	\33[m \n", __FUNCTION__,  __LINE__));
            MDrv_PQ_DumpTable_(MAIN, pInstance, (EN_IP_Info* )pbuf);
            break;
        case E_PQ_CMD_EX_NUM:
        default:
            printf(" %s %d: invalid cmd id = %x  \n", __FUNCTION__,  __LINE__, u32Cmd);
            break;
    }

    return TRUE;
}


MS_BOOL MDrv_PQ_EX_Ctrl(MS_U32 u32Cmd,void *pbuf,MS_U32 u32BufSize)
{
    if (pu32PQInst == NULL)
    {
        printf("[%s,%5d]No instance existed, please get an instance by calling MDrv_PQ_Init() first\n",__FUNCTION__,__LINE__);
        return FALSE;
    }

    stPQ_CMD_EX_CTRL PQArgs;
    PQArgs.u32Cmd = u32Cmd;
    PQArgs.pbuf = pbuf;
    PQArgs.u32BufSize = u32BufSize;
    PQArgs.bReturn = FALSE;

    if(UtopiaIoctl(pu32PQInst, E_PQ_CMD_EX_CTRL, (void*)&PQArgs) != UTOPIA_STATUS_SUCCESS)
    {
        printf("PQ engine GET_CONFIG Ioctl fail\n");
        return E_PQ_RET_FAIL;
    }
    else
    {
        return PQArgs.bReturn;
    }
}


#endif

//--------------------------------------------------------------