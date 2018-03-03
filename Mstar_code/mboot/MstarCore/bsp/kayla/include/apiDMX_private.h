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
// Copyright (c) 2013-2015 MStar Semiconductor, Inc.
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

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File name: apiDMX_private.h
//  Description: Demux  (DMX) API private header file
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _DMX_PRIV_H_
#define _DMX_PRIV_H_

#include "apiDMX.h"
#include "MsTypes.h"
#include "utopia_relation.h"

#ifdef __cplusplus
extern "C"
{
#endif



#define _MODULE_DMX_U1_U2_RELATION                                                                                                                              \
    URELATION(fpDMXInitLibRes,              (IOCTL_DMX_INIT_LIBRES)MApi_DMX_InitLibResource,                            MApi_DMX_InitLibResource)               \
    URELATION(fpDMXSetFWBuf,                (IOCTL_DMX_SET_FW)_MApi_DMX_SetFW,                                          MApi_DMX_SetFW)                         \
    URELATION(fpDMXSetFWMiuDataAddr,        (IOCTL_DMX_SET_FW_DATAADDR)_MApi_DMX_SetFwDataAddr,                         MApi_DMX_SetFwDataAddr)                 \
    URELATION(fpDMXSetHK,                   (IOCTL_DMX_SET_HK)_MApi_DMX_SetHK,                                          MApi_DMX_SetHK)                         \
    URELATION(fpDMXInit,                    (IOCTL_DMX_INIT)_MApi_DMX_Init,                                             MApi_DMX_Init)                          \
    URELATION(fpDMXTSPInit,                 (IOCTL_DMX_TSPINIT)_MApi_DMX_TSPInit,                                       MApi_DMX_TSPInit)                       \
    URELATION(fpDMXExit,                    (IOCTL_DMX_EXIT)_MApi_DMX_Exit,                                             MApi_DMX_Exit)                          \
    URELATION(fpDMXForceExit,               (IOCTL_DMX_FORCE_EXIT)_MApi_DMX_ForceExit,                                  MApi_DMX_ForceExit)                     \
    URELATION(fpDMXSuspend,                 (IOCTL_DMX_SUSPEND)_MApi_DMX_Suspend,                                       MApi_DMX_Suspend)                       \
    URELATION(fpDMXResume,                  (IOCTL_DMX_RESUME)_MApi_DMX_Resume,                                         MApi_DMX_Resume)                        \
    URELATION(fpDMXChkFwAlive,              (IOCTL_DMX_CHK_ALIVE)_MApi_DMX_ChkAlive,                                    MApi_DMX_ChkAlive)                      \
    URELATION(fpDMXReset,                   (IOCTL_DMX_RESET)_MApi_DMX_Reset,                                           MApi_DMX_Reset)                         \
    URELATION(fpDMXReleaseHwSemp,           (IOCTL_DMX_RELEASE_HWSEMP)_MApi_DMX_ReleaseSemaphone,                       MApi_DMX_ReleaseSemaphone)              \
    URELATION(fpDMXWProtectEnable,          (IOCTL_DMX_WPROTECT_EN)_MApi_DMX_WriteProtect_Enable,                       MApi_DMX_WriteProtect_Enable)           \
    URELATION(fpDMXOrzWProtectEnable,       (IOCTL_DMX_ORZWPROTECT_EN)_MApi_DMX_OrzWriteProtect_Enable,                 MApi_DMX_OrzWriteProtect_Enable)        \
    URELATION(fpDMXReadDropCount,           (IOCTL_DMX_READ_DROP_COUNT)_MApi_DMX_Read_DropPktCnt,                       MApi_DMX_Read_DropPktCnt)               \
    URELATION(fpDMXSetPowerState,           (IOCTL_DMX_SET_POWER_STATE)_MApi_DMX_SetPowerState,                         MApi_DMX_SetPowerState)                 \
                                                                                                                                                                \
    URELATION(fpDMXSetOwner,                (IOCTL_DMX_SET_OWNER)_MApi_DMX_SetOwner,                                    MApi_DMX_SetOwner)                      \
    URELATION(fpDMXGetCap,                  (IOCTL_DMX_GET_CAP)_MApi_DMX_GetCap,                                        MApi_DMX_GetCap)                        \
    URELATION(fpDMXGetCapEx,                (IOCTL_DMX_GET_CAP_EX)_MApi_DMX_GetCap_Ex,                                  MApi_DMX_GetCap_Ex)                     \
    URELATION(fpDMXParlInvert,              (IOCTL_DMX_PARL_INVERT)_MApi_DMX_Parl_Invert,                               MApi_DMX_Parl_Invert)                   \
    URELATION(fpDMXSetBurstLen,             (IOCTL_DMX_SET_BURSTLEN)_MApi_DMX_SetBurstLen,                              MApi_DMX_SetBurstLen)                   \
                                                                                                                                                                \
    URELATION(fpDMXFlowSet,                 (IOCTL_DMX_SET_FLOW)_MApi_DMX_FlowSet,                                      MApi_DMX_FlowSet)                       \
    URELATION(fpDMXPvrFlowSet,              (IOCTL_DMX_SET_PVRFLOW)_MApi_DMX_PVR_FlowSet,                               MApi_DMX_PVR_FlowSet)                   \
    URELATION(fpDMXGetFlowInputSts,         (IOCTL_DMX_GET_FLOWINPUT_STS)_MApi_DMX_Get_FlowInput_Status,                MApi_DMX_Get_FlowInput_Status)          \
    URELATION(fpDMXFlowEnable,              (IOCTL_DMX_FLOW_ENABLE)_MApi_DMX_FlowEnable,                                MApi_DMX_FlowEnable)                    \
    URELATION(fpDMXTsOutpadCfg,             (IOCTL_DMX_TSOUTPAD_CFG)_MApi_DMX_TsOutputPadCfg,                           MApi_DMX_TsOutputPadCfg)                \
    URELATION(fpDMXTsS2POutPhase,           (IOCTL_DMX_TSS2P_OUTPHASE)_MApi_DMX_TsS2POutputClkPhase,                    MApi_DMX_TsS2POutputClkPhase)           \
    URELATION(fpDMXFlowDscmbEng,            (IOCTL_DMX_FLOW_DSCMBENG)_MApi_DMX_Flow_DscmbEng,                           MApi_DMX_Flow_DscmbEng)                 \
    URELATION(fpDMXDropScmbPkt,             (IOCTL_DMX_DROP_SCMB_PKT)_MApi_DMX_DropScmbPkt,                             MApi_DMX_DropScmbPkt)                   \
                                                                                                                                                                \
    URELATION(fpDMX64bitModeEn,             (IOCTL_DMX_STC64_MODE_EN)_MApi_DMX_STC64_Mode_Enable,                       MApi_DMX_STC64_Mode_Enable)             \
    URELATION(fpDMXGetPcrEng,               (IOCTL_DMX_GET_PCR_ENG)_MApi_DMX_Pcr_Eng_Get,                               MApi_DMX_Pcr_Eng_Get)                   \
    URELATION(fpDMXGetStcEng,               (IOCTL_DMX_GET_STC_ENG)_MApi_DMX_Stc_Eng_Get,                               MApi_DMX_Stc_Eng_Get)                   \
    URELATION(fpDMXSetStcEng,               (IOCTL_DMX_SET_STC_ENG)_MApi_DMX_Stc_Eng_Set,                               MApi_DMX_Stc_Eng_Set)                   \
    URELATION(fpDMXStcUpdateCtrl,           (IOCTL_DMX_SET_STC_UPDATECTL)_MApi_DMX_STC_UpdateCtrl,                      MApi_DMX_STC_UpdateCtrl)                \
    URELATION(fpDMXSetStcOffset,            (IOCTL_DMX_SET_STC_OFFSET)_MApi_DMX_Stc_Eng_SetOffset,                      MApi_DMX_Stc_Eng_SetOffset)             \
    URELATION(fpDMXStcClkAdjust,            (IOCTL_DMX_SET_STC_CLK_ADJUST)_MApi_DMX_Stc_Clk_Adjust,                     MApi_DMX_Stc_Clk_Adjust)                \
    URELATION(fpDMXStcSel,                  (IOCTL_DMX_SEL_STC)_MApi_DMX_Stc_Select,                                    MApi_DMX_Stc_Select)                    \
                                                                                                                                                                \
    URELATION(fpDMXOpen,                    (IOCTL_DMX_OPEN)_MApi_DMX_Open,                                             MApi_DMX_Open)                          \
    URELATION(fpDMXClose,                   (IOCTL_DMX_CLOSE)_MApi_DMX_Close,                                           MApi_DMX_Close)                         \
    URELATION(fpDMXStart,                   (IOCTL_DMX_START)_MApi_DMX_Start,                                           MApi_DMX_Start)                         \
    URELATION(fpDMXStop,                    (IOCTL_DMX_STOP)_MApi_DMX_Stop,                                             MApi_DMX_Stop)                          \
    URELATION(fpDMXInfo,                    (IOCTL_DMX_INFO)_MApi_DMX_Info,                                             MApi_DMX_Info)                          \
    URELATION(fpDMXPid,                     (IOCTL_DMX_PID)_MApi_DMX_Pid,                                               MApi_DMX_Pid)                           \
    URELATION(fpDMXIsStart,                 (IOCTL_DMX_IS_START)_MApi_DMX_IsStart,                                      MApi_DMX_IsStart)                       \
    URELATION(fpDMXCopyData,                (IOCTL_DMX_COPY_DATA)_MApi_DMX_CopyData,                                    MApi_DMX_CopyData)                      \
    URELATION(fpDMXProc,                    (IOCTL_DMX_PROC)_MApi_DMX_Proc,                                             MApi_DMX_Proc)                          \
    URELATION(fpDMXChangeFltSrc,            (IOCTL_DMX_CHANGE_FLTSRC)_MApi_DMX_Change_FilterSource,                     MApi_DMX_Change_FilterSource)           \
    URELATION(fpDMXSwitchLiveFltSrc,        (IOCTL_DMX_SWITCH_LIVE_FLTSRC)_MApi_DMX_LiveSrcSwitch,                      MApi_DMX_LiveSrcSwitch)                 \
    URELATION(fpDMXGetOnwer,                (IOCTL_DMX_GET_OWNER)_MApi_DMX_GetOwner,                                    MApi_DMX_GetOwner)                      \
                                                                                                                                                                \
    URELATION(fpDMXGetFltScmbSts,           (IOCTL_DMX_GET_FLTSCMBSTS)_MApi_DMX_Get_FltScmbSts,                         MApi_DMX_Get_FltScmbSts)                \
    URELATION(fpDMXGetPesScmbSts,           (IOCTL_DMX_GET_PESSCMBSTS)_MApi_DMX_Get_PesScmbSts,                         MApi_DMX_Get_PesScmbSts)                \
    URELATION(fpDMXGetTsScmbSts,            (IOCTL_DMX_GET_TSSCMBSTS)_MApi_DMX_Get_TsScmbSts,                           MApi_DMX_Get_TsScmbSts)                 \
                                                                                                                                                                \
    URELATION(fpDMXSecReset,                (IOCTL_DMX_SEC_RESET)_MApi_DMX_SectReset,                                   MApi_DMX_SectReset)                     \
    URELATION(fpDMXSecSetReadAddr,          (IOCTL_DMX_SEC_SET_READADDR)_MApi_DMX_SectReadSet,                          MApi_DMX_SectReadSet)                   \
    URELATION(fpDMXSecGetReadAddr,          (IOCTL_DMX_SEC_GET_READADDR)_MApi_DMX_SectReadGet,                          MApi_DMX_SectReadGet)                   \
    URELATION(fpDMXSecGetWriteAddr,         (IOCTL_DMX_SEC_GET_WRITEADDR)_MApi_DMX_SectWriteGet,                        MApi_DMX_SectWriteGet)                  \
    URELATION(fpDMXSecGetStartAddr,         (IOCTL_DMX_SEC_GET_STARTADDR)_MApi_DMX_SectStartGet,                        MApi_DMX_SectStartGet)                  \
    URELATION(fpDMXSecGetEndAddr,           (IOCTL_DMX_SEC_GET_ENDADDR)_MApi_DMX_SectEndGet,                            MApi_DMX_SectEndGet)                    \
    URELATION(fpDMXSecSetPattern,           (IOCTL_DMX_SEC_SET_PATTERN)_MApi_DMX_SectPatternSet,                        MApi_DMX_SectPatternSet)                \
                                                                                                                                                                \
    URELATION(fpDMXGetTTXWrite,             (IOCTL_DMX_GET_TTX_WRITE)_MApi_DMX_TTX_WriteGet,                            MApi_DMX_TTX_WriteGet)                  \
    URELATION(fpDMXGetAccess,               (IOCTL_DMX_GET_ACCESS)_MApi_DMX_GetAccess,                                  MApi_DMX_GetAccess)                     \
    URELATION(fpDMXReleaseAccess,           (IOCTL_DMX_RELEASE_ACCESS)_MApi_DMX_ReleaseAccess,                          MApi_DMX_ReleaseAccess)                 \
                                                                                                                                                                \
    URELATION(fpDMXAVFifoReset,             (IOCTL_DMX_AVFIFO_RESET)_MApi_DMX_AVFifo_Reset,                             MApi_DMX_AVFifo_Reset)                  \
    URELATION(fpDMXAVFifoStatus,            (IOCTL_DMX_AVFIFO_STATUS)_MApi_DMX_AVFifo_Status,                           MApi_DMX_AVFifo_Status)                 \
    URELATION(fpDMXRemoveDupAVPkt,          (IOCTL_DMX_REMOVE_DUPAVFPKT)_MApi_DMX_RemoveDupAVPkt,                       MApi_DMX_RemoveDupAVPkt)                \
    URELATION(fpDMXRemoveDupAVFifoPkt,      (IOCTL_DMX_REMOVE_DUPAVFIFOPKT)_MApi_DMX_RemoveDupAVFifoPkt,                MApi_DMX_RemoveDupAVFifoPkt)            \
    URELATION(fpDMXAUBDModeEn,              (IOCTL_DMX_AUBD_MODE_EN)_MApi_DMX_AU_BD_Mode_Enable,                        MApi_DMX_AU_BD_Mode_Enable)             \
    URELATION(fpDMXSetPktMode,              (IOCTL_DMX_SET_PKTMODE)_MApi_DMX_SetPacketMode,                             MApi_DMX_SetPacketMode)                 \
    URELATION(fpDMXSetMerStrSyc,            (IOCTL_DMX_SET_MERSTR_SYNC)_MApi_DMX_SetMergeStrSyncByte,                   MApi_DMX_SetMergeStrSyncByte)           \
                                                                                                                                                                \
    URELATION(fpDMXFileSetPlayStamp,        (IOCTL_DMX_FILE_SET_PLAYSTAMP)_MApi_DMX_Filein_Eng_SetPlaybackStamp,        MApi_DMX_Filein_Eng_SetPlaybackStamp)   \
    URELATION(fpDMXFileGetPlayStamp,        (IOCTL_DMX_FILE_GET_PLAYSTAMP)_MApi_DMX_Filein_Eng_GetPlaybackStamp,        MApi_DMX_Filein_Eng_GetPlaybackStamp)   \
    URELATION(fpDMXFileTimestampEnable,     (IOCTL_DMX_FILE_TIMESTAMP_ENABLE)_MApi_DMX_Filein_Eng_PlaybackTimeStampEnable,   MApi_DMX_Filein_Eng_PlaybackTimeStampEnable)   \
    URELATION(fpDMXFileTimestampDisable,    (IOCTL_DMX_FILE_TIMESTAMP_DISABLE)_MApi_DMX_Filein_Eng_PlaybackTimeStampDisable, MApi_DMX_Filein_Eng_PlaybackTimeStampDisable)  \
                                                                                                                                                                \
    URELATION(fpDMXPvrEngOpen,              (IOCTL_DMX_PVR_ENG_OPEN)_MApi_DMX_Pvr_Eng_Open,                             MApi_DMX_Pvr_Eng_Open)                  \
    URELATION(fpDMXPvrEngClose,             (IOCTL_DMX_PVR_ENG_CLOSE)_MApi_DMX_Pvr_Eng_Close,                           MApi_DMX_Pvr_Eng_Close)                 \
    URELATION(fpDMXPvrEngPidOpen,           (IOCTL_DMX_PVR_ENG_PID_OPEN)_MApi_DMX_Pvr_Eng_Pid_Open,                     MApi_DMX_Pvr_Eng_Pid_Open)              \
    URELATION(fpDMXPvrEngPidClose,          (IOCTL_DMX_PVR_ENG_PID_CLOSE)_MApi_DMX_Pvr_Eng_Pid_Close,                   MApi_DMX_Pvr_Eng_Pid_Close)             \
    URELATION(fpDMXPvrEngStart,             (IOCTL_DMX_PVR_ENG_START)_MApi_DMX_Pvr_Eng_Start,                           MApi_DMX_Pvr_Eng_Start)                 \
    URELATION(fpDMXPvrEngStop,              (IOCTL_DMX_PVR_ENG_STOP)_MApi_DMX_Pvr_Eng_Stop,                             MApi_DMX_Pvr_Eng_Stop)                  \
    URELATION(fpDMXPvrEngGetWriteAddr,      (IOCTL_DMX_PVR_ENG_GET_WRITEADDR)_MApi_DMX_Pvr_Eng_WriteGet,                MApi_DMX_Pvr_Eng_WriteGet)              \
    URELATION(fpDMXPvrEngSetPktMode,        (IOCTL_DMX_PVR_ENG_SET_PKTMODE)_MApi_DMX_Pvr_Eng_SetPacketMode,             MApi_DMX_Pvr_Eng_SetPacketMode)         \
    URELATION(fpDMXPvrEngSetRecordStamp,    (IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP)_MApi_DMX_Pvr_Eng_SetRecordStamp,        MApi_DMX_Pvr_Eng_SetRecordStamp)        \
    URELATION(fpDMXPvrEngGetRecordStamp,    (IOCTL_DMX_PVR_ENG_GET_RECORDSTAMP)_MApi_DMX_Pvr_Eng_GetRecordStamp,        MApi_DMX_Pvr_Eng_GetRecordStamp)        \
    URELATION(fpDMXPvrEngMobfEn,            (IOCTL_DMX_PVR_ENG_MOBF_EN)_MApi_DMX_Pvr_Eng_MOBF_Enable,                   MApi_DMX_Pvr_Eng_MOBF_Enable)           \
    URELATION(fpDMXPvrEngSetRecordStampClk, (IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP_CLK)_MApi_DMX_Pvr_Eng_SetRecordStampClk, MApi_DMX_Pvr_Eng_SetRecordStampClk)     \
    URELATION(fpDMXPvrEngCBSize,            (IOCTL_DMX_PVR_ENG_CBSIZE)_MApi_DMX_Pvr_Eng_CallbackSize,                   MApi_DMX_Pvr_Eng_CallbackSize)          \
    URELATION(fpDMXPvrEngSetCaMode,         (IOCTL_DMX_PVR_ENG_SET_CAMODE)_MApi_DMX_Pvr_Eng_SetCaMode,                  MApi_DMX_Pvr_Eng_SetCaMode)             \
    URELATION(fpDMXPvrIsStart,              (IOCTL_DMX_PVR_ENG_IS_START)_MApi_DMX_Pvr_Eng_IsStart,                      MApi_DMX_Pvr_Eng_IsStart)               \
                                                                                                                                                                \
    URELATION(fpDMXFileEngSetPlayStampClk,  (IOCTL_DMX_FILE_ENG_SET_PLAYSTAMP_CLK)_MApi_DMX_Pvr_Eng_SetPlaybackStampClk,MApi_DMX_Pvr_Eng_SetPlaybackStampClk)   \
                                                                                                                                                                \
    URELATION(fpDMXPvrcaEngPidOpen,         (IOCTL_DMX_PVRCA_ENG_PID_OPEN)_MApi_DMX_PvrCA_Eng_Pid_Open,                 MApi_DMX_PvrCA_Eng_Pid_Open)            \
    URELATION(fpDMXPvrcaEngPidClose,        (IOCTL_DMX_PVRCA_ENG_PID_CLOSE)_MApi_DMX_PvrCA_Eng_Pid_Close,               MApi_DMX_PvrCA_Eng_Pid_Close)           \
    URELATION(fpDMXPvrcaEngStart,           (IOCTL_DMX_PVRCA_ENG_START)_MApi_DMX_PvrCA_Eng_Start,                       MApi_DMX_PvrCA_Eng_Start)               \
    URELATION(fpDMXPvrcaEngStop,            (IOCTL_DMX_PVRCA_ENG_STOP)_MApi_DMX_PvrCA_Eng_Stop,                         MApi_DMX_PvrCA_Eng_Stop)                \
                                                                                                                                                                \
    URELATION(fpDMXFileStart,               (IOCTL_DMX_FILE_START)_MApi_DMX_Filein_Eng_Start,                           MApi_DMX_Filein_Eng_Start)              \
    URELATION(fpDMXFileStop,                (IOCTL_DMX_FILE_STOP)_MApi_DMX_Filein_Eng_Stop,                             MApi_DMX_Filein_Eng_Stop)               \
    URELATION(fpDMXFileInfo,                (IOCTL_DMX_FILE_INFO)_MApi_DMX_Filein_Info,                                 MApi_DMX_Filein_Info)                   \
    URELATION(fpDMXFileEngInfo,             (IOCTL_DMX_FILE_ENG_INFO)_MApi_DMX_Filein_Eng_Info,                         MApi_DMX_Filein_Eng_Info)               \
    URELATION(fpDMXFilePause,               (IOCTL_DMX_FILE_PAUSE)_MApi_DMX_Filein_Eng_Pause,                           MApi_DMX_Filein_Eng_Pause)              \
    URELATION(fpDMXFileResume,              (IOCTL_DMX_FILE_RESUME)_MApi_DMX_Filein_Eng_Resume,                         MApi_DMX_Filein_Eng_Resume)             \
    URELATION(fpDMXFileIsIdle,              (IOCTL_DMX_FILE_IS_IDLE)_MApi_DMX_Filein_Eng_IsIdle,                        MApi_DMX_Filein_Eng_IsIdle)             \
    URELATION(fpDMXFileIsBusy,              (IOCTL_DMX_FILE_IS_BUSY)_MApi_DMX_Filein_Eng_IsBusy,                        MApi_DMX_Filein_Eng_IsBusy)             \
    URELATION(fpDMXFileIsPause,             (IOCTL_DMX_FILE_IS_PAUSE)_MApi_DMX_Filein_Eng_IsPause,                      MApi_DMX_Filein_Eng_IsPause)            \
    URELATION(fpDMXFileCmdQReset,           (IOCTL_DMX_FILE_CMDQ_RESET)_MApi_DMX_Filein_Eng_CMDQ_Reset,                 MApi_DMX_Filein_Eng_CMDQ_Reset)         \
    URELATION(fpDMXFileCmdQGetEmptyNum,     (IOCTL_DMX_FILE_CMDQ_GET_EMPTY_NUM)_MApi_DMX_Filein_Eng_CMDQ_GetEmptyNum,   MApi_DMX_Filein_Eng_CMDQ_GetEmptyNum)   \
    URELATION(fpDMXFileBypassFileTimeStamp, (IOCTL_DMX_FILE_BYPASS_FILE_TIMESTAMP)_MApi_DMX_Filein_Eng_BypassFileInTimeStamp, MApi_DMX_Filein_Eng_BypassFileInTimeStamp)\
    URELATION(fpDMXFileCmdQGetFifoWLevel,   (IOCTL_DMX_FILE_CMDQ_GET_FIFO_WLEVEL)_MApi_DMX_Filein_Eng_CMDQ_FIFOWriteLevel,    MApi_DMX_Filein_Eng_CMDQ_FIFOWriteLevel)  \
    URELATION(fpDMXFileGetFileTimestamp,    (IOCTL_DMX_FILE_GET_FILE_TIMESTAMP)_MApi_DMX_Filein_Eng_GetFileInTimeStamp, MApi_DMX_Filein_Eng_GetFileInTimeStamp) \
    URELATION(fpDMXFileGetReadAddr,         (IOCTL_DMX_FILE_GET_READADDR)_MApi_DMX_Filein_Eng_GetReadAddr,              MApi_DMX_Filein_Eng_GetReadAddr)        \
    URELATION(fpDMXFileMobfEn,              (IOCTL_DMX_FILE_MOBF_EN)_MApi_DMX_Filein_Eng_MOBF_Enable,                   MApi_DMX_Filein_Eng_MOBF_Enable)        \
                                                                                                                                                                \
    URELATION(fpDMXMMFIIsIdle,              (IOCTL_DMX_MMFI_IS_IDLE)_MApi_DMX_MMFI_Filein_IsIdle,                       MApi_DMX_MMFI_Filein_IsIdle)            \
    URELATION(fpDMXMMFIIsBusy,              (IOCTL_DMX_MMFI_IS_BUSY)_MApi_DMX_MMFI_Filein_IsBusy,                       MApi_DMX_MMFI_Filein_IsBusy)            \
    URELATION(fpDMXMMFICmdQReset,           (IOCTL_DMX_MMFI_CMDQ_RESET)_MApi_DMX_MMFI_Filein_CMDQ_Reset,                MApi_DMX_MMFI_Filein_CMDQ_Reset)        \
    URELATION(fpDMXMMFIGetEmptyNum,         (IOCTL_DMX_MMFI_CMDQ_Get_EMPTY_NUM)_MApi_DMX_MMFI_Filein_CMDQ_GetEmptyNum,  MApi_DMX_MMFI_Filein_CMDQ_GetEmptyNum)  \
    URELATION(fpDMXMMFIStart,               (IOCTL_DMX_MMFI_START)_MApi_DMX_MMFI_Filein_Start,                          MApi_DMX_MMFI_Filein_Start)             \
    URELATION(fpDMXMMFIGetFileTimestamp,    (IOCTL_DMX_MMFI_GET_FILE_TIMESTAMP)_MApi_DMX_MMFI_GetFileInTimeStamp,       MApi_DMX_MMFI_GetFileInTimeStamp)       \
                                                                                                                                                                \
    URELATION(fpDMXMMFIPidOpen,             (IOCTL_DMX_MMFI_PID_OPEN)_MApi_DMX_MMFI_Pid_Open,                           MApi_DMX_MMFI_Pid_Open)                 \
    URELATION(fpDMXMMFIPidClose,            (IOCTL_DMX_MMFI_PID_CLOSE)_MApi_DMX_MMFI_Pid_Close,                         MApi_DMX_MMFI_Pid_Close)                \
    URELATION(fpDMXMMFIGetFifoLevel,        (IOCTL_DMX_MMFI_CMDQ_GET_FIFOLEVEL)_MApi_DMX_MMFI_Filein_CMDQ_FIFOWriteLevel,   MApi_DMX_MMFI_Filein_CMDQ_FIFOWriteLevel)   \
    URELATION(fpDMXMMFISetPlayTimestamp,    (IOCTL_DMX_MMFI_SET_PLAYTIMESTAMP)_MApi_DMX_MMFI_SetPlaybackTimeStamp,      MApi_DMX_MMFI_SetPlaybackTimeStamp)     \
    URELATION(fpDMXMMFIGetPlayTimestamp,    (IOCTL_DMX_MMFI_GET_PLAYTIMESTAMP)_MApi_DMX_MMFI_GetPlaybackTimeStamp,      MApi_DMX_MMFI_GetPlaybackTimeStamp)     \
    URELATION(fpDMXMMFISetTimestampClk,     (IOCTL_DMX_MMFI_SET_TIMESTAMPCLK)_MApi_DMX_MMFI_TimeStampClk,               MApi_DMX_MMFI_TimeStampClk)             \
    URELATION(fpDMXMMFIInfo,                (IOCTL_DMX_MMFI_INFO)_MApi_DMX_MMFI_Filein_Info,                            MApi_DMX_MMFI_Filein_Info)              \
    URELATION(fpDMXMMFIBypassStamp,         (IOCTL_DMX_MMFI_BYPASSS_STAMP)_MApi_DMX_MMFI_Filein_BypassTimeStamp,        MApi_DMX_MMFI_Filein_BypassTimeStamp)   \
    URELATION(fpDMXMMFIRemoveDupAVPkt,      (IOCTL_DMX_MMFI_REMOVE_DUPAVPKT)_MApi_DMX_MMFI_RemoveDupAVPkt,              MApi_DMX_MMFI_RemoveDupAVPkt)           \
    URELATION(fpDMXMMFIMobfEn,              (IOCTL_DMX_MMFI_MOBF_EN)_MApi_DMX_MMFI_MOBF_Enable,                         MApi_DMX_MMFI_MOBF_Enable)              \
    URELATION(fpDMXMMFITimestampEn,         (IOCTL_DMX_MMFI_TIMESTAMP_EN)_MApi_DMX_MMFI_TimeStampEnable,                MApi_DMX_MMFI_TimeStampEnable)          \
    URELATION(fpDMXMMFITimestampDisable,    (IOCTL_DMX_MMFI_TIMESTAMP_DISABLE)_MApi_DMX_MMFI_TimeStampDisable,          MApi_DMX_MMFI_TimeStampDisable)         \
                                                                                                                                                                \
    URELATION(fpDMXTsoFileInfo,             (IOCTL_DMX_TSO_FI_INFO)_MApi_DMX_TSO_Filein_Info,                           MApi_DMX_TSO_Filein_Info)               \
    URELATION(fpDMXTsoFileIsIdle,           (IOCTL_DMX_TSO_FI_ISIDLE)_MApi_DMX_TSO_Filein_IsIdle,                       MApi_DMX_TSO_Filein_IsIdle)             \
    URELATION(fpDMXTsoFileGetCmdQEmptyNum,  (IOCTL_DMX_TSO_FI_CMDQ_GET_EMPTYNUM)_MApi_DMX_TSO_Filein_CMDQ_GetEmptyNum,  MApi_DMX_TSO_Filein_CMDQ_GetEmptyNum)   \
    URELATION(fpDMXTsoFileGetCmdQReset,     (IOCTL_DMX_TSO_FI_CMDQ_RESET)_MApi_DMX_TSO_Filein_CMDQ_Reset,               MApi_DMX_TSO_Filein_CMDQ_Reset)         \
    URELATION(fpDMXTsoFileStart,            (IOCTL_DMX_TSO_FI_START)_MApi_DMX_TSO_Filein_Start,                         MApi_DMX_TSO_Filein_Start)              \
    URELATION(fpDMXTsoFileStop,             (IOCTL_DMX_TSO_FI_STOP)_MApi_DMX_TSO_Filein_Stop,                           MApi_DMX_TSO_Filein_Stop)               \
    URELATION(fpDMXTsoFileSetPlayStamp,     (IOCTL_DMX_TSO_FI_SET_PLAYTIMESTAMP)_MApi_DMX_TSO_SetPlaybackTimeStamp,     MApi_DMX_TSO_SetPlaybackTimeStamp)      \
    URELATION(fpDMXTsoFileGetPlayStamp,     (IOCTL_DMX_TSO_FI_GET_PLAYSTAMP)_MApi_DMX_TSO_GetPlaybackStamp,             MApi_DMX_TSO_GetPlaybackStamp)          \
    URELATION(fpDMXTsoFileGetTimeStamp,     (IOCTL_DMX_TSO_FI_GETSTAMP)_MApi_DMX_TSO_GetFileInTimeStamp,                MApi_DMX_TSO_GetFileInTimeStamp)        \
    URELATION(fpDMXTsoFileBypassStamp,      (IOCTL_DMX_TSO_FI_BYPASS_STAMP)_MApi_DMX_TSO_BypassFileInTimeStamp,         MApi_DMX_TSO_BypassFileInTimeStamp)     \
    URELATION(fpDMXTsoFileTimeStampEnable,  (IOCTL_DMX_TSO_FI_STAMP_EN)_MApi_DMX_TSO_TimeStampEnable,                   MApi_DMX_TSO_TimeStampEnable)           \
    URELATION(fpDMXTsoFileTimeStampDisable, (IOCTL_DMX_TSO_FI_STAMP_DISABLE)_MApi_DMX_TSO_TimeStampDisable,             MApi_DMX_TSO_TimeStampDisable)          \
    URELATION(fpDMXTsoSetOutClk,            (IOCTL_DMX_TSO_SET_OUTCLK)_MApi_DMX_TSO_SetOutClk,                          MApi_DMX_TSO_SetOutClk)                 \
    URELATION(fpDMXTsoOutputEn,             (IOCTL_DMX_TSO_OUTPUT_EN)_MApi_DMX_TSO_OutputEnable,                        MApi_DMX_TSO_OutputEnable)              \
    URELATION(fpDMXTsoLocStrId,             (IOCTL_DMX_TSO_LOCSTRID)_MApi_DMX_TSO_LocalStreamId,                        MApi_DMX_TSO_LocalStreamId)             \
    URELATION(fpDMXTsoSvqBufSet,            (IOCTL_DMX_TSO_SVQBUF_SET)_MApi_DMX_TSO_SVQBuf_Set,                         MApi_DMX_TSO_SVQBuf_Set)                \
    URELATION(fpDMXTsoFlowInputCfg,         (IOCTL_DMX_TSO_FLOW_INPUTCFG)_MApi_DMX_TSO_Flow_InputCfg,                   MApi_DMX_TSO_Flow_InputCfg)             \
    URELATION(fpDMXTsoFlowOutputCfg,        (IOCTL_DMX_TSO_FLOW_OUTPUTCFG)_MApi_DMX_TSO_Flow_OutputCfg,                 MApi_DMX_TSO_Flow_OutputCfg)            \
    URELATION(fpDMXTsoPidOpen,              (IOCTL_DMX_TSO_PID_OPEN)_MApi_DMX_TSO_Pid_Open,                             MApi_DMX_TSO_Pid_Open)                  \
    URELATION(fpDMXTsoPidClose,             (IOCTL_DMX_TSO_PID_CLOSE)_MApi_DMX_TSO_Pid_Close,                           MApi_DMX_TSO_Pid_Close)                 \
                                                                                                                                                                \
    URELATION(fpDMXSetDbgLevel,             (IOCTL_DMX_SET_DBGLEVEL)_MApi_DMX_SetDbgLevel,                              MApi_DMX_SetDbgLevel)                   \
    URELATION(fpDMXGetFwVer,                (IOCTL_DMX_GET_FWVER)_MApi_TSP_Get_FW_VER,                                  MApi_TSP_Get_FW_VER)                    \
    URELATION(fpDMXGetLibVer,               (IOCTL_DMX_GET_LIBVER)_MApi_DMX_GetLibVer,                                  MApi_DMX_GetLibVer)                     \
    URELATION(fpDMXGetDisConCnt,            (IOCTL_DMX_GET_DISCONCNT)_MApi_DMX_Get_DisContiCnt,                         MApi_DMX_Get_DisContiCnt)               \
    URELATION(fpDMXGetDropPktCnt,           (IOCTL_DMX_GET_DROPPKTCNT)_MApi_DMX_Get_DropPktCnt,                         MApi_DMX_Get_DropPktCnt)                \
    URELATION(fpDMXGetLockPktCnt,           (IOCTL_DMX_GET_LOCKPKTCNT)_MApi_DMX_Get_LockPktCnt,                         MApi_DMX_Get_LockPktCnt)                \
    URELATION(fpDMXGetAVPktCnt,             (IOCTL_DMX_GET_AVPKTCNT)_MApi_DMX_Get_AVPktCnt,                             MApi_DMX_Get_AVPktCnt)                  \
    URELATION(fpDMXGetSecTeiPktCnt,         (IOCTL_DMX_GET_SECTEI_PKTCNT)_MApi_DMX_Get_SecTEI_PktCount,                 MApi_DMX_Get_SecTEI_PktCount)           \
    URELATION(fpDMXResetSecTeiPktCnt,       (IOCTL_DMX_RESET_SECTEI_PKTCNT)_MApi_DMX_Reset_SecTEI_PktCount,             MApi_DMX_Reset_SecTEI_PktCount)         \
    URELATION(fpDMXGetSecDisConPktCnt,      (IOCTL_DMX_GET_SECDISCON_PKTCNT)_MApi_DMX_Get_SecDisCont_PktCount,          MApi_DMX_Get_SecDisCont_PktCount)       \
    URELATION(fpDMXResetSecDisContPktCnt,   (IOCTL_DMX_RESET_SECDISCONT_PKTCNT)_MApi_DMX_Reset_SecDisCont_PktCount,     MApi_DMX_Reset_SecDisCont_PktCount)     \
                                                                                                                                                                \
    URELATION(fpDMXCmdRun,                  (IOCTL_DMX_CMD_RUN)_MApi_DMX_CMD_Run,                                       MApi_DMX_CMD_Run)                       \
                                                                                                                                                                \
    URELATION(fpDMXFQSetFltRushPass,        (IOCTL_DMX_FQ_SET_FLT_RUSH_PASS)_MApi_DMX_FQ_SetFltRushPass,                MApi_DMX_FQ_SetFltRushPass)             \
    URELATION(fpDMXFQInit,                  (IOCTL_DMX_FQ_INIT)_MApi_DMX_FQ_Init,                                       MApi_DMX_FQ_Init)                       \
    URELATION(fpDMXFQExit,                  (IOCTL_DMX_FQ_EXIT)_MApi_DMX_FQ_Exit,                                       MApi_DMX_FQ_Exit)                       \
    URELATION(fpDMXFQRushEn,                (IOCTL_DMX_FQ_RUSH_EN)_MApi_DMX_FQ_RushEnable,                              MApi_DMX_FQ_RushEnable)                 \
    URELATION(fpDMXFQSkipRushData,          (IOCTL_DMX_FQ_SKIP_RUSH_DATA)_MApi_DMX_FQ_SkipRushData,                     MApi_DMX_FQ_SkipRushData)               \
    URELATION(fpDMXFQConfigure,             (IOCTL_DMX_FQ_CONFIGURE)_MApi_DMX_FQ_Configure,                             MApi_DMX_FQ_Configure)               \
                                                                                                                                                                \
    URELATION(fpDMXMStrSyncBy,              (IOCTL_DMX_MSTR_SYNCBY)_MApi_DMX_MStr_SyncByte,                             MApi_DMX_MStr_SyncByte)                 \
                                                                                                                                                                \
    /*URELATION(fpDMXWaitTspSig,            (IOCTL_DMX_WAIT_TSPSIG)_MApi_DMX_Wait_TspIoSignal,                          NULL)                               */  \
                                                                                                                                                                \
    URELATION(fpDMXGetIntCnt,               (IOCTL_DMX_GET_INTCNT)_MApi_DMX_Get_Intr_Count,                             MApi_DMX_Get_Intr_Count)                \
    URELATION(fpDMXDropEn,                  (IOCTL_DMX_DROP_EN)_MApi_DMX_Drop_Enable,                                   MApi_DMX_Drop_Enable)                   \
    URELATION(fpDMXTeiRmErrPkt,             (IOCTL_DMX_TEI_RM_ERRPKT)_MApi_DMX_TEI_RemoveErrorPkt,                      MApi_DMX_TEI_RemoveErrorPkt)            \
    URELATION(fpDMXSetFwDbgParam,           (IOCTL_DMX_SET_FWDBGPARAM)_MApi_DMX_SetFwDbgParam,                          MApi_DMX_SetFwDbgParam)                 \
    URELATION(fpDMXPvrMobfEn,               (IOCTL_DMX_PVR_MOBF_EN)_MApi_DMX_Pvr_MOBF_Enable,                           MApi_DMX_Pvr_MOBF_Enable)               \
    URELATION(fpDMXGetDbgportInfo,          (IOCTL_DMX_GET_DBGPORT_INFO)_MApi_DMX_GetDbgPortInfo,                       MApi_DMX_GetDbgPortInfo)                \
    URELATION(fpDMXOpenMultiFlt,            (IOCTL_DMX_OPEN_MULTI_FLT)_MApi_DMX_Open_MultiFlt,                          MApi_DMX_Open_MultiFlt)                 \
                                                                                                                                                                \
    URELATION(fpDMXFilePvrPidOpen,          (IOCTL_DMX_FILE_PVR_PID_OPEN)_MApi_DMX_Filein_Pvr_Eng_Pid_Open,             MApi_DMX_Filein_Pvr_Eng_Pid_Open)       \
    URELATION(fpDMXFilePvrPidClose,         (IOCTL_DMX_FILE_PVR_PID_CLOSE)_MApi_DMX_Filein_Pvr_Eng_Pid_Close,           MApi_DMX_Filein_Pvr_Eng_Pid_Close)      \
    URELATION(fpDMXFilePvrStart,            (IOCTL_DMX_FILE_PVR_START)_MApi_DMX_Filein_Pvr_Eng_Start,                   MApi_DMX_Filein_Pvr_Eng_Start)          \
    URELATION(fpDMXFilePvrStop,             (IOCTL_DMX_FILE_PVR_STOP)_MApi_DMX_Filein_Pvr_Eng_Stop,                     MApi_DMX_Filein_Pvr_Eng_Stop)           \
    URELATION(fpDMXPvrPause,                (IOCTL_DMX_PVR_PAUSE)_MApi_DMX_Pvr_Eng_Pause,                               MApi_DMX_Pvr_Eng_Pause)                 \
    URELATION(fpDMXPvrPid,                  (IOCTL_DMX_PVR_PID)_MApi_DMX_Pvr_Eng_Pid,                                   MApi_DMX_Pvr_Eng_Pid)                   \
                                                                                                                                                                \
    URELATION(fpDMXResAllocate,             (IOCTL_DMX_RES_ALLOCATE)_MApi_DMX_ResAllocate,                              MApi_DMX_ResAllocate)                   \
    URELATION(fpDMXResFree,                 (IOCTL_DMX_RES_FREE)_MApi_DMX_ResFree,                                      MApi_DMX_ResFree)                       \
    URELATION(fpDMXPcrGetMapStc,            (IOCTL_DMX_PCR_GET_MAP_STC)_MApi_DMX_Pcr_Get_MapSTC,                        MApi_DMX_Pcr_Get_MapSTC)


// General API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_INIT_LIBRES)(void*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_FW)(MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_FW_DATAADDR)(MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_HK)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_INIT)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSPINIT)(DMX_TSPParam*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_EXIT)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FORCE_EXIT)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SUSPEND)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RESUME)(MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_CHK_ALIVE)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RESET)(void);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RELEASE_HWSEMP)(void);
typedef void              (*IOCTL_DMX_WPROTECT_EN)(MS_BOOL, MS_PHY*, MS_PHY*);
typedef void              (*IOCTL_DMX_ORZWPROTECT_EN)(MS_BOOL, MS_PHY, MS_PHY);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_READ_DROP_COUNT)(MS_U16*, MS_U16*);
typedef MS_U32            (*IOCTL_DMX_SET_POWER_STATE)(EN_POWER_MODE, MS_PHY, MS_U32);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_OWNER)(MS_U8, MS_U8, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_CAP)(DMX_QUERY_TYPE, void*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_CAP_EX)(char*, MS_S32, void*, MS_S32*);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_PARL_INVERT)(DMX_FLOW, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_BURSTLEN)(DMX_BURSTTYPE);

