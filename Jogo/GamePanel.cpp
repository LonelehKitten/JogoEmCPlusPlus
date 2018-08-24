#include "GamePanel.h"

bool GamePanel::eventHandler() {
    while(SDL_PollEvent(&evt)){
        if(evt.type == SDL_QUIT){
            return false;
        }
        
        player.eventHandler(evt);
    }
    return true;
}

void GamePanel::update() {
    player.update();
}

void GamePanel::draw(SDL_Renderer& renderer) {
    player.draw(renderer);
    enemy01.draw(renderer);
}

//=========================================}>

GamePanel::GamePanel() {
    player.create(50, 50, 75, 75, 100);
    enemy01.create(275, 50, 50, 50, 10);
}

GamePanel::GamePanel(const GamePanel& orig) {
}

GamePanel::~GamePanel() {
}

