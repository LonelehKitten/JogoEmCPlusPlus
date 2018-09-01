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




    enemies_manager->update(player);
}

void GamePanel::draw(SDL_Renderer& renderer) {
    player.draw(renderer);
    enemies_manager->draw(renderer);
}

//=========================================}>

GamePanel::GamePanel() {
    stage = new Stage;
    level = new Level(stage);
    enemies_manager = new EnemiesManager(level);
    player.create(260, 300, 75, 75, 100);
}

GamePanel::~GamePanel() {
}

