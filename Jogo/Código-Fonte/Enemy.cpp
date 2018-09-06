#include "Enemy.h"

Enemy::Enemy(){
    this->sprite_load = false;
}

Enemy::~Enemy(){

}
//SETTERS
void Enemy::setBounds(int x, int y, int w, int h){
    this->bounds.x = x;
    this->bounds.y = y;
    this->bounds.w = w;
    this->bounds.h = h;
}
void Enemy::setMaxHealth(int mhealth){
    this->max_health = mhealth;
}
void Enemy::setHealth(int health){
    this->health = health;
}
void Enemy::setState(int s){
    this->state = s;
}
void Enemy::setTexture(SDL_Texture& t){
    this->sprite = &t;
    this->sprite_load = true;
}
//GETTERS
SDL_Rect& Enemy::getBounds(){
    return this->bounds;
}
int Enemy::getMaxHealth(){
    return this->max_health;
}
int Enemy::getHealth(){
    return this->health;
}
int Enemy::getState(){
    return this->state;
}
SDL_Texture& Enemy::getTexture(){
    return *this->sprite;
}
//IS
bool Enemy::isSpriteLoaded(){
    return this->sprite_load;
}
