#include <linux/kthread.h>
#include <linux/string.h>
#include <linux/slab.h>
///#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/irqreturn.h>
#include <linux/list.h>

#include "mhal_audio.h"
//#include "mhal_audio_datatype.h"

#include "mi_sys.h"
#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#if 0
static MI_U8 _gau8Tone48kmono[256] = {
    0x00, 0x00, 0xf9, 0x18, 0xfb, 0x30, 0x1c, 0x47,
    0x82, 0x5a, 0x6d, 0x6a, 0x41, 0x76, 0x8a, 0x7d,
    0xff, 0x7f, 0x8b, 0x7d, 0x42, 0x76, 0x6f, 0x6a,
    0x84, 0x5a, 0x1f, 0x47, 0xfe, 0x30, 0xfc, 0x18,
    0x03, 0x00, 0x0a, 0xe7, 0x07, 0xcf, 0xe6, 0xb8,
    0x80, 0xa5, 0x95, 0x95, 0xc0, 0x89, 0x76, 0x82,
    0x00, 0x80, 0x75, 0x82, 0xbc, 0x89, 0x90, 0x95,
    0x7a, 0xa5, 0xde, 0xb8, 0xff, 0xce, 0x02, 0xe7,
    0x00, 0x00, 0xf9, 0x18, 0xfb, 0x30, 0x1c, 0x47,
    0x82, 0x5a, 0x6d, 0x6a, 0x41, 0x76, 0x8a, 0x7d,
    0xff, 0x7f, 0x8b, 0x7d, 0x42, 0x76, 0x6f, 0x6a,
    0x84, 0x5a, 0x1f, 0x47, 0xfe, 0x30, 0xfc, 0x18,
    0x03, 0x00, 0x0a, 0xe7, 0x07, 0xcf, 0xe6, 0xb8,
    0x80, 0xa5, 0x95, 0x95, 0xc0, 0x89, 0x76, 0x82,
    0x00, 0x80, 0x75, 0x82, 0xbc, 0x89, 0x90, 0x95,
    0x7a, 0xa5, 0xde, 0xb8, 0xff, 0xce, 0x02, 0xe7,
    0x00, 0x00, 0xf9, 0x18, 0xfb, 0x30, 0x1c, 0x47,
    0x82, 0x5a, 0x6d, 0x6a, 0x41, 0x76, 0x8a, 0x7d,
    0xff, 0x7f, 0x8b, 0x7d, 0x42, 0x76, 0x6f, 0x6a,
    0x84, 0x5a, 0x1f, 0x47, 0xfe, 0x30, 0xfc, 0x18,
    0x03, 0x00, 0x0a, 0xe7, 0x07, 0xcf, 0xe6, 0xb8,
    0x80, 0xa5, 0x95, 0x95, 0xc0, 0x89, 0x76, 0x82,
    0x00, 0x80, 0x75, 0x82, 0xbc, 0x89, 0x90, 0x95,
    0x7a, 0xa5, 0xde, 0xb8, 0xff, 0xce, 0x02, 0xe7,
    0x00, 0x00, 0xf9, 0x18, 0xfb, 0x30, 0x1c, 0x47,
    0x82, 0x5a, 0x6d, 0x6a, 0x41, 0x76, 0x8a, 0x7d,
    0xff, 0x7f, 0x8b, 0x7d, 0x42, 0x76, 0x6f, 0x6a,
    0x84, 0x5a, 0x1f, 0x47, 0xfe, 0x30, 0xfc, 0x18,
    0x03, 0x00, 0x0a, 0xe7, 0x07, 0xcf, 0xe6, 0xb8,
    0x80, 0xa5, 0x95, 0x95, 0xc0, 0x89, 0x76, 0x82,
    0x00, 0x80, 0x75, 0x82, 0xbc, 0x89, 0x90, 0x95,
    0x7a, 0xa5, 0xde, 0xb8, 0xff, 0xce, 0x02, 0xe7
};
#else
static MI_U8 _gau8Tone48kmono[256] = {
    0x00, 0x00, 0x4e, 0x17, 0xb6, 0x2d, 0x5d, 0x42,
    0x78, 0x54, 0x52, 0x63, 0x5c, 0x6e, 0x29, 0x75,
    0x75, 0x77, 0x29, 0x75, 0x5d, 0x6e, 0x52, 0x63,
    0x78, 0x54, 0x5d, 0x42, 0xb7, 0x2d, 0x4e, 0x17,
    0x00, 0x00, 0xb2, 0xe8, 0x4a, 0xd2, 0xa3, 0xbd,
    0x89, 0xab, 0xad, 0x9c, 0xa5, 0x91, 0xd8, 0x8a,
    0x8d, 0x88, 0xd8, 0x8a, 0xa4, 0x91, 0xae, 0x9c,
    0x88, 0xab, 0xa2, 0xbd, 0x4a, 0xd2, 0xb2, 0xe8,
    0x00, 0x00, 0x4e, 0x17, 0xb6, 0x2d, 0x5d, 0x42,
    0x78, 0x54, 0x52, 0x63, 0x5c, 0x6e, 0x29, 0x75,
    0x75, 0x77, 0x29, 0x75, 0x5d, 0x6e, 0x52, 0x63,
    0x78, 0x54, 0x5d, 0x42, 0xb7, 0x2d, 0x4e, 0x17,
    0x00, 0x00, 0xb2, 0xe8, 0x4a, 0xd2, 0xa3, 0xbd,
    0x89, 0xab, 0xad, 0x9c, 0xa5, 0x91, 0xd8, 0x8a,
    0x8d, 0x88, 0xd8, 0x8a, 0xa4, 0x91, 0xae, 0x9c,
    0x88, 0xab, 0xa2, 0xbd, 0x4a, 0xd2, 0xb2, 0xe8,
    0x00, 0x00, 0x4e, 0x17, 0xb6, 0x2d, 0x5d, 0x42,
    0x78, 0x54, 0x52, 0x63, 0x5c, 0x6e, 0x29, 0x75,
    0x75, 0x77, 0x29, 0x75, 0x5d, 0x6e, 0x52, 0x63,
    0x78, 0x54, 0x5d, 0x42, 0xb7, 0x2d, 0x4e, 0x17,
    0x00, 0x00, 0xb2, 0xe8, 0x4a, 0xd2, 0xa3, 0xbd,
    0x89, 0xab, 0xad, 0x9c, 0xa5, 0x91, 0xd8, 0x8a,
    0x8d, 0x88, 0xd8, 0x8a, 0xa4, 0x91, 0xae, 0x9c,
    0x88, 0xab, 0xa2, 0xbd, 0x4a, 0xd2, 0xb2, 0xe8,
    0x00, 0x00, 0x4e, 0x17, 0xb6, 0x2d, 0x5d, 0x42,
    0x78, 0x54, 0x52, 0x63, 0x5c, 0x6e, 0x29, 0x75,
    0x75, 0x77, 0x29, 0x75, 0x5d, 0x6e, 0x52, 0x63,
    0x78, 0x54, 0x5d, 0x42, 0xb7, 0x2d, 0x4e, 0x17,
    0x00, 0x00, 0xb2, 0xe8, 0x4a, 0xd2, 0xa3, 0xbd,
    0x89, 0xab, 0xad, 0x9c, 0xa5, 0x91, 0xd8, 0x8a,
    0x8d, 0x88, 0xd8, 0x8a, 0xa4, 0x91, 0xae, 0x9c,
    0x88, 0xab, 0xa2, 0xbd, 0x4a, 0xd2, 0xb2, 0xe8
 };
