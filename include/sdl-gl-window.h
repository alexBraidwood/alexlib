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

        class Sdl_gl_window {
        public:
            void update();

            virtual ~Sdl_gl_window();

            SDL_window* get_sdl_window() const;


            Sdl_gl_window& operator=(Sdl_gl_window &&) = delete;
            Sdl_gl_window(Sdl_gl_window &&) = delete;
            Sdl_gl_window(const Sdl_gl_window &) = delete;
            Sdl_gl_window& operator=(const Sdl_gl_window &) = delete;

            /**
             * Factory method for generating GLWindow with an OpenGL-friendly context
             * @param window Pointer to an SDL2 window, used in context creation
             * @return OpenGL-friendly window
             */
            static Sdl_gl_window* create(SDL_window* window);

        private:
            Sdl_gl_window(SDL_GLContext context_handle, SDL_window* window);

            SDL_GLContext context;
            SDL_window* window;
            bool loaded_successfully;

        };
    }
}


#endif //BREAKOUT_SDL_GLWINDOW_H
