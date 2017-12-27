/*
 * File: SDL_window.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <SDL2/SDL.h>
#include <sdl-window.h>
#include <cassert>
#include <iostream>

using namespace alexlib::sdl2;

SDL_window::SDL_window(SDL_Window* handle, const glm::vec2& size)
    : windowHandle(handle), windowSize(size) { }

SDL_window::~SDL_window() {
    if(windowHandle != nullptr) {
        SDL_DestroyWindow(windowHandle);
    }
}

SDL_Window* SDL_window::get() const {
    return windowHandle;
}

SDL_window* SDL_window::create(const glm::vec2& size,
                               const std::string& windowName) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
        // TODO(Alex): Handle the error here (assert maybe? it shouldn't fail)
        std::cout << "Failed to initialize SDL properly " << SDL_GetError() << std::endl;
    }

    auto window_handle = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_OPENGL);
    assert(window_handle);

    return new SDL_window(window_handle, size);
}

void SDL_window::resize(const glm::vec2& size) {
    SDL_SetWindowSize(this->get(), size.x, size.y);
    this->windowSize = size;
}

const glm::vec2 &SDL_window::window_size() const {
    return this->windowSize;
}
