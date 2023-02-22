#ifndef __CAMERA_HIMPP_CONFIG_H
#define __CAMERA_HIMPP_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "himpp.h"

// 视频码率系数
typedef struct {
    int num; // Numerator
    int den; // Denominator
} video_bitrate_ratio;
const video_bitrate_ratio g_br_list[3];
extern int g_br_index;

// 启用的VENC通道总数
#define ENABLE_VENC_CHN_NUM (1)
// 启用的AENC通道总数
#define ENABLE_AENC_CHN_NUM (1)


extern HI_U32 preview_crop_u32Width;
extern HI_U32 preview_crop_u32Height;
extern HI_U32 preview_u32Width;
extern HI_U32 preview_u32Height;

extern HI_U32 g_u32SupplementConfig;

extern HI_U32 g_u32SuperFrameSize;

extern VI_PIPE    g_ViPipe;
extern VI_CHN     g_ViChn;
extern PIC_SIZE_E g_viSize;

extern VPSS_GRP       g_VpssGrp;
extern VPSS_CHN       g_VpssChn[];
extern VENC_CHN       g_VencChn[];
extern HI_BOOL        g_abChnEnable[];
extern PIC_SIZE_E     g_vpssSize[];
extern PIC_SIZE_E     g_vencSize[];
extern PAYLOAD_TYPE_E g_enPayLoad[];
extern HI_U32         g_u32Profile[];
extern HI_U32         g_u32DstFrameRate;

extern HI_S32              g_s32AiChnCnt;
extern HI_S32              g_s32AencChnCnt;
extern AUDIO_DEV           g_AiDev;
extern HI_BOOL             g_bAiReSample;
extern AI_CHN              g_AiChn;
extern AENC_CHN            g_AeChn;
extern AUDIO_SAMPLE_RATE_E g_AiSamplerate;
extern AUDIO_BIT_WIDTH_E   g_AiBitwidth;
extern AUDIO_SOUND_MODE_E  g_AiSoundmode;

extern HI_S32              g_s32AoChnCnt;
extern AUDIO_DEV           g_AoDev;
extern HI_BOOL             g_bAoReSample;
extern AI_CHN              g_AoChn;
extern AENC_CHN            g_AdChn;
extern AUDIO_SAMPLE_RATE_E g_AoSamplerate;
extern AUDIO_BIT_WIDTH_E   g_AoBitwidth;
extern AUDIO_SOUND_MODE_E  g_AoSoundmode;

#ifdef __cplusplus
}
#endif

#endif
