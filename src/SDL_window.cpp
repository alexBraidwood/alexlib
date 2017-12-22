/*
 * File: SDL_window.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <SDL2/SDL.h>
#include <SDL_window.h>
#include <cassert>
#include <iostream>

using namespace alexlib::sdl2;

SDL_window::SDL_window(SDL_Window* handle)
    : windowHandle(handle) { }

SDL_window::~SDL_window() {
    if(windowHandle != nullptr) {
        SDL_DestroyWindow(windowHandle);
    }
}

SDL_Window* SDL_window::get() const {
    return windowHandle;
}

SDL_window* SDL_window::create(int height,
                               int width,
                               const std::string& windowName) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
        // TODO(Alex): Handle the error here (assert maybe? it shouldn't fail)
        std::cout << "Failed to initialize SDL properly " << SDL_GetError() << std::endl;
    }

    auto window_handle = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_OPENGL);
    assert(window_handle);

    return new SDL_window(window_handle);
}
