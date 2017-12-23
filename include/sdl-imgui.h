/*
 * File: sdl_imgui.h.
 * Created by: Alex Braidwood.
 * Date: Dec 22, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef GL_BREAKOUT_SDL_IMGUI_H
#define GL_BREAKOUT_SDL_IMGUI_H

#include <GL/glew.h>

struct SDL_Window;
struct ImDrawData;
typedef union SDL_Event SDL_Event;

namespace alexlib {
    namespace imgui {
        bool init(SDL_Window* window);
        void shutdown();

        void new_frame(SDL_Window* window, float deltaTime);
        bool process_event(SDL_Event* event);
        void invalidate_device_objects();
        bool create_device_objects();
        void create_fonts_texture();
        void render_draw_lists(ImDrawData* draw_data);

        static const char* get_clipboard_text(void*);
        static void set_clipboard_text(void*, const char* text);
    }
}

// TODO: This will eventually need to be moved out elsewhere
// TODO: Gl handles are truly global
namespace alexlib {
    namespace imgui {
        namespace globals {
            static double time = 0.0f;
            static bool mouse_pressed[3] = {false, false, false};
            static float mouse_wheel = 0.0f;
            static GLuint font_texture = 0;
            static int shader_handle = 0, vert_handle = 0, fragment_handle = 0;
            static int attrib_location_texture = 0, attrib_location_proj_matrix = 0;
            static int attrib_location_position = 0, attrib_location_uv = 0, attrib_location_color = 0;
            static unsigned int vbo_handle = 0, vao_handle = 0, elements_handle = 0;
        }
    }
}


#endif //GL_BREAKOUT_SDL_IMGUI_H
