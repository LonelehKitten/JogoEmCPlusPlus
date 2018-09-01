#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <SDL2/SDL_video.h>

#ifdef LINUX || Linux || linux || UNIX
#include <X11/Xlib.h>
#elif WIN32 || Win32 || win32
#include <window.h>
#endif

#define GAME_SCREEN_WIDTH 700
#define GAME_SCREEN_HEIGHT 500

class GlobalConstants {
    static void setFullScreenMode(SDL_Window*, Uint32);
    static int getDeviceScreenWidth();
    static int getDeviceScreenHeight();
};

#endif // GLOBALCONSTANTS_H
