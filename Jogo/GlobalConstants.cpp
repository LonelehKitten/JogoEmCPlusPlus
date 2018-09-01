#include "GlobalConstants.h"

void GlobalConstants::setFullScreenMode(SDL_Window* window, Uint32 flags){
    SDL_SetWindowFullscreen(window, flags);

    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode(0, &dm);
    dm.
}

int GlobalConstants::getDeviceScreenWidth(){
    int w = 0;
    #ifdef LINUX || Linux || linux || UNIX
    Display * display = XOpenDiplay(NULL);
    Screen screen = DefaultScreenOfDisplay(display);
    w = screen->width;
    #elif WIN32 || Win32 || win32
    w = getSystemMetrics(SM_CXSCREEN);
    #endif
    return w;
}

int GlobalConstants::getDeviceScreenHeight(){
    int h = 0;
    #ifdef LINUX || Linux || linux || UNIX
    Display * display = XOpenDiplay(NULL);
    Screen screen = DefaultScreenOfDisplay(display);
    h = screen->height;
    #elif WIN32 || Win32 || win32
    h = getSystemMetrics(SM_CYSCREEN);
    #endif
    return h;
}
