cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico2)

include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

project(envopenaudio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(envopenaudio
    main.c
    usb_descriptors.c
)

pico_enable_stdio_uart(envopenaudio 1)
pico_enable_stdio_usb(envopenaudio 0)

target_include_directories(envopenaudio PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${PICO_SDK_PATH}/lib/tinyusb/src
)

target_link_libraries(envopenaudio
    pico_stdlib
    pico_audio_i2s
    tinyusb_device
    tinyusb_board
    hardware_dma
    hardware_pio
    hardware_clocks
)

pico_add_extra_outputs(envopenaudio)