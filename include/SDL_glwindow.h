/*
 * File: SDL_GLWindow.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_SDL_GLWINDOW_H
#define BREAKOUT_SDL_GLWINDOW_H

#include <SDL_window.h>

typedef void* SDL_GLContext;

namespace alexlib {
    namespace sdl2 {

        class SDL_glwindow {
        public:
            void update();

            virtual ~SDL_glwindow();

            SDL_window* get_sdl_window() const;

            /**
             * Factory method for generating GLWindow with an OpenGL-friendly context
             * @param window Pointer to an SDL2 window, used in context creation
             * @return OpenGL-friendly window
             */
            static SDL_glwindow* create(SDL_window* window);

        private:
            SDL_glwindow(SDL_GLContext context_handle, SDL_window* window);

            SDL_GLContext context;
            SDL_window* window;
            bool loaded_successfully;

            SDL_glwindow &operator=(SDL_glwindow &&) = delete;

            SDL_glwindow(SDL_glwindow &&) = delete;

            SDL_glwindow(const SDL_glwindow &) = delete;

            SDL_glwindow &operator=(const SDL_glwindow &) = delete;
        };
    }
}


#endif //BREAKOUT_SDL_GLWINDOW_H
