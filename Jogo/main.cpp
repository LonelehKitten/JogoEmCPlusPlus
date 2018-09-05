#include <locale.h>

#include "GlobalConstants.h"
#include "Game.h"


int main() {
    setlocale(LC_ALL, "portuguese");
    Game *game  = new Game(
                "Meu Jogo de Nave",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                GlobalConstants::getGameScreenWidth(),
                GlobalConstants::getGameScreenHeight(),
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    game->~Game();
    return 0;
}

