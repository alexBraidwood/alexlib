/*
 * File: sdl_imgui.h.
 * Created by: Alex Braidwood.
 * Date: Dec 22, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef GL_BREAKOUT_SDL_IMGUI_H
#define GL_BREAKOUT_SDL_IMGUI_H

struct SDL_Window;
typedef union SDL_Event SDL_Event;

namespace alexlib {
    namespace imgui {
        bool init(SDL_Window* window);
        void shutdown();
        void new_frame(SDL_Window* window);
        void invalidate_device_objects();
        bool create_device_objects();
    }
}


#endif //GL_BREAKOUT_SDL_IMGUI_H