//Flow Control
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_FLOW)(DMX_FLOW, DMX_FLOW_INPUT, MS_BOOL, MS_BOOL, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_PVRFLOW)(DMX_PVR_ENG, DMX_TSIF, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_FLOWINPUT_STS)(DMX_FLOW, DMX_FLOW_INPUT*, MS_BOOL*, MS_BOOL*, MS_BOOL*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FLOW_ENABLE)(DMX_FLOW, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSOUTPAD_CFG)(DMX_FLOW_OUTPUT_PAD, DMX_FLOW_INPUT, MS_BOOL, MS_U32, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSS2P_OUTPHASE)(MS_U16, MS_BOOL, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FLOW_DSCMBENG)(DMX_TSIF, MS_U32*, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_DROP_SCMB_PKT)(DMX_FILTER_TYPE, MS_BOOL);

//STC API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_STC64_MODE_EN)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_PCR_ENG)(MS_U8, MS_U32*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_STC_ENG)(MS_U8, MS_U32*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_STC_ENG)(MS_U8, MS_U32, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_STC_UPDATECTL)(MS_U8, eStcUpdateCtrlMode);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_STC_OFFSET)(MS_U32, MS_U32, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_STC_CLK_ADJUST)(MS_U32, MS_BOOL, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEL_STC)(DMX_FILTER_TYPE, MS_U32);


