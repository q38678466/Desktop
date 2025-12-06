idf_component_register(SRCS "my_wifi.c"
                            "my_http_server.c" 
                            "device_config.c" 
                            "deep_sleep.c" 
                            "my_sht30.c" 
                            "e_paper.c" 
                            "main.c" 
                            "my_button.c" 
                            "system_time.c"
                            "app_getweather.c"
                    INCLUDE_DIRS "."
                    EMBED_FILES "wifi_config.html")

target_compile_options(${COMPONENT_LIB} PRIVATE 
    -Wno-missing-braces
)
