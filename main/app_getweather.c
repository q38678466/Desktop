#include "app_getweather.h"

#include "esp_log.h"   
#include "esp_err.h"
#include "my_wifi.h"
#include "cJSON.h"
#include "esp_http_client.h"

#define TAG "app_getweather"

// #define URL_TS "https://api.seniverse.com/v3/weather/daily.json?key=Sqh0Lj6xcWShKnElL&location=beijing&language=zh-Hans&unit=c&start=0&days=1"
#define URL_TS "https://api.seniverse.com/v3/weather/daily.json?key=Sqh0Lj6xcWShKnElL&location=beijing&language=zh-Hans&unit=c&start=0&days=1"


static esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id) {
    case HTTP_EVENT_ON_DATA:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA: len=%d", evt->data_len);
        break;
    default:
        break;
    }
    return ESP_OK;
}

void  get_network_weather()
{
    esp_err_t err;
    esp_http_client_config_t config = {
        .url = URL_TS,
        .method = HTTP_METHOD_GET,
        .event_handler = _http_event_handler,
        .timeout_ms = 10000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialise HTTP connection");
        return;
    }

    ESP_LOGI(TAG, "Performing HTTP GET: %s", URL_TS);
    err = esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}