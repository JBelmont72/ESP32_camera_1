
# main/CMakeLists.txt
idf_component_register(
    SRCS
        "main.c"
        "camera_init.c"
        "wifi_init.c"
        "http_stream.c"
    INCLUDE_DIRS
        "."        # include all headers in main/
)

# Optionally, link extra components
# REQUIRES esp32 camera
