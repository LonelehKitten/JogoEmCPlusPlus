#include <locale.h>

#include "Game.h"


int main(int argc, char** argv) {
    setlocale(LC_ALL, "portuguese");
    Game *game  = new Game("Meu Jogo de Nave", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    return 0;
}

