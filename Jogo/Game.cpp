#include "Game.h"

void Game::close() {
    SDL_Delay(1000);
    SDL_Quit();
}

Game::Game(const char* title, int x, int y, unsigned int width, unsigned int height, Uint32 flags) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
        glEnable(GL_MULTISAMPLE);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        main_thread.start(*renderer);
        close();
    }
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

