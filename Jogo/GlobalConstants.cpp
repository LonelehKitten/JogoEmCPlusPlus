#include "GlobalConstants.h"

bool GlobalConstants::is_fullscreen = false;

int GlobalConstants::DEVICE_SCREEN_WIDTH = 0;
int GlobalConstants::DEVICE_SCREEN_HEIGHT = 0;

void GlobalConstants::setFullScreenMode(SDL_Window* window, Uint32 flags){
    SDL_SetWindowFullscreen(window, flags);
    GlobalConstants::is_fullscreen = true;
}

int GlobalConstants::getDeviceScreenWidth(){
    if(GlobalConstants::DEVICE_SCREEN_WIDTH == 0){
#ifdef __unix__
    Display * display = XOpenDisplay(nullptr);
    Screen * screen = DefaultScreenOfDisplay(display);
    GlobalConstants::DEVICE_SCREEN_WIDTH = screen->width;
    delete screen;
#elif defined(_WIN32) || defined(WIN32)
    h = getSystemMetrics(SM_CXSCREEN);
#endif
    }
    return GlobalConstants::DEVICE_SCREEN_WIDTH;
}

int GlobalConstants::getDeviceScreenHeight(){
    if(GlobalConstants::DEVICE_SCREEN_HEIGHT == 0){
#ifdef __unix__
    Display * display = XOpenDisplay(nullptr);
    Screen * screen = DefaultScreenOfDisplay(display);
    GlobalConstants::DEVICE_SCREEN_HEIGHT = screen->height;
    delete screen;
#elif defined(_WIN32) || defined(WIN32)
    h = getSystemMetrics(SM_CYSCREEN);
#endif
    }
    return GlobalConstants::DEVICE_SCREEN_HEIGHT;
}

int GlobalConstants::getGameScreenWidth(){
    int w = 0;
    if(GlobalConstants::is_fullscreen){
        w = GlobalConstants::getDeviceScreenWidth();
    }
    else{
        w = GlobalConstants::GAME_SCREEN_WIDTH;
    }
    return w;
}

int GlobalConstants::getGameScreenHeight(){
    int h = 0;
    if(GlobalConstants::is_fullscreen){
        h = GlobalConstants::getDeviceScreenHeight();
    }
    else{
        h = GlobalConstants::GAME_SCREEN_HEIGHT;
    }
    return h;
}

int GlobalConstants::getProportionalResolutionOf(int n){
    return (int) ceil((n*ceil(sqrt((pow(getGameScreenWidth(), 2) + pow(getGameScreenHeight(), 2)))))/ceil(sqrt((pow(GAME_SCREEN_WIDTH, 2) + pow(GAME_SCREEN_HEIGHT, 2)))));
}
