/*
 * File: SDL_GLWindow.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <sdl-gl-window.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace alexlib::sdl2;

Sdl_gl_window::Sdl_gl_window(SDL_GLContext context_handle, SDL_window* window)
        :   context(context_handle),
            loaded_successfully(false),
            window(window)  {

}

Sdl_gl_window::~Sdl_gl_window() {
    if (this->context != nullptr) {
        SDL_GL_DeleteContext(this->context);
    }
    if (this->window != nullptr) {
        delete window;
    }
}

void Sdl_gl_window::update() {
    SDL_GL_SwapWindow(window->get());
}

Sdl_gl_window* Sdl_gl_window::create(SDL_window* window) {
    if(window) {
        /* TODO(Alex): GL Settings */
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        auto glContext = SDL_GL_CreateContext(window->get());

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (err != GLEW_OK)
        {
            auto error = glewGetErrorString(err);
        }

        return new Sdl_gl_window(glContext, window);
    }

    return nullptr;
}

SDL_window* Sdl_gl_window::get_sdl_window() const {
    return window;
}


