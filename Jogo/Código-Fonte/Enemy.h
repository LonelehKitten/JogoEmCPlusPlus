#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "GameSolids.h"

class Enemy: GameSolids, Entity {
public:
    Enemy();
    ~Enemy();
    bool launch;
    //SETTERS
    void setBounds(int, int, int, int);
    void setMaxHealth(int);
    void setHealth(int);
    void setState(int);
    void setTexture(SDL_Texture&);
    //GETTERS
    SDL_Rect& getBounds();
    int getMaxHealth();
    int getHealth();
    int getState();
    SDL_Texture& getTexture();
    //IS
    bool isSpriteLoaded();
};

#endif // ENEMY_H
