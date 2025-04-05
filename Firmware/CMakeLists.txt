cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico)

include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

project(envopenaudio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(envopenaudio)

target_sources(envopenaudio PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
)

pico_set_program_name(envopenaudio "envopenaudio")
pico_set_program_version(envopenaudio "0.1")

#pico_enable_stdio_uart(envopenaudio 0)
#pico_enable_stdio_usb(envopenaudio 0)

target_include_directories(
	envopenaudio
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
	)

target_link_libraries(envopenaudio
    pico_stdlib
    pico_audio_i2s
	pico_unique_id
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(envopenaudio)