//Filter API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_OPEN)(DMX_FILTER_TYPE, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_CLOSE)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_START)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_STOP)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_INFO)(MS_U8, DMX_Flt_info*, DMX_FILTER_TYPE*, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PID)(MS_U8, MS_U16*, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_IS_START)(MS_U8, MS_BOOL*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_COPY_DATA)(MS_U8, MS_U8*, MS_U32, MS_U32*, MS_U32*, DMX_CheckCb);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PROC)(MS_U8, DMX_EVENT*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_CHANGE_FLTSRC)(MS_U8, DMX_FILTER_TYPE);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SWITCH_LIVE_FLTSRC)(DMX_FILTER_TYPE);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_OWNER)(MS_U8, MS_BOOL*);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_FLTSCMBSTS)(DMX_FILTER_TYPE, MS_U32, MS_U32, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_PESSCMBSTS)(MS_U8, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_TSSCMBSTS)(MS_U8, MS_U8*);

// Section API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_RESET)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_SET_READADDR)(MS_U8, MS_PHY);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_GET_READADDR)(MS_U8, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_GET_WRITEADDR)(MS_U8, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_GET_STARTADDR)(MS_U8, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_GET_ENDADDR)(MS_U8, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SEC_SET_PATTERN)(MS_U8, MS_U8*, MS_U8*, MS_U8*, MS_U32);

