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

    if(!was_created){
        create((700/2) - 37, (500/2) - 37, 75, 75, 100);
        was_created = true;
    }
    
    // KEY PRESSED EVENTS

    if(move_up && !move_down){
        if(y_acc < 16) y_acc++;
        if(bounds.y > 0){
            if(bounds.y > y_acc) bounds.y -= y_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.y -= bounds.y;            // se for falso vai completar o encaixe na tela
        }
        else bounds.y = 0;
    }
    if(move_down && !move_up){
        if(y_acc > -16) y_acc--;
        if(bounds.y+bounds.h < GlobalConstants::getGameScreenHeight()){
            if(bounds.y+bounds.h < GlobalConstants::getGameScreenHeight() - y_acc) bounds.y -= y_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.y += GlobalConstants::getGameScreenHeight() - (bounds.h+bounds.y);              // se for falso vai completar o encaixe na tela
        }
        else bounds.y = GlobalConstants::getGameScreenHeight() - bounds.h;
    }
    if(move_left && !move_right){
        if(x_acc > -16) x_acc--;
        if(bounds.x > 0){
            if(bounds.x > x_acc) bounds.x += x_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.x -= bounds.x;           // se for falso vai completar o encaixe na tela
        }
        else bounds.x = 0;
    }
    if(move_right && !move_left){
        if(x_acc < 16) x_acc++;
        if(bounds.x+bounds.w < GlobalConstants::getGameScreenWidth()){
            if(bounds.x+bounds.w < GlobalConstants::getGameScreenWidth() + x_acc) bounds.x += x_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.x += GlobalConstants::getGameScreenWidth() - (bounds.w+bounds.x);             // se for falso vai completar o encaixe na tela
        }
        else bounds.x = GlobalConstants::getGameScreenWidth() - bounds.w;
    }

    //KEY RELEASED EVENTS

    if(!move_up && !move_down && y_acc > 0){
        y_acc--;
        if(bounds.y > 0){
            if(bounds.y > y_acc) bounds.y -= y_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.y -= bounds.y;            // se for falso vai completar o encaixe na tela
        }
        else bounds.y = 0;
    }
    if(!move_up && !move_down && y_acc < 0){
        y_acc++;
        if(bounds.y+bounds.h < GlobalConstants::getGameScreenHeight()){
            if(bounds.y+bounds.h < GlobalConstants::getGameScreenHeight() - y_acc) bounds.y -= y_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.y += GlobalConstants::getGameScreenHeight() - (bounds.h+bounds.y);              // se for falso vai completar o encaixe na tela
        }
        else bounds.y = GlobalConstants::getGameScreenHeight() - bounds.h;
    }
    if(!move_left && !move_right && x_acc < 0){
        x_acc++;
        if(bounds.x > 0){
            if(bounds.x > x_acc) bounds.x += x_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.x -= bounds.x;           // se for falso vai completar o encaixe na tela
        }
        else bounds.x = 0;
    }
    if(!move_left && !move_right && x_acc > 0){
        x_acc--;
        if(bounds.x+bounds.w < GlobalConstants::getGameScreenWidth()){
            if(bounds.x+bounds.w < GlobalConstants::getGameScreenWidth() - x_acc) bounds.x += x_acc; // se for verdadeiro, vai movimentar normalmente
            else bounds.x += GlobalConstants::getGameScreenWidth() - (bounds.w+bounds.x);             // se for falso vai completar o encaixe na tela
        }
        else bounds.x = GlobalConstants::getGameScreenWidth() - bounds.w;
    }
    
    //SHOOTING EVENTS

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
                    bullets[ab].bounds.x = (bounds.x+bounds.w/2)-GlobalConstants::getProportionalResolutionOf(10);
                    bullets[ab].bounds.y = bounds.y-GlobalConstants::getProportionalResolutionOf(40);
                    bullets[ab].bounds.w = GlobalConstants::getProportionalResolutionOf(20);
                    bullets[ab].bounds.h = GlobalConstants::getProportionalResolutionOf(40);
                    bullets[ab].speed = GlobalConstants::getProportionalResolutionOf(20);
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
    
    SDL_RenderCopy(&renderer, sprite, nullptr, &bounds);
    
    if(avalable_bullets < MAX_BULLETS){                                                   // verifica se existem tiros disparados
        for(int bac = 0; bac < MAX_BULLETS; bac++){
            if(bullets[bac].actived){                                                     // identifica o tiro disparado
                
                SDL_RenderCopy(&renderer, sprite_02, nullptr, &bullets[bac].bounds);
                
            }
        }
    }
}





// criação de player==============================

void Player::create(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int max_health){
    this->bounds.x = GlobalConstants::getProportionalResolutionOf(x);
    this->bounds.y = GlobalConstants::getProportionalResolutionOf(y);
    this->bounds.w = GlobalConstants::getProportionalResolutionOf(width);
    this->bounds.h = GlobalConstants::getProportionalResolutionOf(height);
    this->max_health = max_health;
    this->health = this->max_health;
    this->x_acc = 0;
    this->y_acc = 0;
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
    this->was_created = false;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

