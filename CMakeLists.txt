cmake_minimum_required(VERSION 3.6)
project(alexlib)

set(CMAKE_CXX_STANDARD 17)

add_library(alexlib "")

if (WIN32)
    set(GLEW_BUILD "GLEW_STATIC")
    set(GLEW_STATIC)
endif()

include(cmake/TargetArch.cmake)
target_architecture(ARCH_TYPE)

add_subdirectory(external/glew/build/cmake)
add_subdirectory(external/SOIL)
add_subdirectory(external/SDL2)

find_library(GL_Library
        NAMES opengl32)

set(CMAKE_C_FLAGS_DEBUG "-DDEBUG")

target_sources(alexlib PRIVATE
        # Headers
        include/alexlib.h
        include/SDL_glwindow.h
        include/SDL_window.h

        # Source Files
        src/alexlib.cpp
        src/SDL_glwindow.cpp
        src/SDL_window.cpp)

target_include_directories(alexlib PRIVATE
        include
        external/glew/include
        external/SOIL/src
        external/glm
        external/SDL2/include)


if(WIN32)
    target_link_libraries(alexlib PUBLIC -static-libstdc++ -lmingw32 -lrpcrt4 SDL2 SDL2Main SOIL glew_s ${GL_Library})
else()
    target_link_libraries(alexlib PUBLIC uuid glew SOIL SDL2 ${GL_LIBRARY})
endif()