//TTX API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_TTX_WRITE)(MS_U8, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_ACCESS)(MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RELEASE_ACCESS)(void);

// AVFIFO control
typedef DMX_FILTER_STATUS (*IOCTL_DMX_AVFIFO_RESET)(DMX_FILTER_TYPE, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_AVFIFO_STATUS)(DMX_FILTER_TYPE, DMX_FIFO_STATUS*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_REMOVE_DUPAVFPKT)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_REMOVE_DUPAVFIFOPKT)(DMX_FILTER_TYPE, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_AUBD_MODE_EN)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_PKTMODE)(DMX_FLOW, DMX_PacketMode);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_MERSTR_SYNC)(MS_U32, MS_U8);

//PVR Playback API (Old)
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_SET_PLAYSTAMP)(DMX_FILEIN_PATH, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_GET_PLAYSTAMP)(DMX_FILEIN_PATH, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_TIMESTAMP_ENABLE)(DMX_FILEIN_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_TIMESTAMP_DISABLE)(DMX_FILEIN_PATH);

// PVR Engine API  (New)
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_OPEN)(DMX_PVR_ENG, DMX_Pvr_info*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_CLOSE)(DMX_PVR_ENG);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_PAUSE)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_PID_OPEN)(DMX_PVR_ENG, MS_U32, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_PID_CLOSE)(DMX_PVR_ENG, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_START)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_STOP)(DMX_PVR_ENG);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_GET_WRITEADDR)(DMX_PVR_ENG, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_SET_PKTMODE)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP)(DMX_PVR_ENG, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_GET_RECORDSTAMP)(DMX_PVR_ENG, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_MOBF_EN)(MS_U8 , MS_BOOL, MS_U32, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP_CLK)(DMX_PVR_ENG, DMX_TimeStamp_Clk);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_CBSIZE)(DMX_PVR_ENG, MS_U32*, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_SET_CAMODE)(DMX_PVR_ENG, DMX_CA_PVRMODE, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_ENG_IS_START)(DMX_PVR_ENG, MS_BOOL*);

//PVR Playback API (New)
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_ENG_SET_PLAYSTAMP_CLK)(MS_U8, DMX_TimeStamp_Clk);

//PVR CA Engine API (New)
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVRCA_ENG_PID_OPEN)(DMX_PVR_ENG, MS_U32, MS_U8*, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVRCA_ENG_PID_CLOSE)(DMX_PVR_ENG, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVRCA_ENG_START)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVRCA_ENG_STOP)(DMX_PVR_ENG);

// File-in API (Old)
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_START)(DMX_FILEIN_PATH, DMX_FILEIN_DST, MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_STOP)(DMX_FILEIN_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_INFO)(DMX_Filein_info*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_ENG_INFO)(DMX_FILEIN_PATH, DMX_Filein_info*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_PAUSE)(DMX_FILEIN_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_RESUME)(DMX_FILEIN_PATH);
typedef MS_BOOL           (*IOCTL_DMX_FILE_IS_IDLE)(DMX_FILEIN_PATH);
typedef MS_BOOL           (*IOCTL_DMX_FILE_IS_BUSY)(DMX_FILEIN_PATH);
typedef MS_BOOL           (*IOCTL_DMX_FILE_IS_PAUSE)(DMX_FILEIN_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_CMDQ_RESET)(DMX_FILEIN_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_CMDQ_GET_EMPTY_NUM)(DMX_FILEIN_PATH, MS_U32*);
typedef void              (*IOCTL_DMX_FILE_BYPASS_FILE_TIMESTAMP)(DMX_FILEIN_PATH, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_CMDQ_GET_FIFO_WLEVEL)(DMX_FILEIN_PATH, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_GET_FILE_TIMESTAMP)(DMX_FILEIN_PATH, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_GET_READADDR)(DMX_FILEIN_PATH, MS_PHY*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_MOBF_EN)(DMX_FILEIN_PATH, MS_BOOL, MS_U32);

