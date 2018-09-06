#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <SDL2/SDL_video.h>
#include <cmath>

#ifdef __unix__
#include <X11/Xlib.h>
#elif defined(_WIN32) || defined(WIN32)
#include <window.h>
#endif

class GlobalConstants {
public:
    GlobalConstants();
    ~GlobalConstants();
    static void setFullScreenMode(SDL_Window*, Uint32);
    static int getGameScreenWidth();
    static int getGameScreenHeight();
    static int getProportionalResolutionOf(int);

private:
    static bool is_fullscreen;
    static int getDeviceScreenWidth();
    static int getDeviceScreenHeight();
    static const int GAME_SCREEN_WIDTH = 700;
    static const int GAME_SCREEN_HEIGHT = 500;
    static int DEVICE_SCREEN_WIDTH;
    static int DEVICE_SCREEN_HEIGHT;
};

#endif // GLOBALCONSTANTS_H
