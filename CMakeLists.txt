cmake_minimum_required(VERSION 3.13)

include(FetchContent)
include(pico_sdk_import.cmake)

project(testapplication C CXX ASM)

pico_sdk_init()

add_executable(main
    src/main.c
)

target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(main pico_stdlib hardware_pwm)
pico_add_extra_outputs(main)
