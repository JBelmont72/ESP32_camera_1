

// main/main.c
#include <stdio.h>
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_camera.h"
#include "esp_event.h"

#include "wifi_init.h"       // Wi-Fi init
#include "camera_pins.h"     // camera pin definitions
#include "http_stream.h"     // HTTP stream server

static const char *TAG = "MAIN_APP";

void app_main(void)
{
    esp_err_t ret;

    // Initialize NVS
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "Initializing network interface...");
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Initialize Wi-Fi
    const char* ssid = "SpectrumSetup-41";
    const char* pass = "leastdinner914";
    ESP_LOGI(TAG, "Connecting to Wi-Fi SSID: %s", ssid);
    ret = wifi_init_sta(ssid, pass);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Wi-Fi init failed: %d", ret);
        return;
    }

    // Initialize Camera
    ESP_LOGI(TAG, "Initializing camera...");
    camera_config_t config = {
        .ledc_channel = LEDC_CHANNEL_0,
        .ledc_timer   = LEDC_TIMER_0,
        .pin_d0       = CAM_PIN_D0,
        .pin_d1       = CAM_PIN_D1,
        .pin_d2       = CAM_PIN_D2,
        .pin_d3       = CAM_PIN_D3,
        .pin_d4       = CAM_PIN_D4,
        .pin_d5       = CAM_PIN_D5,
        .pin_d6       = CAM_PIN_D6,
        .pin_d7       = CAM_PIN_D7,
        .pin_xclk     = CAM_PIN_XCLK,
        .pin_pclk     = CAM_PIN_PCLK,
        .pin_vsync    = CAM_PIN_VSYNC,
        .pin_href     = CAM_PIN_HREF,
        .pin_sccb_sda = CAM_PIN_SIOD,
        .pin_sccb_scl = CAM_PIN_SIOC,
        .pin_pwdn     = CAM_PIN_PWDN,
        .pin_reset    = CAM_PIN_RESET,
        .xclk_freq_hz = 20000000,
        .pixel_format = PIXFORMAT_JPEG,
        .frame_size   = FRAMESIZE_QVGA,
        .jpeg_quality = 12,
        .fb_count     = 1
    };

    ret = esp_camera_init(&config);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Camera init failed with error 0x%x", ret);
        return;
    }

    // Start HTTP stream server
    ESP_LOGI(TAG, "Starting HTTP stream server...");
    ret = http_stream_start();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "HTTP stream server failed: 0x%x", ret);
        return;
    }

    ESP_LOGI(TAG, "Camera ready. Access the stream via http://<ESP32_IP>:8080");
}

