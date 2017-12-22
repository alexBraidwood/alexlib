#include <alexlib.h>
#include <SDL_window.h>
#include <SDL_glwindow.h>
#include <SDL_events.h>

namespace alexlib {
    void initialize() {
        window_handle = alexlib::sdl2::SDL_window::create(800, 600, "Game Window");
        glwindow_handle = alexlib::sdl2::SDL_glwindow::create(window_handle);
        SDL_ShowWindow(window_handle->get());
    }

    void start() {
        is_running = true;
        main_loop();
    }

    void stop() {
        is_running = false;
    }

    void main_loop() {
        while(is_running) {
            SDL_Event e;
            SDL_PollEvent(&e);

            if (e.type == SDL_QUIT || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)) {
                stop();
            }
        }
    }
}
