#ifndef ENEMY01_H
#define ENEMY01_H

#include <SDL2/SDL_events.h>

#include "GameSolids.h"
#include "Player.h"
#include "TextureManager.h"
#include "Entity.h"

class Enemy01 : GameSolids, Entity{
public:
    Enemy01();
    Enemy01(const Enemy01& orig);
    virtual ~Enemy01();
    void update(Player&);
    void draw(SDL_Renderer&);
    void create(int, int, unsigned int, unsigned int, unsigned int);
private:
    
};

#endif /* ENEMY01_H */

