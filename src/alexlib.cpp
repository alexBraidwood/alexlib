#include <alexlib.h>
#include <sdl-window.h>
#include <sdl-glwindow.h>
#include <SDL_events.h>
#include <sdl-imgui.h>
#include <imgui.h>
#include <glm/glm.hpp>

namespace alexlib {
    void initialize() {
        window_handle = alexlib::sdl2::SDL_window::create(1280, 960, "Game Window");
        glwindow_handle = alexlib::sdl2::SDL::create(window_handle);
        alexlib::imgui::init(window_handle->get());
    }

    void start() {
        is_running = true;
        game_clock.start();
        main_loop();
    }

    void stop() {
        is_running = false;
    }

    void main_loop() {
        while(is_running) {
            auto dt = game_clock.deltaTime();
            SDL_Event e;
            SDL_PollEvent(&e);
            alexlib::imgui::process_event(&e);
            alexlib::imgui::new_frame(window_handle->get(), dt);

            if (e.type == SDL_QUIT || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)) {
                stop();
            }

            glm::vec4 clear_color = {0.45f, 0.55f, 0.60f, 1.00f};

            ImGui::Text("Hello, World!");

            glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
            glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui::Render();
            SDL_GL_SwapWindow(window_handle->get());
        }
    }
}
