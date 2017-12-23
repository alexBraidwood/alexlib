/*
 * File: SDL_GLWindow.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_SDL_GLWINDOW_H
#define BREAKOUT_SDL_GLWINDOW_H

#include <sdl-window.h>

typedef void* SDL_GLContext;

namespace alexlib {
    namespace sdl2 {

        class SDL {
        public:
            void update();

            virtual ~SDL();

            SDL_window* get_sdl_window() const;

            /**
             * Factory method for generating GLWindow with an OpenGL-friendly context
             * @param window Pointer to an SDL2 window, used in context creation
             * @return OpenGL-friendly window
             */
            static SDL* create(SDL_window* window);

        private:
            SDL(SDL_GLContext context_handle, SDL_window* window);

            SDL_GLContext context;
            SDL_window* window;
            bool loaded_successfully;

            SDL &operator=(SDL &&) = delete;

            SDL(SDL &&) = delete;

            SDL(const SDL &) = delete;

            SDL &operator=(const SDL &) = delete;
        };
    }
}


#endif //BREAKOUT_SDL_GLWINDOW_H