//MMFI & MINITSP API
typedef MS_BOOL           (*IOCTL_DMX_MMFI_IS_IDLE)(DMX_MMFI_PATH);
typedef MS_BOOL           (*IOCTL_DMX_MMFI_IS_BUSY)(DMX_MMFI_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_CMDQ_RESET)(DMX_MMFI_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_CMDQ_Get_EMPTY_NUM)(DMX_MMFI_PATH, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_START)(DMX_MMFI_DST, MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_GET_FILE_TIMESTAMP)(DMX_MMFI_PATH, MS_U32*);

//MMFI  (MMFI Only) API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_PID_OPEN)(DMX_MMFI_FLTTYPE, MS_U16, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_PID_CLOSE)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_CMDQ_GET_FIFOLEVEL)(DMX_MMFI_PATH, MS_U8*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_SET_PLAYTIMESTAMP)(DMX_MMFI_PATH, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_GET_PLAYTIMESTAMP)(DMX_MMFI_PATH, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_SET_TIMESTAMPCLK)(DMX_MMFI_PATH, DMX_TimeStamp_Clk);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_INFO)(DMX_MMFI_PATH, DMX_Filein_info*);
typedef void              (*IOCTL_DMX_MMFI_BYPASSS_STAMP)(DMX_MMFI_PATH, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_TIMESTAMP_EN)(DMX_MMFI_PATH);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_TIMESTAMP_DISABLE)(DMX_MMFI_PATH);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_REMOVE_DUPAVPKT)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MMFI_MOBF_EN)(DMX_MMFI_PATH, MS_BOOL, MS_U32);

//TSO API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_INFO)(MS_U8, DMX_Filein_info*);
typedef MS_BOOL           (*IOCTL_DMX_TSO_FI_ISIDLE)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_CMDQ_GET_EMPTYNUM)(MS_U8, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_CMDQ_RESET)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_START)(MS_U8, MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_STOP)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_SET_PLAYTIMESTAMP)(MS_U8, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_GET_PLAYSTAMP)(MS_U8, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_GETSTAMP)(MS_U8, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_BYPASS_STAMP)(MS_U8, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_STAMP_EN)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FI_STAMP_DISABLE)(MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_SET_OUTCLK)(MS_U8, DMX_TSO_OutClk, DMX_TSO_OutClkSrc, MS_U16, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_OUTPUT_EN)(MS_U8, MS_BOOL);

//TSO2 API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_LOCSTRID)(MS_U8, DMX_TSIF, MS_U8*, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_SVQBUF_SET)(MS_U8, MS_PHY, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FLOW_INPUTCFG)(DMX_TSO_InputCfg*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_FLOW_OUTPUTCFG)(DMX_TSO_OutputCfg*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_PID_OPEN)(MS_U8, DMX_TSIF, MS_U16, MS_U16*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TSO_PID_CLOSE)(MS_U8, MS_U16);

//Debug API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_DBGLEVEL)(DMX_DBGMSG_LEVEL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_FWVER)(MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_LIBVER)(const MSIF_Version **);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_DISCONCNT)(DMX_DisContiCnt_info*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_DROPPKTCNT)(DMX_DropPktCnt_info*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_LOCKPKTCNT)(DMX_LockPktCnt_info*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_AVPKTCNT)(DMX_AVPktCnt_info*, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_SECTEI_PKTCNT)(DMX_FILTER_TYPE, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RESET_SECTEI_PKTCNT)(DMX_FILTER_TYPE);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_SECDISCON_PKTCNT)(MS_U32, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RESET_SECDISCONT_PKTCNT)(MS_U32);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_CMD_RUN)(MS_U32, MS_U32, MS_U32, void*);

//FQ
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_SET_FLT_RUSH_PASS)(MS_U8, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_INIT)(MS_U32, DMX_FQ_Info*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_EXIT)(MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_RUSH_EN)(MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_SKIP_RUSH_DATA)(MS_U32,DMX_FQ_SkipPath);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FQ_CONFIGURE)(DMX_FQ_Cfg*);

//Merge Stream API
typedef DMX_FILTER_STATUS (*IOCTL_DMX_MSTR_SYNCBY)(DMX_TSIF, MS_U8, MS_U8*, MS_BOOL);

//utopia 2K only
typedef DMX_FILTER_STATUS (*IOCTL_DMX_WAIT_TSPSIG)(DMX_TSP_IOSIGNAL*);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_INTCNT)(MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_DROP_EN)(MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_TEI_RM_ERRPKT)(DMX_TEI_RmPktType, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_SET_FWDBGPARAM)(MS_PHY, MS_U32, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_MOBF_EN)(MS_BOOL, MS_U32, MS_U32);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_GET_DBGPORT_INFO)(MS_U32, MS_U32*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_OPEN_MULTI_FLT)(DMX_FILTER_TYPE, MS_U8*, MS_U8);

typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_PVR_PID_OPEN)(DMX_PVR_ENG, MS_U32, MS_U8*, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_PVR_PID_CLOSE)(DMX_PVR_ENG, MS_U8);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_PVR_START)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_FILE_PVR_STOP)(DMX_PVR_ENG);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_PAUSE)(DMX_PVR_ENG, MS_BOOL);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PVR_PID)(DMX_PVR_ENG, MS_U8 ,MS_U32*, MS_BOOL);

// DMX_RES_ALLOC_EN
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RES_ALLOCATE)(DMX_RES_TYPE, void*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_RES_FREE)(DMX_RES_TYPE, void*);
typedef DMX_FILTER_STATUS (*IOCTL_DMX_PCR_GET_MAP_STC)(MS_U32, MS_U32*);


