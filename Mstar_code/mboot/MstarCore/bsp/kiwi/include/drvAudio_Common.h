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
// reverse bEngineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
//  [for Doxygen]
/// @file drvAudio_Common.h
/// @brief Subroutine for advance sound effect
/// @author MStarSemi Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef _DRVIPCHECK_H_
#define _DRVIPCHECK_H_

#include "MsTypes.h"
#include "drvAUDIO_if.h"


#ifdef __cplusplus
extern "C"
{
#endif

//====== STAOS PIP START 2012/02/02 ========
MMA_AudioType MDrv_AUDIO_CheckHashkey2(AUDIO_DEC_ID DecId, MMA_AudioType Param);
MS_BOOL MDrv_AUDIO_SetAudioParam2( AUDIO_DEC_ID DecId, Audio_ParamType paramType, MS_U32 Param );

//====== STAOS PIP END 2012/02/02 ========

MS_BOOL MDrv_AUDIO_SetSystem(En_DVB_decSystemType enDecSystem);
MS_BOOL MDrv_AUDIO_SetDecodeSystem(AUDIO_DEC_ID DecId, AudioDecStatus_t * p_AudioDecStatus);
void  MDrv_SOUND_VDS_Enable(MS_U8 u8enVDS);
void  MDrv_SOUND_VSPK_Enable(MS_U8 u8enVSPK);
void  MDrv_SOUND_SRS_SetTsxtPara(MS_U8 u8mode, MS_U8 u8value);
void  MDrv_SOUND_SRS_SetTshdPara(MS_U8 u8mode, MS_U8 u8value);
void  MDrv_SOUND_SRS_Enable(MS_U8 u8enSRS);
void  MDrv_SOUND_TSHD_Enable(MS_U8 u8enTSHD);
void  MDrv_SOUND_VSPK_SetWMod(MS_U8 u8VSPK_WMode);
void  MDrv_SOUND_VSPK_SetSMod(MS_U8 u8VSPK_SMode);
void  MDrv_SOUND_BBE_SetBbeMode(MS_U8 u8EnBBE, MS_U8 u8BBEMode);
void  MDrv_SOUND_SRS_DC(MS_U8 u8SRSenDC);
void  MDrv_SOUND_SRS_TruBass(MS_U8 u8SRSenTruBass);
void  MDrv_SOUND_TSHD_TruBass(MS_U8 u8TSHDenTruBass);
void  MDrv_SOUND_TSHD_Definition(MS_U8 u8TSHDenDefinition);
void  MDrv_SOUND_TSHD_Clarity(MS_U8 u8TSHDenClarity);
MS_BOOL MDrv_ADVSOUND_ProcessEnable(ADVSND_TYPE type);
MS_BOOL MDrv_ADVSOUND_SubProcessEnable(ADVFUNC proc, MS_BOOL enable);
void MDrv_DBXTV_SetMode(EN_DBXTV_TotSonMode totsonmode, EN_DBXTV_TotVolMode totvolmode, EN_DBXTV_TotSurMode totsurmode,MS_U32 enable);
MS_U32 MDrv_ADVSOUND_GetInfo(AdvSound_GET_Type Type);

#ifdef __cplusplus
}
#endif

#endif //_DRVIPCHECK_H_