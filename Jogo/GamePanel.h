#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <GL/gl.h>
#include <iostream>
#include <SDL2/SDL_events.h>
#include "Player.h"
#include "Enemy01.h"



class GamePanel {
public:
    GamePanel();
    GamePanel(const GamePanel& orig);
    virtual ~GamePanel();
    bool eventHandler();
    void update();
    void draw(SDL_Renderer&);
private:
    SDL_Event evt;
    Player player;
    Enemy01 enemy01;
};

#endif /* GAMEPANEL_H */

