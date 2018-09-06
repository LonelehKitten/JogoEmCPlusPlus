#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <GL/gl.h>
#include <iostream>
#include <SDL2/SDL_events.h>
#include <fstream>
#include <string>

#include "Stage.h"
#include "Level.h"
#include "Player.h"
#include "EnemiesManager.h"

using namespace std;

class GamePanel {
public:
    GamePanel();
    virtual ~GamePanel();
    bool eventHandler();
    void update();
    void draw(SDL_Renderer&);
private:
    SDL_Event evt;
    Stage *stage;
    Level *level;
    Player player;
    EnemiesManager *enemies_manager;
};

#endif /* GAMEPANEL_H */

