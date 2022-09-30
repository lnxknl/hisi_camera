#ifndef __MEDIA_H
#define __MEDIA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>
#include "media_buf.h"

typedef enum {
    REC_STATE_IDLE,
    REC_STATE_DO_START,
    REC_STATE_START_OK,
    REC_STATE_PAUSE,
    REC_STATE_DO_STOP,
    REC_STATE_STOP_OK,
} rec_state_e;

typedef enum {
    HISI_SDK_STATE_UNKNOWN,
    HISI_SDK_DO_INIT,
    HISI_SDK_INIT_OK,
    HISI_SDK_DO_EXIT,
    HISI_SDK_EXIT_OK,
} hisi_sdk_state_e;

int32_t hisi_media_init();
int32_t hisi_media_exit();
int32_t ao_send_frame(uint8_t *data, int32_t len, int32_t block);
int32_t get_preview_img(uint8_t *buf);
int32_t cam_media_init();
int32_t cam_media_exit();

#ifdef __cplusplus
}
#endif

#endif
