#ifndef __CAMERA_BASE_CONFIG_H
#define __CAMERA_BASE_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// 调试期间使用，不真正执行如 "reboot" 等系统调用
// #define ENABLE_SIMULATE_SYSTEM_CALL

#define LCD_SCREEN_WIDTH  (240)
#define LCD_SCREEN_HEIGHT (240)

#define PREVIEW_WIDTH  (240)
#define PREVIEW_HEIGHT (180)

#ifdef __cplusplus
}
#endif

#endif