typedef struct _DMX_INSTANT_PRIVATE
{
    IOCTL_DMX_INIT_LIBRES                   fpDMXInitLibRes;
    IOCTL_DMX_SET_FW                        fpDMXSetFWBuf;
    IOCTL_DMX_SET_FW_DATAADDR               fpDMXSetFWMiuDataAddr;
    IOCTL_DMX_SET_HK                        fpDMXSetHK;
    IOCTL_DMX_INIT                          fpDMXInit;
    IOCTL_DMX_TSPINIT                       fpDMXTSPInit;
    IOCTL_DMX_EXIT                          fpDMXExit;
    IOCTL_DMX_FORCE_EXIT                    fpDMXForceExit;
    IOCTL_DMX_SUSPEND                       fpDMXSuspend;
    IOCTL_DMX_RESUME                        fpDMXResume;
    IOCTL_DMX_CHK_ALIVE                     fpDMXChkFwAlive;
    IOCTL_DMX_RESET                         fpDMXReset;
    IOCTL_DMX_RELEASE_HWSEMP                fpDMXReleaseHwSemp;
    IOCTL_DMX_WPROTECT_EN                   fpDMXWProtectEnable;
    IOCTL_DMX_ORZWPROTECT_EN                fpDMXOrzWProtectEnable;
    IOCTL_DMX_READ_DROP_COUNT               fpDMXReadDropCount;
    IOCTL_DMX_SET_POWER_STATE               fpDMXSetPowerState;

    IOCTL_DMX_SET_OWNER                     fpDMXSetOwner;
    IOCTL_DMX_GET_CAP                       fpDMXGetCap;
    IOCTL_DMX_GET_CAP_EX                    fpDMXGetCapEx;
    IOCTL_DMX_PARL_INVERT                   fpDMXParlInvert;
    IOCTL_DMX_SET_BURSTLEN                  fpDMXSetBurstLen;

    IOCTL_DMX_SET_FLOW                      fpDMXFlowSet;
    IOCTL_DMX_SET_PVRFLOW                   fpDMXPvrFlowSet;
    IOCTL_DMX_GET_FLOWINPUT_STS             fpDMXGetFlowInputSts;
    IOCTL_DMX_FLOW_ENABLE                   fpDMXFlowEnable;
    IOCTL_DMX_TSOUTPAD_CFG                  fpDMXTsOutpadCfg;
    IOCTL_DMX_TSS2P_OUTPHASE                fpDMXTsS2POutPhase;
    IOCTL_DMX_FLOW_DSCMBENG                 fpDMXFlowDscmbEng;
    IOCTL_DMX_DROP_SCMB_PKT                 fpDMXDropScmbPkt;

    IOCTL_DMX_STC64_MODE_EN                 fpDMX64bitModeEn;
    IOCTL_DMX_GET_PCR_ENG                   fpDMXGetPcrEng;
    IOCTL_DMX_GET_STC_ENG                   fpDMXGetStcEng;
    IOCTL_DMX_SET_STC_ENG                   fpDMXSetStcEng;
    IOCTL_DMX_SET_STC_UPDATECTL             fpDMXStcUpdateCtrl;
    IOCTL_DMX_SET_STC_OFFSET                fpDMXSetStcOffset;
    IOCTL_DMX_SET_STC_CLK_ADJUST            fpDMXStcClkAdjust;
    IOCTL_DMX_SEL_STC                       fpDMXStcSel;

    IOCTL_DMX_OPEN                          fpDMXOpen;
    IOCTL_DMX_CLOSE                         fpDMXClose;
    IOCTL_DMX_START                         fpDMXStart;
    IOCTL_DMX_STOP                          fpDMXStop;
    IOCTL_DMX_INFO                          fpDMXInfo;
    IOCTL_DMX_PID                           fpDMXPid;
    IOCTL_DMX_IS_START                      fpDMXIsStart;
    IOCTL_DMX_COPY_DATA                     fpDMXCopyData;
    IOCTL_DMX_PROC                          fpDMXProc;
    IOCTL_DMX_CHANGE_FLTSRC                 fpDMXChangeFltSrc;
    IOCTL_DMX_SWITCH_LIVE_FLTSRC            fpDMXSwitchLiveFltSrc;
    IOCTL_DMX_GET_OWNER                     fpDMXGetOnwer;

    IOCTL_DMX_GET_FLTSCMBSTS                fpDMXGetFltScmbSts;
    IOCTL_DMX_GET_PESSCMBSTS                fpDMXGetPesScmbSts;
    IOCTL_DMX_GET_TSSCMBSTS                 fpDMXGetTsScmbSts;

    IOCTL_DMX_SEC_RESET                     fpDMXSecReset;
    IOCTL_DMX_SEC_SET_READADDR              fpDMXSecSetReadAddr;
    IOCTL_DMX_SEC_GET_READADDR              fpDMXSecGetReadAddr;
    IOCTL_DMX_SEC_GET_WRITEADDR             fpDMXSecGetWriteAddr;
    IOCTL_DMX_SEC_GET_STARTADDR             fpDMXSecGetStartAddr;
    IOCTL_DMX_SEC_GET_ENDADDR               fpDMXSecGetEndAddr;
    IOCTL_DMX_SEC_SET_PATTERN               fpDMXSecSetPattern;

    IOCTL_DMX_GET_TTX_WRITE                 fpDMXGetTTXWrite;
    IOCTL_DMX_GET_ACCESS                    fpDMXGetAccess;
    IOCTL_DMX_RELEASE_ACCESS                fpDMXReleaseAccess;

    IOCTL_DMX_AVFIFO_RESET                  fpDMXAVFifoReset;
    IOCTL_DMX_AVFIFO_STATUS                 fpDMXAVFifoStatus;
    IOCTL_DMX_REMOVE_DUPAVFPKT              fpDMXRemoveDupAVPkt;
    IOCTL_DMX_REMOVE_DUPAVFIFOPKT           fpDMXRemoveDupAVFifoPkt;
    IOCTL_DMX_AUBD_MODE_EN                  fpDMXAUBDModeEn;
    IOCTL_DMX_SET_PKTMODE                   fpDMXSetPktMode;
    IOCTL_DMX_SET_MERSTR_SYNC               fpDMXSetMerStrSyc;

    IOCTL_DMX_FILE_SET_PLAYSTAMP            fpDMXFileSetPlayStamp;
    IOCTL_DMX_FILE_GET_PLAYSTAMP            fpDMXFileGetPlayStamp;
    IOCTL_DMX_FILE_TIMESTAMP_ENABLE         fpDMXFileTimestampEnable;
    IOCTL_DMX_FILE_TIMESTAMP_DISABLE        fpDMXFileTimestampDisable;

    IOCTL_DMX_PVR_ENG_OPEN                  fpDMXPvrEngOpen;
    IOCTL_DMX_PVR_ENG_CLOSE                 fpDMXPvrEngClose;
    IOCTL_DMX_PVR_ENG_PAUSE                 fpDMXPvrEngPause;
    IOCTL_DMX_PVR_ENG_PID_OPEN              fpDMXPvrEngPidOpen;
    IOCTL_DMX_PVR_ENG_PID_CLOSE             fpDMXPvrEngPidClose;
    IOCTL_DMX_PVR_ENG_START                 fpDMXPvrEngStart;
    IOCTL_DMX_PVR_ENG_STOP                  fpDMXPvrEngStop;
    IOCTL_DMX_PVR_ENG_GET_WRITEADDR         fpDMXPvrEngGetWriteAddr;
    IOCTL_DMX_PVR_ENG_SET_PKTMODE           fpDMXPvrEngSetPktMode;
    IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP       fpDMXPvrEngSetRecordStamp;
    IOCTL_DMX_PVR_ENG_GET_RECORDSTAMP       fpDMXPvrEngGetRecordStamp;
    IOCTL_DMX_PVR_ENG_MOBF_EN               fpDMXPvrEngMobfEn;
    IOCTL_DMX_PVR_ENG_SET_RECORDSTAMP_CLK   fpDMXPvrEngSetRecordStampClk;
    IOCTL_DMX_PVR_ENG_CBSIZE                fpDMXPvrEngCBSize;
    IOCTL_DMX_PVR_ENG_SET_CAMODE            fpDMXPvrEngSetCaMode;
    IOCTL_DMX_PVR_ENG_IS_START              fpDMXPvrIsStart;

    IOCTL_DMX_FILE_ENG_SET_PLAYSTAMP_CLK    fpDMXFileEngSetPlayStampClk;

    IOCTL_DMX_PVRCA_ENG_PID_OPEN            fpDMXPvrcaEngPidOpen;
    IOCTL_DMX_PVRCA_ENG_PID_CLOSE           fpDMXPvrcaEngPidClose;
    IOCTL_DMX_PVRCA_ENG_START               fpDMXPvrcaEngStart;
    IOCTL_DMX_PVRCA_ENG_STOP                fpDMXPvrcaEngStop;

    IOCTL_DMX_FILE_START                    fpDMXFileStart;
    IOCTL_DMX_FILE_STOP                     fpDMXFileStop;
    IOCTL_DMX_FILE_INFO                     fpDMXFileInfo;
    IOCTL_DMX_FILE_ENG_INFO                 fpDMXFileEngInfo;
    IOCTL_DMX_FILE_PAUSE                    fpDMXFilePause;
    IOCTL_DMX_FILE_RESUME                   fpDMXFileResume;
    IOCTL_DMX_FILE_IS_IDLE                  fpDMXFileIsIdle;
    IOCTL_DMX_FILE_IS_BUSY                  fpDMXFileIsBusy;
    IOCTL_DMX_FILE_IS_PAUSE                 fpDMXFileIsPause;
    IOCTL_DMX_FILE_CMDQ_RESET               fpDMXFileCmdQReset;
    IOCTL_DMX_FILE_CMDQ_GET_EMPTY_NUM       fpDMXFileCmdQGetEmptyNum;
    IOCTL_DMX_FILE_BYPASS_FILE_TIMESTAMP    fpDMXFileBypassFileTimeStamp;
    IOCTL_DMX_FILE_CMDQ_GET_FIFO_WLEVEL     fpDMXFileCmdQGetFifoWLevel;
    IOCTL_DMX_FILE_GET_FILE_TIMESTAMP       fpDMXFileGetFileTimestamp;
    IOCTL_DMX_FILE_GET_READADDR             fpDMXFileGetReadAddr;
    IOCTL_DMX_FILE_MOBF_EN                  fpDMXFileMobfEn;

    IOCTL_DMX_MMFI_IS_IDLE                  fpDMXMMFIIsIdle;
    IOCTL_DMX_MMFI_IS_BUSY                  fpDMXMMFIIsBusy;
    IOCTL_DMX_MMFI_CMDQ_RESET               fpDMXMMFICmdQReset;
    IOCTL_DMX_MMFI_CMDQ_Get_EMPTY_NUM       fpDMXMMFIGetEmptyNum;
    IOCTL_DMX_MMFI_START                    fpDMXMMFIStart;
    IOCTL_DMX_MMFI_GET_FILE_TIMESTAMP       fpDMXMMFIGetFileTimestamp;

    IOCTL_DMX_MMFI_PID_OPEN                 fpDMXMMFIPidOpen;
    IOCTL_DMX_MMFI_PID_CLOSE                fpDMXMMFIPidClose;
    IOCTL_DMX_MMFI_CMDQ_GET_FIFOLEVEL       fpDMXMMFIGetFifoLevel;
    IOCTL_DMX_MMFI_SET_PLAYTIMESTAMP        fpDMXMMFISetPlayTimestamp;
    IOCTL_DMX_MMFI_GET_PLAYTIMESTAMP        fpDMXMMFIGetPlayTimestamp;
    IOCTL_DMX_MMFI_SET_TIMESTAMPCLK         fpDMXMMFISetTimestampClk;
    IOCTL_DMX_MMFI_INFO                     fpDMXMMFIInfo;
    IOCTL_DMX_MMFI_BYPASSS_STAMP            fpDMXMMFIBypassStamp;
    IOCTL_DMX_MMFI_REMOVE_DUPAVPKT          fpDMXMMFIRemoveDupAVPkt;
    IOCTL_DMX_MMFI_MOBF_EN                  fpDMXMMFIMobfEn;
    IOCTL_DMX_MMFI_TIMESTAMP_EN             fpDMXMMFITimestampEn;
    IOCTL_DMX_MMFI_TIMESTAMP_DISABLE        fpDMXMMFITimestampDisable;

    IOCTL_DMX_TSO_FI_INFO                   fpDMXTsoFileInfo;
    IOCTL_DMX_TSO_FI_ISIDLE                 fpDMXTsoFileIsIdle;
    IOCTL_DMX_TSO_FI_CMDQ_GET_EMPTYNUM      fpDMXTsoFileGetCmdQEmptyNum;
    IOCTL_DMX_TSO_FI_CMDQ_RESET             fpDMXTsoFileGetCmdQReset;
    IOCTL_DMX_TSO_FI_START                  fpDMXTsoFileStart;
    IOCTL_DMX_TSO_FI_STOP                   fpDMXTsoFileStop;
    IOCTL_DMX_TSO_FI_SET_PLAYTIMESTAMP      fpDMXTsoFileSetPlayStamp;
    IOCTL_DMX_TSO_FI_GET_PLAYSTAMP          fpDMXTsoFileGetPlayStamp;
    IOCTL_DMX_TSO_FI_GETSTAMP               fpDMXTsoFileGetTimeStamp;
    IOCTL_DMX_TSO_FI_BYPASS_STAMP           fpDMXTsoFileBypassStamp;
    IOCTL_DMX_TSO_FI_STAMP_EN               fpDMXTsoFileTimeStampEnable;
    IOCTL_DMX_TSO_FI_STAMP_DISABLE          fpDMXTsoFileTimeStampDisable;
    IOCTL_DMX_TSO_SET_OUTCLK                fpDMXTsoSetOutClk;
    IOCTL_DMX_TSO_OUTPUT_EN                 fpDMXTsoOutputEn;
    IOCTL_DMX_TSO_LOCSTRID                  fpDMXTsoLocStrId;
    IOCTL_DMX_TSO_SVQBUF_SET                fpDMXTsoSvqBufSet;
    IOCTL_DMX_TSO_FLOW_INPUTCFG             fpDMXTsoFlowInputCfg;
    IOCTL_DMX_TSO_FLOW_OUTPUTCFG            fpDMXTsoFlowOutputCfg;
    IOCTL_DMX_TSO_PID_OPEN                  fpDMXTsoPidOpen;
    IOCTL_DMX_TSO_PID_CLOSE                 fpDMXTsoPidClose;

    IOCTL_DMX_SET_DBGLEVEL                  fpDMXSetDbgLevel;
    IOCTL_DMX_GET_FWVER                     fpDMXGetFwVer;
    IOCTL_DMX_GET_LIBVER                    fpDMXGetLibVer;
    IOCTL_DMX_GET_DISCONCNT                 fpDMXGetDisConCnt;
    IOCTL_DMX_GET_DROPPKTCNT                fpDMXGetDropPktCnt;
    IOCTL_DMX_GET_LOCKPKTCNT                fpDMXGetLockPktCnt;
    IOCTL_DMX_GET_AVPKTCNT                  fpDMXGetAVPktCnt;
    IOCTL_DMX_GET_SECTEI_PKTCNT             fpDMXGetSecTeiPktCnt;
    IOCTL_DMX_RESET_SECTEI_PKTCNT           fpDMXResetSecTeiPktCnt;
    IOCTL_DMX_GET_SECDISCON_PKTCNT          fpDMXGetSecDisConPktCnt;
    IOCTL_DMX_RESET_SECDISCONT_PKTCNT       fpDMXResetSecDisContPktCnt;

    IOCTL_DMX_CMD_RUN                       fpDMXCmdRun;

    IOCTL_DMX_FQ_SET_FLT_RUSH_PASS          fpDMXFQSetFltRushPass;
    IOCTL_DMX_FQ_INIT                       fpDMXFQInit;
    IOCTL_DMX_FQ_EXIT                       fpDMXFQExit;
    IOCTL_DMX_FQ_RUSH_EN                    fpDMXFQRushEn;
    IOCTL_DMX_FQ_SKIP_RUSH_DATA             fpDMXFQSkipRushData;
    IOCTL_DMX_FQ_CONFIGURE                  fpDMXFQConfigure;

    IOCTL_DMX_MSTR_SYNCBY                   fpDMXMStrSyncBy;

    IOCTL_DMX_WAIT_TSPSIG                   fpDMXWaitTspSig;

    IOCTL_DMX_GET_INTCNT                    fpDMXGetIntCnt;
    IOCTL_DMX_DROP_EN                       fpDMXDropEn;
    IOCTL_DMX_TEI_RM_ERRPKT                 fpDMXTeiRmErrPkt;
    IOCTL_DMX_SET_FWDBGPARAM                fpDMXSetFwDbgParam;
    IOCTL_DMX_PVR_MOBF_EN                   fpDMXPvrMobfEn;
    IOCTL_DMX_GET_DBGPORT_INFO              fpDMXGetDbgportInfo;
    IOCTL_DMX_OPEN_MULTI_FLT                fpDMXOpenMultiFlt;

    IOCTL_DMX_FILE_PVR_PID_OPEN             fpDMXFilePvrPidOpen;
    IOCTL_DMX_FILE_PVR_PID_CLOSE            fpDMXFilePvrPidClose;
    IOCTL_DMX_FILE_PVR_START                fpDMXFilePvrStart;
    IOCTL_DMX_FILE_PVR_STOP                 fpDMXFilePvrStop;
    IOCTL_DMX_PVR_PAUSE                     fpDMXPvrPause;
    IOCTL_DMX_PVR_PID                       fpDMXPvrPid;

    IOCTL_DMX_RES_ALLOCATE                  fpDMXResAllocate;
    IOCTL_DMX_RES_FREE                      fpDMXResFree;
    IOCTL_DMX_PCR_GET_MAP_STC               fpDMXPcrGetMapStc;

}DMX_INSTANT_PRIVATE;


void    DMXRegisterToUtopia(FUtopiaOpen ModuleType);
MS_U32  DMXOpen(void** pInstance, void* pAttribute);
MS_U32  DMXClose(void* pInstance);
MS_U32  DMXIoctl(void* pInstance, MS_U32 u32Cmd, void* pArgs);


