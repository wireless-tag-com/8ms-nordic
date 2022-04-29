# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(SHIELD st7789v_tl019fqv01)
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lvgl)

FILE(GLOB app_sources main/*.c)
target_sources(app PRIVATE ${app_sources})
