cmake_minimum_required(VERSION 3.27)

set(PICO_BOARD pico_w)

include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include(lib/hcst/CMakeLists.txt)

project(curiosity C CXX ASM)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)

add_executable(
        curiosity
        main.c
        src/socket.c
        src/execute.c
)

target_include_directories(curiosity PRIVATE inc)

target_link_libraries(
        curiosity
        pico_stdlib
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        pico_cyw43_arch_lwip_sys_freertos
        hcst
        hardware_gpio
        hardware_pwm
)

pico_enable_stdio_usb(curiosity 1)
pico_enable_stdio_uart(curiosity 0)

pico_add_extra_outputs(curiosity)
