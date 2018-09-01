#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "GlobalConstants.h"
#include "GameSolids.h"
#include "TextureManager.h"
#include "Entity.h"

#define MAX_BULLETS 10
#define MAX_BULLET_TICKS 5


typedef struct PlayerBullets{
    SDL_Rect bounds;
    int speed;
    bool actived;
} Bullets;

class Player : GameSolids, Entity{
public:
    
    Player();
    Player(const Player& orig);
    virtual ~Player();
    void create(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void eventHandler(SDL_Event evt);
    void update();
    void draw(SDL_Renderer&);
    
    int getX();
    int getY();
    unsigned int getWidth();
    unsigned int getHeight();
    Bullets* getBullets();
    
    
private:
    
    //event booleans
    bool move_up = false;
    bool move_down = false;
    bool move_left = false;
    bool move_right = false;
    
    //player peculiar attributes
    int speed = 16;
    bool shoot = false;
    
    //bullet controller
    int avalable_bullets = MAX_BULLETS;
    int bullet_ticks = MAX_BULLET_TICKS;
    
    //bullets
    Bullets bullets[MAX_BULLETS];
    SDL_Texture* sprite_02;
};

#endif /* PLAYER_H */

