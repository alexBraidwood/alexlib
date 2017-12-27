/*
 * File: alexlib.h.
 * Created by: Alex Braidwood.
 * Date: Dec 21, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef ALEXLIB_ALEXLIB_H
#define ALEXLIB_ALEXLIB_H

#include <string>
#include <glm/glm.hpp>
#include "game-clock.h"

namespace alexlib {
    namespace sdl2 {
        class SDL_window;
        class Sdl_gl_window;
    }

    static Game_clock game_clock;
    static bool is_running = false;
    static alexlib::sdl2::SDL_window* window_handle;
    static alexlib::sdl2::Sdl_gl_window* glwindow_handle;

    void initialize(const std::string& title = "Game", glm::vec2 window_size = glm::vec2(800, 600));
    void start();
    void stop();
    void main_loop();
}

#endif //ALEXLIB_ALEXLIB_H
