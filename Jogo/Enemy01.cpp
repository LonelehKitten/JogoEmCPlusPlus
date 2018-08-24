#include "Enemy01.h"


void Enemy01::update(Player& player) {
    
}

void Enemy01::draw(SDL_Renderer& renderer) {
    
    if(!sprite_load){ sprite = TextureManager::load("assets/enemy01.png", &renderer); sprite_load = true; }
    
    SDL_RenderCopy(&renderer, sprite, NULL, &bounds);
}

//========================================}>

void Enemy01::create(int x, int y, unsigned int width, unsigned int height, unsigned int max_health) {
    this->bounds.x = x;
    this->bounds.y = y;
    this->bounds.w = width;
    this->bounds.h = height;
    this->max_health = max_health;
    this->health = this->max_health;
}


Enemy01::Enemy01() {
    this->bounds.x = 0;
    this->bounds.y = 0;
    this->bounds.w = 0;
    this->bounds.h = 0;
    this->max_health = 0;
    this->health = 0;
}

Enemy01::Enemy01(const Enemy01& orig) {
}

Enemy01::~Enemy01() {
}