//----------------------
// Utopia 1.0 body API
//----------------------
#ifndef UTOPIA_STRIP
DMX_FILTER_STATUS _MApi_DMX_SetFW(MS_PHY pFwAddr, MS_U32 u32FwSize);
DMX_FILTER_STATUS _MApi_DMX_Init(void);
DMX_FILTER_STATUS _MApi_DMX_TSPInit(DMX_TSPParam *param);
DMX_FILTER_STATUS _MApi_DMX_Exit(void);
DMX_FILTER_STATUS _MApi_DMX_Reset(void);
DMX_FILTER_STATUS _MApi_DMX_ForceExit(void);
DMX_FILTER_STATUS _MApi_DMX_Resume(MS_PHY phyFWAddr, MS_U32 u32FWSize);
DMX_FILTER_STATUS _MApi_DMX_Suspend(void);
DMX_FILTER_STATUS _MApi_DMX_SetHK(MS_BOOL bIsHK);
DMX_FILTER_STATUS _MApi_DMX_ReleaseSemaphone(void);
DMX_FILTER_STATUS _MApi_DMX_Get_FlowInput_Status(DMX_FLOW DmxFlow, DMX_FLOW_INPUT *pDmxFlowInput, MS_BOOL *pbClkInv, MS_BOOL *pbExtSync, MS_BOOL *pbParallel);
DMX_FILTER_STATUS _MApi_DMX_FlowSet(DMX_FLOW DmxFlow, DMX_FLOW_INPUT DmxFlowInput, MS_BOOL bClkInv, MS_BOOL bExtSync, MS_BOOL bParallel);
DMX_FILTER_STATUS _MApi_DMX_PVR_FlowSet(DMX_PVR_ENG Eng, DMX_TSIF ePvrSrcTSIf, MS_BOOL bDscmbRec);
DMX_FILTER_STATUS _MApi_DMX_Open(DMX_FILTER_TYPE DmxFltType, MS_U8* pu8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Close(MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Start(MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Stop(MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_IsStart(MS_U8 u8DmxId, MS_BOOL* pbEnable);
DMX_FILTER_STATUS _MApi_DMX_Get_FltScmbSts(DMX_FILTER_TYPE FltSrc, MS_U32 u32FltGroupId, MS_U32 PidFltId, MS_U32 *pu32ScmbSts);
DMX_FILTER_STATUS _MApi_DMX_Get_PesScmbSts(MS_U8 u8DmxId, MS_U8* pu8scmb);
DMX_FILTER_STATUS _MApi_DMX_Get_TsScmbSts(MS_U8 u8DmxId, MS_U8* pu8ScmSts);
DMX_FILTER_STATUS _MApi_DMX_ChkAlive(void);
DMX_FILTER_STATUS _MApi_DMX_Info(MS_U8 u8DmxId, DMX_Flt_info* pDmxFltInfo, DMX_FILTER_TYPE* pDmxFltType, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_Pid(MS_U8 u8DmxId, MS_U16* pu16Pid, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_SectPatternSet(MS_U8 u8DmxId, MS_U8* pPattern, MS_U8* pMask, MS_U8 *pu8NotMask, MS_U32 MatchSize);
DMX_FILTER_STATUS _MApi_DMX_SectReset(MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_SectReadSet(MS_U8 u8DmxId, MS_PHY Read);
DMX_FILTER_STATUS _MApi_DMX_SectReadGet(MS_U8 u8DmxId, MS_PHY* pRead);
DMX_FILTER_STATUS _MApi_DMX_SectWriteGet(MS_U8 u8DmxId, MS_PHY* pWrite);
DMX_FILTER_STATUS _MApi_DMX_SectStartGet(MS_U8 u8DmxId, MS_PHY* pStart);
DMX_FILTER_STATUS _MApi_DMX_SectEndGet(MS_U8 u8DmxId, MS_PHY* pEnd);
DMX_FILTER_STATUS _MApi_DMX_SetFwDataAddr(MS_PHY phyDataAddr, MS_U32 u32size);
DMX_FILTER_STATUS _MApi_DMX_TTX_WriteGet(MS_U8 u8DmxId, MS_PHY* pWrite);
DMX_FILTER_STATUS _MApi_DMX_Pvr_SetPlaybackStamp(MS_U32 u32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Pvr_GetPlaybackStamp(MS_U32* pu32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Pvr_TimeStampEnable(void);
DMX_FILTER_STATUS _MApi_DMX_Pvr_TimeStampDisable(void);
DMX_FILTER_STATUS _MApi_DMX_PvrCA_Eng_Pid_Open(DMX_PVR_ENG Eng, MS_U32 Pid, MS_U8* pu8DmxId, MS_U8 u8ShareKeyType);
DMX_FILTER_STATUS _MApi_DMX_PvrCA_Eng_Pid_Close(DMX_PVR_ENG Eng, MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_PvrCA_Eng_Start(DMX_PVR_ENG Eng, MS_BOOL bPvrAll);
DMX_FILTER_STATUS _MApi_DMX_PvrCA_Eng_Stop(DMX_PVR_ENG Eng);
DMX_FILTER_STATUS _MApi_DMX_Filein_Info(DMX_Filein_info *pFileinInfo);
DMX_FILTER_STATUS _MApi_DMX_Filein_Start(DMX_FILEIN_DST Dst, MS_PHY pBuf, MS_U32 u32BufSize);
DMX_FILTER_STATUS _MApi_DMX_Filein_Stop(void);
DMX_FILTER_STATUS _MApi_DMX_Filein_Pause(void);
DMX_FILTER_STATUS _MApi_DMX_Filein_Resume(void);
DMX_FILTER_STATUS _MApi_DMX_Filein_CMDQ_Reset(void);
DMX_FILTER_STATUS _MApi_DMX_Filein_CMDQ_GetEmptyNum(MS_U32 *pu32EmptySlot);
DMX_FILTER_STATUS _MApi_DMX_Filein_CMDQ_FIFOWriteLevel(MS_U8 *pu8CmdQStatus);
MS_BOOL           _MApi_DMX_Filein_IsIdle(void);
MS_BOOL           _MApi_DMX_Filein_IsBusy(void);
MS_BOOL           _MApi_DMX_Filein_IsPause(void);
DMX_FILTER_STATUS _MApi_DMX_Stc_Eng_Get(MS_U8 u8Eng, MS_U32* pu32Stc32, MS_U32* pu32Stc);
DMX_FILTER_STATUS _MApi_DMX_Stc_Eng_Set(MS_U8 u8Eng, MS_U32 u32Stc32, MS_U32 u32Stc);
DMX_FILTER_STATUS _MApi_DMX_STC_UpdateCtrl(MS_U8 u8Eng, eStcUpdateCtrlMode eMode);
DMX_FILTER_STATUS _MApi_DMX_Stc_Eng_SetOffset(MS_U32 u32Eng, MS_U32 u32Offset, MS_BOOL bAdd);
DMX_FILTER_STATUS _MApi_DMX_Stc_Clk_Adjust(MS_U32 u32EngId, MS_BOOL bUpClk, MS_U32 u32Percentage);
DMX_FILTER_STATUS _MApi_DMX_Stc_Select(DMX_FILTER_TYPE eFltSrc, MS_U32 u32StcEng);
DMX_FILTER_STATUS _MApi_DMX_Pcr_Eng_Get(MS_U8 u8Eng, MS_U32* pu32Pcr32, MS_U32* pu32Pcr);
DMX_FILTER_STATUS _MApi_DMX_Proc(MS_U8 u8DmxId, DMX_EVENT* pEvent);
DMX_FILTER_STATUS _MApi_DMX_Parl_Invert(DMX_FLOW DmxFlow, MS_BOOL bInvert);
DMX_FILTER_STATUS _MApi_DMX_CopyData(MS_U8 u8DmxId, MS_U8* pu8Buf, MS_U32 u32BufSize, MS_U32* pu32ActualSize, MS_U32* pu32RmnSize, DMX_CheckCb pfCheckCB);
void              _MApi_DMX_WriteProtect_Enable(MS_BOOL bEnable, MS_PHY* pphyStartAddr, MS_PHY* pphyEndAddr);
void              _MApi_DMX_OrzWriteProtect_Enable(MS_BOOL bEnable, MS_PHY phyStartAddr, MS_PHY phyEndAddr);
DMX_FILTER_STATUS _MApi_DMX_FlowEnable(DMX_FLOW DmxFlow, MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_Read_DropPktCnt(MS_U16* pu16ADropCnt, MS_U16* pu16VDropCnt);
DMX_FILTER_STATUS _MApi_DMX_SetOwner(MS_U8 u8DmxIdStart, MS_U8 u8DmxIdEnd, MS_BOOL bOwner);
DMX_FILTER_STATUS _MApi_DMX_GetOwner(MS_U8 u8DmxId, MS_BOOL* pbOwner);
DMX_FILTER_STATUS _MApi_DMX_GetAccess(MS_U32 u32Try);
DMX_FILTER_STATUS _MApi_DMX_ReleaseAccess(void);
DMX_FILTER_STATUS _MApi_DMX_AVFifo_Reset(DMX_FILTER_TYPE DmxFltType, MS_BOOL bReset);
DMX_FILTER_STATUS _MApi_DMX_AVFifo_Status(DMX_FILTER_TYPE DmxFltType, DMX_FIFO_STATUS* u32FifoLevel);
DMX_FILTER_STATUS _MApi_DMX_GetLibVer(const MSIF_Version **ppVersion);
DMX_FILTER_STATUS _MApi_DMX_GetCap(DMX_QUERY_TYPE DmxQueryType, void* pOutput);
DMX_FILTER_STATUS _MApi_DMX_GetCap_Ex(char* pstrQueryType, MS_S32 s32Strlen, void* pOutput, MS_S32* ps32OutSize);
DMX_FILTER_STATUS _MApi_DMX_SetBurstLen(DMX_BURSTTYPE BurstType);
DMX_FILTER_STATUS _MApi_DMX_GetFileInTimeStamp(MS_U32 *pu32FileInTS);
DMX_FILTER_STATUS _MApi_DMX_Filein_GetReadAddr(MS_PHY* pphyRead);
void              _MApi_DMX_BypassFileInTimeStamp(MS_BOOL bbypass);
DMX_FILTER_STATUS _MApi_TSP_Get_FW_VER(MS_U32* u32FWVer);
DMX_FILTER_STATUS _MApi_DMX_RemoveDupAVPkt(MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_RemoveDupAVFifoPkt(DMX_FILTER_TYPE DmxFltType, MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_SetPacketMode(DMX_FLOW DmxFlow, DMX_PacketMode ePktMode);
DMX_FILTER_STATUS _MApi_DMX_SetMergeStrSyncByte(MS_U32 u32SrcID, MS_U8 u8SyncByte);
DMX_FILTER_STATUS _MApi_DMX_Change_FilterSource(MS_U8 u8DmxId, DMX_FILTER_TYPE DmxFltSrcType);
DMX_FILTER_STATUS _MApi_DMX_SetDbgLevel(DMX_DBGMSG_LEVEL level);
DMX_FILTER_STATUS _MApi_DMX_STC64_Mode_Enable(MS_BOOL bEnable);
MS_BOOL           _MApi_DMX_MMFI_Filein_IsIdle(DMX_MMFI_PATH ePath);
MS_BOOL           _MApi_DMX_MMFI_Filein_IsBusy(DMX_MMFI_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Filein_CMDQ_Reset(DMX_MMFI_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Filein_CMDQ_GetEmptyNum(DMX_MMFI_PATH ePath, MS_U32 *pu32EmptySlot);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Filein_Start(DMX_MMFI_DST eDst, MS_PHY pBuf, MS_U32 u32BufSize);
DMX_FILTER_STATUS _MApi_DMX_MMFI_GetFileInTimeStamp(DMX_MMFI_PATH ePath, MS_U32 *pu32FileInTS);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Pid_Open(DMX_MMFI_FLTTYPE flttype, MS_U16 u16Pid, MS_U8* pu8DmxId);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Pid_Close(MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_MMFI_Filein_CMDQ_FIFOWriteLevel(DMX_MMFI_PATH ePath, MS_U8 *pu8CmdQStatus);
DMX_FILTER_STATUS _MApi_DMX_MMFI_SetPlaybackTimeStamp(DMX_MMFI_PATH ePath, MS_U32 u32pcr2);
DMX_FILTER_STATUS _MApi_DMX_MMFI_GetPlaybackTimeStamp(DMX_MMFI_PATH ePath, MS_U32 *pu32pcr2);
DMX_FILTER_STATUS _MApi_DMX_MMFI_TimeStampClk(DMX_MMFI_PATH ePath, DMX_TimeStamp_Clk eClk);
DMX_FILTER_STATUS _MApi_DMX_MMFI_RemoveDupAVPkt(MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_MMFI_MOBF_Enable(DMX_MMFI_PATH ePath, MS_BOOL bEnable, MS_U32 u32key);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_MOBF_Enable(MS_U8 u8Eng, MS_BOOL bEnable, MS_U32 u32key0, MS_U32 u32key1);
DMX_FILTER_STATUS _MApi_DMX_Filein_MOBF_Enable(MS_BOOL bEnable, MS_U32 u32key);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Open(DMX_PVR_ENG Eng ,DMX_Pvr_info* pPvrInfo);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Close(DMX_PVR_ENG Eng );
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Pid_Open(DMX_PVR_ENG Eng ,MS_U32 Pid, MS_U8* pu8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Pid_Close(DMX_PVR_ENG Eng ,MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Start(DMX_PVR_ENG Eng, MS_BOOL bPvrAll);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Stop(DMX_PVR_ENG Eng);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_WriteGet(DMX_PVR_ENG Eng ,MS_PHY* pphyWrite);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_SetPacketMode(DMX_PVR_ENG Eng ,MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_SetRecordStamp(DMX_PVR_ENG Eng ,MS_U32 u32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_GetRecordStamp(DMX_PVR_ENG Eng ,MS_U32* pu32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_SetPlaybackStampClk(MS_U8 u8Eng, DMX_TimeStamp_Clk eClkSrc);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_SetRecordStampClk(DMX_PVR_ENG Eng, DMX_TimeStamp_Clk eClkSrc);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_CallbackSize(DMX_PVR_ENG Eng, MS_U32* pu32CallbackSize, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_SetCaMode(DMX_PVR_ENG Eng, DMX_CA_PVRMODE eCaMode, MS_BOOL bspsEnable);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_IsStart(DMX_PVR_ENG Eng, MS_BOOL *pbIsStart);
DMX_FILTER_STATUS _MApi_DMX_TSO_Filein_Info(MS_U8 u8Eng, DMX_Filein_info *pFileinInfo);
MS_BOOL           _MApi_DMX_TSO_Filein_IsIdle(MS_U8 u8Eng);
DMX_FILTER_STATUS _MApi_DMX_TSO_Filein_CMDQ_GetEmptyNum(MS_U8 u8Eng, MS_U32 *pu32EmptySlot);
DMX_FILTER_STATUS _MApi_DMX_TSO_Filein_CMDQ_Reset(MS_U8 u8Eng);
DMX_FILTER_STATUS _MApi_DMX_TSO_Filein_Start(MS_U8 u8Eng, MS_PHY pBuf, MS_U32 u32BufSize);
DMX_FILTER_STATUS _MApi_DMX_TSO_Filein_Stop(MS_U8 u8Eng);
DMX_FILTER_STATUS _MApi_DMX_TSO_SetPlaybackTimeStamp(MS_U8 u8Eng, MS_U32 u32Stamp);
DMX_FILTER_STATUS _MApi_DMX_TSO_GetPlaybackStamp(MS_U8 u8Eng, MS_U32* pu32Stamp);
DMX_FILTER_STATUS _MApi_DMX_TSO_GetFileInTimeStamp(MS_U8 u8Eng, MS_U32 *pu32Stamp);
DMX_FILTER_STATUS _MApi_DMX_TSO_BypassFileInTimeStamp(MS_U8 u8Eng, MS_BOOL bbypass);
DMX_FILTER_STATUS _MApi_DMX_TSO_TimeStampEnable(MS_U8 u8Eng);
DMX_FILTER_STATUS _MApi_DMX_TSO_TimeStampDisable(MS_U8 u8Eng);
DMX_FILTER_STATUS _MApi_DMX_TSO_SetOutClk(MS_U8 u8Eng, DMX_TSO_OutClk eTsOutClk, DMX_TSO_OutClkSrc eTsOutClkSrc, MS_U16 u16DivNum, MS_BOOL bClkInv);
DMX_FILTER_STATUS _MApi_DMX_TSO_OutputEnable(MS_U8 u8Eng, MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_TSO_LocalStreamId(MS_U8 u8Eng, DMX_TSIF eIf, MS_U8* pu8StrId, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_TSO_SVQBuf_Set(MS_U8 u8Eng, MS_PHY phyAddr, MS_U32 u32BufSize);
DMX_FILTER_STATUS _MApi_DMX_TSO_Flow_InputCfg(DMX_TSO_InputCfg* pstInputCfg);
DMX_FILTER_STATUS _MApi_DMX_TSO_Flow_OutputCfg(DMX_TSO_OutputCfg* pstOutputCfg);
DMX_FILTER_STATUS _MApi_DMX_TSO_Pid_Open(MS_U8 u8Eng, DMX_TSIF eTSOInSrc, MS_U16 u16Pid, MS_U16* pu16DmxId);
DMX_FILTER_STATUS _MApi_DMX_TSO_Pid_Close(MS_U8 u8Eng, MS_U16 u16DmxId);

DMX_FILTER_STATUS _MApi_DMX_LiveSrcSwitch(DMX_FILTER_TYPE TgtFlow);
DMX_FILTER_STATUS _MApi_DMX_AU_BD_Mode_Enable(MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_CMD_Run(MS_U32 u32Cmd, MS_U32 u32Config, MS_U32 u32DataNum, void *pData);
MS_U32            _MApi_DMX_SetPowerState(EN_POWER_MODE u16PowerState, MS_PHY phyFWAddr, MS_U32 u32FWSize);
DMX_FILTER_STATUS _MApi_DMX_Get_DisContiCnt(DMX_DisContiCnt_info* pDmxInfo, MS_U32* pu32Cnt);
DMX_FILTER_STATUS _MApi_DMX_Get_DropPktCnt(DMX_DropPktCnt_info* pDmxInfo, MS_U32* pu32Cnt);
DMX_FILTER_STATUS _MApi_DMX_Get_LockPktCnt(DMX_LockPktCnt_info* pDmxInfo, MS_U32* pu32Cnt);
DMX_FILTER_STATUS _MApi_DMX_Get_AVPktCnt(DMX_AVPktCnt_info* DmxInfo, MS_U32* pu32Cnt);
DMX_FILTER_STATUS _MApi_DMX_Get_SecTEI_PktCount(DMX_FILTER_TYPE FltSrc, MS_U32* pu32PktCnt);
DMX_FILTER_STATUS _MApi_DMX_Reset_SecTEI_PktCount(DMX_FILTER_TYPE FltSrc);
DMX_FILTER_STATUS _MApi_DMX_Get_SecDisCont_PktCount(MS_U32 u32DmxID, MS_U32* pu32PktCnt);
DMX_FILTER_STATUS _MApi_DMX_Reset_SecDisCont_PktCount(MS_U32 u32DmxID);

DMX_FILTER_STATUS _MApi_DMX_FQ_SetFltRushPass(MS_U8 u8DmxId, MS_U8 u8Enable);
DMX_FILTER_STATUS _MApi_DMX_FQ_Init(MS_U32 u32FQEng, DMX_FQ_Info* pFQInfo);
DMX_FILTER_STATUS _MApi_DMX_FQ_Exit(MS_U32 u32FQEng);
DMX_FILTER_STATUS _MApi_DMX_FQ_RushEnable(MS_U32 u32FQEng);
DMX_FILTER_STATUS _MApi_DMX_FQ_SkipRushData(MS_U32 u32FQEng, DMX_FQ_SkipPath eSkipPath);
DMX_FILTER_STATUS _MApi_DMX_FQ_Configure(DMX_FQ_Cfg* pstFqCfg);

DMX_FILTER_STATUS _MApi_DMX_MStr_SyncByte(DMX_TSIF eIf, MS_U8 u8ScrId, MS_U8* pu8SyncByte, MS_BOOL bSet);

DMX_FILTER_STATUS _MApi_DMX_Wait_TspIoSignal(DMX_TSP_IOSIGNAL *pDmxTspIoSig);

DMX_FILTER_STATUS _MApi_DMX_Get_Intr_Count(MS_U32* pu32Count);
DMX_FILTER_STATUS _MApi_DMX_Drop_Enable(MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_VQ_Enable(MS_BOOL bEnable);
DMX_FILTER_STATUS _MApi_DMX_TEI_RemoveErrorPkt( DMX_TEI_RmPktType eDmxPktType, MS_BOOL bEnable );
DMX_FILTER_STATUS _MApi_DMX_SetFwDbgParam(MS_PHY phyAddr, MS_U32 u32Size, MS_U32 u32DbgWord);
DMX_FILTER_STATUS _MApi_DMX_SetAVPause(MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_Pvr_MOBF_Enable(MS_BOOL bEnable, MS_U32 u32key0, MS_U32 u32key1);

DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_Start(DMX_FILEIN_PATH ePath, DMX_FILEIN_DST Dst, MS_PHY pBuf, MS_U32 u32BufSize);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_Stop(DMX_FILEIN_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_Info(DMX_FILEIN_PATH ePath, DMX_Filein_info *pFileinInfo);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_Pause(DMX_FILEIN_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_Resume(DMX_FILEIN_PATH ePath);
MS_BOOL           _MApi_DMX_Filein_Eng_IsIdle(DMX_FILEIN_PATH ePath);
MS_BOOL           _MApi_DMX_Filein_Eng_IsBusy(DMX_FILEIN_PATH ePath);
MS_BOOL           _MApi_DMX_Filein_Eng_IsPause(DMX_FILEIN_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_CMDQ_Reset(DMX_FILEIN_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_CMDQ_GetEmptyNum(DMX_FILEIN_PATH ePath, MS_U32 *pu32EmptySlot);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_CMDQ_FIFOWriteLevel(DMX_FILEIN_PATH ePath, MS_U8 *pu8CmdQStatus);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_GetFileInTimeStamp(DMX_FILEIN_PATH ePath, MS_U32 *pu32FileInTS);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_GetPlaybackStamp(DMX_FILEIN_PATH ePath,MS_U32* pu32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_SetPlaybackStamp(DMX_FILEIN_PATH ePath,MS_U32 u32Stamp);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_GetReadAddr(DMX_FILEIN_PATH ePath, MS_PHY* pphyRead);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_MOBF_Enable(DMX_FILEIN_PATH ePath, MS_BOOL bEnable, MS_U32 u32key);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_PlaybackTimeStampDisable(DMX_FILEIN_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_Filein_Eng_PlaybackTimeStampEnable(DMX_FILEIN_PATH ePath);
void              _MApi_DMX_Filein_Eng_BypassFileInTimeStamp(DMX_FILEIN_PATH ePath, MS_BOOL bbypass);

DMX_FILTER_STATUS _MApi_DMX_MMFI_Filein_Info(DMX_MMFI_PATH ePath, DMX_Filein_info *pFileinInfo);
void              _MApi_DMX_MMFI_Filein_BypassTimeStamp(DMX_MMFI_PATH ePath, MS_BOOL bbypass);
DMX_FILTER_STATUS _MApi_DMX_MMFI_TimeStampEnable(DMX_MMFI_PATH ePath);
DMX_FILTER_STATUS _MApi_DMX_MMFI_TimeStampDisable(DMX_MMFI_PATH ePath);

DMX_FILTER_STATUS _MApi_DMX_GetDbgPortInfo(MS_U32 u32DbgSel,MS_U32* u32DbgInfo);
DMX_FILTER_STATUS _MApi_DMX_Open_MultiFlt( DMX_FILTER_TYPE DmxFltType , MS_U8* pu8DmxId, MS_U8 u8TargetDmxId);
DMX_FILTER_STATUS _MApi_DMX_Filein_Pvr_Eng_Pid_Open(DMX_PVR_ENG Eng, MS_U32 Pid, MS_U8* pu8DmxId, MS_U8 u8ShareKeyType);
DMX_FILTER_STATUS _MApi_DMX_Filein_Pvr_Eng_Pid_Close(DMX_PVR_ENG Eng, MS_U8 u8DmxId);
DMX_FILTER_STATUS _MApi_DMX_Filein_Pvr_Eng_Start(DMX_PVR_ENG Eng, MS_BOOL bPvrAll);
DMX_FILTER_STATUS _MApi_DMX_Filein_Pvr_Eng_Stop(DMX_PVR_ENG Eng);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Pause(DMX_PVR_ENG Eng ,MS_BOOL bPause);
DMX_FILTER_STATUS _MApi_DMX_Pvr_Eng_Pid(DMX_PVR_ENG Eng ,MS_U8 u8DmxId , MS_U32 *Pid, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_Stc_Select(DMX_FILTER_TYPE eFltSrc, MS_U32 u32StcEng);
DMX_FILTER_STATUS _MApi_DMX_TsOutputPadCfg(DMX_FLOW_OUTPUT_PAD eOutPad, DMX_FLOW_INPUT eInSrcPad, MS_BOOL bInParallel, MS_U32 u32ResvNum, MS_U32 *pu32Resv);
DMX_FILTER_STATUS _MApi_DMX_TsS2POutputClkPhase(MS_U16 u16Val, MS_BOOL bEnable, MS_U32 u32Reserved);
DMX_FILTER_STATUS _MApi_DMX_Flow_DscmbEng(DMX_TSIF eTsIf, MS_U32* pu32EngId, MS_BOOL bSet);
DMX_FILTER_STATUS _MApi_DMX_DropScmbPkt(DMX_FILTER_TYPE DmxFltType, MS_BOOL bEnable);

DMX_FILTER_STATUS _MApi_DMX_ResAllocate(DMX_RES_TYPE eResType, void *pRes);
DMX_FILTER_STATUS _MApi_DMX_ResFree(DMX_RES_TYPE eResType, void *pRes);
DMX_FILTER_STATUS _MApi_DMX_Pcr_Get_MapSTC(MS_U32 u32PcrFltId, MS_U32 *pu32StcEng);

#endif //undef UTOPIA_STRIP

#ifdef __cplusplus
}
#endif

#endif //_DMX_PRIV_H_

