#include "Game.h"

void Game::close() {
    GlobalConstants::setFullScreenMode(window, 0);
    SDL_Delay(1000);
    SDL_Quit();
}

Game::Game(const char* title, int x, int y, unsigned int width, unsigned int height, Uint32 flags) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        char opt;

        cout << "Do you want to play in fullscreen mode?[y/n]    ";
        cin >> opt;
        cout << endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(opt == 'y' || opt == 'Y')GlobalConstants::setFullScreenMode(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        //=======================================================================================================================================================
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

