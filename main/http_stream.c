
#include "http_stream.h"
#include "esp_log.h"

static const char *TAG = "HTTP_STREAM";

esp_err_t http_stream_start(void) {
    ESP_LOGI(TAG, "HTTP stream server starting...");
    // your HTTP server init code here
    return ESP_OK;
}

