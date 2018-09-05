#include "EnemiesManager.h"

void EnemiesManager::enemies_config(){
    if((wave_ticks == wave_max_ticks) && (wave_line < 10)){
        string line;
        level->next(line);
        const char* l = line.data();
        pos = GlobalConstants::getProportionalResolutionOf(25);
        for(int i = 0; i < line.length(); i++){
            if(l[i] == '0'){
                pos += GlobalConstants::getProportionalResolutionOf(24);
            }
            else if(l[i] == 'x'){
                cout << id << endl;
                pos += GlobalConstants::getProportionalResolutionOf(24);
                this->create(pos, -50, 50, 50, 1);
                id++;
                enemie_number++;
            }

            if(l[i] == '-' && l[i+1] == 'd'){
                if(l[i+3] != 'n'){
                    stringstream ss;
                    if(l[i+4] != '}'){
                        int k = 3;
                        while(l[i+k] != '}'){
                            ss << l[i+k];
                            k++;
                        }
                        ss >> wave_max_ticks;
                    }
                    else{
                        ss << l[i+3];
                        ss >> wave_max_ticks;
                    }
                }
                else{
                    wave_max_ticks = 0;
                }
                wave_ticks = 1;
                break;
            }
        }
        wave_line++;
        if(wave_line == 10) level->finish();
    }
}


void EnemiesManager::update(Player& player) {

    if(wave_line != 10) this->enemies_config();

    if(this->enemie_number > 0){
        cout << "chegou aki" << endl;
        //enemies movements updates

        for(int j = 0; j < enemie_number; j++){

            if(this->enemies[j].get()->launch){

                //===========================================================

                if(this->enemies[j].get()->getBounds().y > (GlobalConstants::getGameScreenHeight() + (100*GlobalConstants::getGameScreenHeight())/500) || this->enemies[j].get()->getHealth() == 0){
                    vector<unique_ptr<Enemy>>::iterator it = this->enemies.begin();
                    this->enemies.erase(it+j);
                    this->enemie_number--;
                    this->id--;
                    it.~__normal_iterator();
                }

                if(enemie_number == j) j--;

                //===========================================================

                for(int h = 0; h < enemie_number; h++){
                    cout  << ">>> "<< h+1 << "º " << "Enemie:  "<< this->enemies[h].get()->getBounds().y << endl;
                }
                cout << endl;

                cout << "turn: " << j << ", n: " << enemie_number << endl;

                if(enemie_number > 0){

                    if((this->enemies[j].get()->getBounds().y + this->enemies[j].get()->getBounds().h) > 0){
                        for(int k = 0; k < MAX_BULLETS; k++){
                            if(player.getBullets()[k].actived){
                                if(((this->enemies[j].get()->getBounds().x <= player.getBullets()[k].bounds.x) && ((this->enemies[j].get()->getBounds().x + this->enemies[j].get()->getBounds().w) >= player.getBullets()[k].bounds.x))
                                        ||((this->enemies[j].get()->getBounds().x <= player.getBullets()[k].bounds.w) && ((this->enemies[j].get()->getBounds().x + this->enemies[j].get()->getBounds().w) >= (player.getBullets()[k].bounds.x + player.getBullets()[k].bounds.w)))){
                                    if(((this->enemies[j].get()->getBounds().y + this->enemies[j].get()->getBounds().h) >= player.getBullets()[k].bounds.y) && (this->enemies[j].get()->getBounds().y <= player.getBullets()[k].bounds.y)){
                                        this->enemies[j].get()->setHealth(0);
                                    }
                                }
                            }
                        }
                    }

                    this->enemies[j].get()->setBounds(
                            this->enemies[j].get()->getBounds().x,
                            this->enemies[j].get()->getBounds().y+GlobalConstants::getProportionalResolutionOf(2),
                            this->enemies[j].get()->getBounds().w,
                            this->enemies[j].get()->getBounds().h
                            );
                }
            }

        }
    }
    cout << "tick: " << wave_ticks << endl;

    if(wave_line != 10)wave_ticks++;
}

void EnemiesManager::draw(SDL_Renderer& renderer) {
    
    for(int i = 0; i < enemie_number; i++){
        if(!this->enemies[i].get()->isSpriteLoaded()){
            cout << "sprite " << i << ": " << this->enemies[i].get()->isSpriteLoaded() << endl;
            this->enemies[i].get()->setTexture(*TextureManager::load("assets/enemy01.png", &renderer));
        }
        if(this->enemies[i].get()->launch){
            SDL_RenderCopy(&renderer, &this->enemies[i].get()->getTexture(), nullptr, &this->enemies[i].get()->getBounds());
        }
    }
}

//========================================}>

void EnemiesManager::create(int x, int y, unsigned int width, unsigned int height, unsigned int max_health) {
    this->enemies.emplace_back(new Enemy);
    this->enemies[id].get()->setBounds(
                x,
                y,
                GlobalConstants::getProportionalResolutionOf(width),
                GlobalConstants::getProportionalResolutionOf(height)
                );
    this->enemies[id].get()->setMaxHealth(max_health);
    this->enemies[id].get()->setHealth(enemies[id].get()->getMaxHealth());
    this->enemies[id].get()->launch = true;
}


EnemiesManager::EnemiesManager(Level *level) {
    this->level = level;
    this->level->start();
    this->id = 0;
    this->wave_line = 0;
    this->wave_max_ticks = 30;
    this->wave_ticks = 0;
    this->enemie_number = 0;
    cout << "Screen Width: " << GlobalConstants::getGameScreenWidth() << endl;
    cout << "Screen Height: " << GlobalConstants::getGameScreenHeight() << endl;
}

EnemiesManager::~EnemiesManager() {
}

//========================================================================



