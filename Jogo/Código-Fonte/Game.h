#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>

#include "MainThread.h"

class Game {
public:
    Game(const char*, int, int, unsigned int, unsigned int, Uint32);
    Game(const Game& orig);
    virtual ~Game();
private:
    void close();

    SDL_Window* window;
    SDL_Renderer* renderer;
    MainThread main_thread;
};

#endif /* GAME_H */

