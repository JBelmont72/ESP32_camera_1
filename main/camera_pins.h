
// main/camera_pins.h
#pragma once

// ESP32-S3-EYE V2.2 pin definitions
#define CAM_PIN_PWDN    -1  // power down not used
#define CAM_PIN_RESET   -1  // software reset
#define CAM_PIN_XCLK    21
#define CAM_PIN_SIOD    26
#define CAM_PIN_SIOC    27

#define CAM_PIN_D7      35
#define CAM_PIN_D6      34
#define CAM_PIN_D5      39
#define CAM_PIN_D4      36
#define CAM_PIN_D3      19
#define CAM_PIN_D2      18
#define CAM_PIN_D1      5
#define CAM_PIN_D0      4
#define CAM_PIN_VSYNC   25
#define CAM_PIN_HREF    23
#define CAM_PIN_PCLK    22

// Optional: define Yx_GPIO_NUM etc. to match main.c references
#define Y2_GPIO_NUM    CAM_PIN_D0
#define Y3_GPIO_NUM    CAM_PIN_D1
#define Y4_GPIO_NUM    CAM_PIN_D2
#define Y5_GPIO_NUM    CAM_PIN_D3
#define Y6_GPIO_NUM    CAM_PIN_D4
#define Y7_GPIO_NUM    CAM_PIN_D5
#define Y8_GPIO_NUM    CAM_PIN_D6
#define Y9_GPIO_NUM    CAM_PIN_D7
#define XCLK_GPIO_NUM  CAM_PIN_XCLK
#define PCLK_GPIO_NUM  CAM_PIN_PCLK
#define VSYNC_GPIO_NUM CAM_PIN_VSYNC
#define HREF_GPIO_NUM  CAM_PIN_HREF
#define SIOD_GPIO_NUM  CAM_PIN_SIOD
#define SIOC_GPIO_NUM  CAM_PIN_SIOC
#define PWDN_GPIO_NUM  CAM_PIN_PWDN
#define RESET_GPIO_NUM CAM_PIN_RESET

