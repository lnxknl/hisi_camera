#include "camera_himpp_config.h"
#include "camera_base_config.h"

// 海思多媒体系统的相关配置
// 如果修改了分辨率，还需要修改 MPP 内存池相关配置

// 视频码率系数，原始码率值乘以这个系数
const video_bitrate_ratio g_br_list[3] = {
    {1, 2}, // 低
    {1, 1}, // 中
    {3, 2}, // 高
};
int g_br_index = 0;

// 是否启用 VB 内存的附加信息
HI_U32 g_u32SupplementConfig = HI_FALSE;

// 超大帧阈值，超过此大小进行重编或丢弃
HI_U32 g_u32SuperFrameSize = 512 * 1024;

// VI相关，此芯片只支持单摄，连接在VI管道0、通道0上
VI_PIPE g_ViPipe = 0;
VI_CHN g_ViChn = 0;

// OV5640 的输入图像尺寸，如有变动需配合OV5640驱动一起修改
PIC_SIZE_E g_viSize = PIC_1080P;

// VPSS组序号，目前只使用 Group 0
VPSS_GRP g_VpssGrp = 0;

// VPSS 通道和 VENC 通道的绑定关系，即VpssChn[i]绑定到VencChn[i]，以下面为例就是VpssChn4绑定VencChn0
VPSS_CHN g_VpssChn[ENABLE_VENC_CHN_NUM] = {3};
VENC_CHN g_VencChn[ENABLE_VENC_CHN_NUM] = {0};

// 要使用的vpss通道，3516EV200是3物理通道+4扩展通道，0到2是物理通道，3到6是扩展通道
HI_BOOL g_abChnEnable[VPSS_MAX_CHN_NUM] = {HI_TRUE, HI_FALSE, HI_FALSE,
                                         HI_TRUE, HI_TRUE, HI_FALSE, HI_FALSE};

// 各个VPSS通道的输出图像尺寸
PIC_SIZE_E g_vpssSize[VPSS_MAX_CHN_NUM] = {PIC_1080P, PIC_BUTT, PIC_BUTT, 
                                         PIC_1080P, PIC_PREVIEW, PIC_BUTT, PIC_BUTT};

// 各个VENC通道的输入图像尺寸，必须和上面的VpssChn、VencChn绑定关系一致
PIC_SIZE_E g_vencSize[ENABLE_VENC_CHN_NUM] = {PIC_1080P};

// 各个VENC通道的编码类型
// PAYLOAD_TYPE_E g_enPayLoad[ENABLE_VENC_CHN_NUM] = {PT_H265};
PAYLOAD_TYPE_E g_enPayLoad[ENABLE_VENC_CHN_NUM] = {PT_H264};

// 各个VENC通道的编码等级，一般而言对于H264、H265、JPEG都配置为0就行，如有其它需求参考文档进行配置
HI_U32 g_u32Profile[ENABLE_VENC_CHN_NUM] = {0};


// 我在VPSS做了帧率控制，这个就是VPSS限制后的帧率，也是下级模块的输入帧率
HI_U32 g_u32DstFrameRate = 30;


// VPSS 扩展通道先做裁剪后做缩放
HI_U32 preview_crop_u32Width  = 1440;
HI_U32 preview_crop_u32Height = 1080;
// PIC_PREVIEW 视频预览缩放尺寸，VPSS 等比缩放到这个大小，也是最终显示的大小
HI_U32 preview_u32Width  = PREVIEW_WIDTH;
HI_U32 preview_u32Height = PREVIEW_HEIGHT;


// 音频输入配置
HI_S32              g_s32AiChnCnt   = 1;
HI_S32              g_s32AencChnCnt = 1; // AENC 通道数 = AiChnCnt >> (声道数 - 1)
AUDIO_DEV           g_AiDev         = HIMPP_AUDIO_INNER_AI_DEV;
HI_BOOL             g_bAiReSample   = HI_FALSE;
AI_CHN              g_AiChn         = 0;
AENC_CHN            g_AeChn         = 0;
AUDIO_SAMPLE_RATE_E g_AiSamplerate  = AUDIO_SAMPLE_RATE_48000;
AUDIO_BIT_WIDTH_E   g_AiBitwidth    = AUDIO_BIT_WIDTH_16; // PCM 默认就用16BIT，不要改
AUDIO_SOUND_MODE_E  g_AiSoundmode   = AUDIO_SOUND_MODE_MONO;

// 音频输出配置
HI_S32              g_s32AoChnCnt  = 1; // 单声道为1，双声道为2
AUDIO_DEV           g_AoDev        = HIMPP_AUDIO_INNER_AO_DEV;
HI_BOOL             g_bAoReSample  = HI_FALSE;
AI_CHN              g_AoChn        = 0;
AENC_CHN            g_AdChn        = 0;
AUDIO_SAMPLE_RATE_E g_AoSamplerate = AUDIO_SAMPLE_RATE_48000;
AUDIO_BIT_WIDTH_E   g_AoBitwidth   = AUDIO_BIT_WIDTH_16; // PCM 默认就用16BIT，不要改
AUDIO_SOUND_MODE_E  g_AoSoundmode  = AUDIO_SOUND_MODE_MONO;
