cmake_minimum_required(VERSION 3.8)
project(SOIL)

add_library(SOIL "")
target_sources(SOIL PRIVATE
        src/image_helper.c
        src/stb_image_aug.c
        src/image_DXT.c
        src/SOIL.c)
target_include_directories(SOIL PUBLIC src)