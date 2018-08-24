#include "Player.h"

int Player::getX() { return bounds.x; }

int Player::getY() { return bounds.y; }

unsigned int Player::getWidth() { return bounds.w; }

unsigned int Player::getHeight() { return bounds.h; }

Bullets* Player::getBullets() { return bullets; }

//============================================================}>

void Player::eventHandler(SDL_Event evt) {

    if(evt.type == SDL_KEYDOWN){
        if(evt.key.keysym.sym == SDLK_w){
            move_up = true;
            state += MOVING_UP;
        }
        if(evt.key.keysym.sym == SDLK_a){
            move_left = true;
            state += MOVING_LEFT;
        }
        if(evt.key.keysym.sym == SDLK_s){
            move_down = true;
            state += MOVING_DOWN;
        }
        if(evt.key.keysym.sym == SDLK_d){
            move_right = true;
            state += MOVING_RIGHT;
        }
        if(evt.key.keysym.sym == SDLK_k){
            shoot = true;
            state += FIRING;
        }
    }
    if(evt.type == SDL_KEYUP){
        if(evt.key.keysym.sym == SDLK_w){
            move_up = false;
            state -= MOVING_UP;
        }
        if(evt.key.keysym.sym == SDLK_a){
            move_left = false;
            state -= MOVING_LEFT;
        }
        if(evt.key.keysym.sym == SDLK_s){
            move_down = false;
            state -= MOVING_DOWN;
        }
        if(evt.key.keysym.sym == SDLK_d){
            move_right = false;
            state -= MOVING_RIGHT;
        }
        if(evt.key.keysym.sym == SDLK_k){
            shoot = false;
            bullet_ticks = MAX_BULLET_TICKS;
            state -= FIRING;
        }
    }
}

void Player::update() {
    
    if(move_up){
        if(bounds.y > 0){
            if(bounds.y > speed) bounds.y -= speed; // se for verdadeiro, vai movimentar normalmente
            else bounds.y -= bounds.y;            // se for falso vai completar o encaixe na tela
        }
        else bounds.y = 0;
    }
    if(move_down){
        if(bounds.y+bounds.h < 400){
            if(bounds.y+bounds.h < 400 - speed) bounds.y += speed; // se for verdadeiro, vai movimentar normalmente
            else bounds.y += 400 - (bounds.h+bounds.y);              // se for falso vai completar o encaixe na tela
        }
        else bounds.y = 400 - bounds.h;
    }
    if(move_left){
        if(bounds.x > 0){
            if(bounds.x > speed) bounds.x -= speed; // se for verdadeiro, vai movimentar normalmente
            else bounds.x -= bounds.x;           // se for falso vai completar o encaixe na tela
        }
        else bounds.x = 0;
    }
    if(move_right){
        if(bounds.x+bounds.w < 600){
            if(bounds.x+bounds.w < 600 - speed) bounds.x += speed; // se for verdadeiro, vai movimentar normalmente
            else bounds.x += 600 - (bounds.w+bounds.x);             // se for falso vai completar o encaixe na tela
        }
        else bounds.x = 600 - bounds.w;
    }
    
    if(avalable_bullets < MAX_BULLETS){                                                              // se tiver tiros disparados
        std::cout << "Existem " << avalable_bullets << " disparos disponíveis."<< std::endl;
        for(int bac = 0; bac < MAX_BULLETS; bac++){
            std::cout << "Lendo disparo " << bac << "." << std::endl;
            if(bullets[bac].actived){                                                                // pega o tiro ativado
                std::cout << "O disparo " << bac << " está ativo." << std::endl;
                if(bullets[bac].bounds.y + bullets[bac].bounds.h > 0){                               // se y do tiro for maior q 0
                    std::cout << "O disparo " << bac << " está em movimento." << std::endl;
                    bullets[bac].bounds.y -= bullets[bac].speed;                                     // decrementa o tiro
                }
                else{                                                                                // se y do tiro for menor q 0
                    std::cout << "O disparo " << bac << " foi desativado." << std::endl;
                    bullets[bac].actived = false;                                                    // desativa o tiro
                    avalable_bullets++;                                                              // disponibiliza um tiro
                }
            }
        }
    }
    
    if(shoot){                                                                           // se "k" foi pressionado
        std::cout << "teste 2 parte 1" << std::endl;
        if(bullet_ticks == MAX_BULLET_TICKS && avalable_bullets > 0){                    // se ticks é menor q 100000000 e tiver tiros disponiveis
            std::cout << "teste 2 parte 2" << std::endl;
            for(int ab = 0; ab < MAX_BULLETS; ab++){
                std::cout << "teste 2 parte 3" << std::endl;
                if(!bullets[ab].actived){                                                // se tiro n estiver ativado ainda
                    //std::cout << "teste 2 parte 4" << std::endl;
                    bullets[ab].bounds.x = (bounds.x+bounds.w/2)-12;
                    bullets[ab].bounds.y = bounds.y-48;
                    bullets[ab].bounds.w = 24;
                    bullets[ab].bounds.h = 48;
                    bullets[ab].speed = 20;
                    bullets[ab].actived = true;

                    bullet_ticks = 0;                                                    // reseta ticks
                    avalable_bullets--;                                                  // diminui um tiro disponivel
                    break;
                }
            }

            std::cout << "teste 2 parte 5" << std::endl;

                                                     
        }
        
        bullet_ticks++;                                                                  // incrementa ticks
    }
    
    
}

void Player::draw(SDL_Renderer& renderer) {
    
    if(!sprite_load){
        sprite = TextureManager::load("assets/nave.png", &renderer);
        sprite_02 = TextureManager::load("assets/bullet.png", &renderer);
        sprite_load = true;
    }
    
    SDL_RenderCopy(&renderer, sprite, NULL, &bounds);
    
    if(avalable_bullets < MAX_BULLETS){                                                   // verifica se existem tiros disparados
        for(int bac = 0; bac < MAX_BULLETS; bac++){
            if(bullets[bac].actived){                                                     // identifica o tiro disparado
                
                SDL_RenderCopy(&renderer, sprite_02, NULL, &bullets[bac].bounds);
                
            }
        }
    }
}





// criação de player==============================

void Player::create(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int max_health){
    this->bounds.x = x;
    this->bounds.y = y;
    this->bounds.w = width;
    this->bounds.h = height;
    this->max_health = max_health;
    this->health = this->max_health;
}

Player::Player(){
    this->bounds.x = 0;
    this->bounds.y = 0;
    this->bounds.w = 0;
    this->bounds.h = 0;
    this->sprite_load = false;
    
    for(int b = 0; b < MAX_BULLETS; b++){
        bullets[b].actived = false;
    }
    
    this->health = 0;
    this->max_health = 0;
    this->state = STAYED;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

