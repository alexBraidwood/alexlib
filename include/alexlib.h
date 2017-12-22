/*
 * File: alexlib.h.
 * Created by: Alex Braidwood.
 * Date: Dec 21, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef ALEXLIB_ALEXLIB_H
#define ALEXLIB_ALEXLIB_H

namespace alexlib {
    namespace sdl2 {
        class SDL_window;
        class SDL_glwindow;
    }
    static bool is_running = false;
    static alexlib::sdl2::SDL_window* window_handle;
    static alexlib::sdl2::SDL_glwindow* glwindow_handle;

    void initialize();
    void start();
    void stop();
    void main_loop();
}

#endif //ALEXLIB_ALEXLIB_H