#endif


/**
*  @file mhal_audio.h
*  @brief audio driver APIs
*/

/**
* \brief Init audio HW
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_Init(void)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Config audio I2S output device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ConfigI2sOut(MHAL_AUDIO_DEV AoutDevId, MHAL_AUDIO_I2sCfg_t *pstI2sConfig)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Config audio I2S input device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ConfigI2sIn(MHAL_AUDIO_DEV AinDevId, MHAL_AUDIO_I2sCfg_t *pstI2sConfig)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Config audio PCM output device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ConfigPcmOut(MHAL_AUDIO_DEV AoutDevId, MHAL_AUDIO_PcmCfg_t *ptDmaConfig)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Config audio PCM input device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ConfigPcmIn(MHAL_AUDIO_DEV AinDevId, MHAL_AUDIO_PcmCfg_t *ptDmaConfig)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Open audio PCM output device, should be called after configPcmOut
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_OpenPcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Open audio PCM input device, should be called after configPcmIn
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_OpenPcmIn(MHAL_AUDIO_DEV AinDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Close audio PCM output device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ClosePcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Close audio PCM input device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ClosePcmIn(MHAL_AUDIO_DEV AinDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}

/**
* \brief Start audio PCM output device, start playback
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_StartPcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Start audio PCM input device, start recording
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_StartPcmIn(MHAL_AUDIO_DEV AinDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Stop audio PCM output device, stop playback
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_StopPcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Stop audio PCM input device, stop recording
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_StopPcmIn(MHAL_AUDIO_DEV AinDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Pause audio PCM output device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_PausePcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Resume audio PCM output device
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_ResumePcmOut(MHAL_AUDIO_DEV AoutDevId)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}


/**
* \brief Read audio raw data from PCM input device(period unit)
* \return value>0 => read data bytes, value<0 => error number
*/
MS_S32 MHAL_AUDIO_ReadDataIn(MHAL_AUDIO_DEV AinDevId, VOID *pRdBuffer, MS_U32 u32Size, MS_BOOL bBlock)
{
    MS_S32 s32RetSize = u32Size;

    MS_S32 s32Idx = 0;
    MS_S32 s32LenPerChan;
    MS_S32 s32Jidx = 0;
    MS_S32 s32LoopTone;
    MS_U32 u32ToneSize;

    u32ToneSize = sizeof(_gau8Tone48kmono);

    s32LenPerChan = u32Size /16;
    s32LoopTone =  s32LenPerChan / u32ToneSize ;

    for(s32Idx = 0; s32Idx<16; s32Idx++)
   {
        for(s32Jidx = 0; s32Jidx < s32LoopTone; s32Jidx++)
            memcpy((pRdBuffer+s32Idx*s32LenPerChan + s32Jidx*u32ToneSize) ,_gau8Tone48kmono, u32ToneSize);
    }

    return s32RetSize;
}

/**
* \brief Write audio raw data to PCM output device(period unit)
* \return value>0 => write data bytes, value<0 => error number
*/
MS_S32  MHAL_AUDIO_WriteDataOut(MHAL_AUDIO_DEV AoutDevId, VOID *pWrBuffer, MS_U32 u32Size, MS_BOOL bBlock)
{
    MS_S32 s32RetSize = u32Size;

    return s32RetSize;
}


/**
* \brief Set output path gain
* \return 0 => success, <0 => error number
*/
MS_S32 MHAL_AUDIO_SetGainOut(MHAL_AUDIO_DEV AoutDevId, MS_S16 s16Gain)
{
    MS_S32 s32Ret = MHAL_SUCCESS;

    return s32Ret;
}