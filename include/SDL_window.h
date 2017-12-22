/*
 * File: SDL_Window.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_SDL_WINDOW_H
#define BREAKOUT_SDL_WINDOW_H

#include <memory>

struct SDL_Window;

namespace alexlib {
    namespace sdl2 {

        class SDL_window {

        public:
            /**
             * Constructs an RAII-friendly SDL2 Window
             * @param handle Pointer to SDL2 native window
             */
            SDL_window(SDL_Window* handle);

            /**
             * Frees up native window handle
             */
            virtual ~SDL_window();

            SDL_Window* get() const;

            SDL_window(const SDL_window &) = delete;

            SDL_window& operator=(const SDL_window &) = delete;

            /**
             * Factory method for getting an SDL Window
             * @param height The Initial Window Height
             * @param width The Initial Window Width
             * @return Ready-to-go SDL2 Window
             */
            static SDL_window* create(int height, int width, const std::string& name);

        private:
            SDL_Window* windowHandle;
        };
    }
}

#endif //BREAKOUT_SDL_WINDOW_H
