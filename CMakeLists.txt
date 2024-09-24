cmake_minimum_required(VERSION 3.27)

set(PICO_BOARD pico_w)

include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(Curiosity C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)

add_executable(Curiosity main.c)

target_link_libraries(
        Curiosity
        pico_stdlib
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
)

pico_enable_stdio_usb(Curiosity 1)
pico_enable_stdio_uart(Curiosity 0)

pico_add_extra_outputs(Curiosity)
