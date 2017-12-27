#include <alexlib.h>
#include <sdl-window.h>
#include <sdl-gl-window.h>
#include <SDL_events.h>
#include <sdl-imgui.h>
#include <imgui.h>

namespace alexlib {
    void initialize(const std::string& title, glm::vec2 window_size) {
        window_handle = alexlib::sdl2::SDL_window::create(window_size, title);
        glwindow_handle = alexlib::sdl2::Sdl_gl_window::create(window_handle);
        alexlib::imgui::init(window_handle->get());
    }

    void start() {
        is_running = true;
        game_clock.start();
        main_loop();
    }

    void stop() {
        is_running = false;
        alexlib::imgui::shutdown();
        delete glwindow_handle;
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

            ImGui::Begin("Window Information");
            ImGui::SetWindowSize(ImVec2(200.f, 100.f));
            ImGui::Text("Window Width: %1.f", window_handle->window_size().x);
            ImGui::Text("Window Height: %1.f", window_handle->window_size().y);
            ImGui::End();

            glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
            glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui::Render();
            SDL_GL_SwapWindow(window_handle->get());
        }
    }
}
