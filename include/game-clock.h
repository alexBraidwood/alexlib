/*
 * File: GameClock.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef ALEXLIB_GAMECLOCK_H
#define ALEXLIB_GAMECLOCK_H

#include <chrono>

namespace alexlib {

using timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>;

struct Game_clock {
    Game_clock() : running(false) {}

    void start();

    void stop();

    float deltaTime();

    bool isRunning() const;

private:
    bool running;
    timestamp startTime;
    timestamp stopTime;
    timestamp lastDt;
};

}

#endif //ALEXLIB_GAMECLOCK_H
