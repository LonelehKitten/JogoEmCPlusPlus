#ifndef ENEMIES_H
#define ENEMIES_H

#include <SDL2/SDL_events.h>
#include <sstream>
#include <vector>
#include <memory>

#include "GlobalConstants.h"
#include "Player.h"
#include "TextureManager.h"
#include "Level.h"
#include "Enemy.h"


class EnemiesManager{
public:
    EnemiesManager(Level *);
    virtual ~EnemiesManager();
    void update(Player&);
    void draw(SDL_Renderer&);
    void create(int, int, unsigned int, unsigned int, unsigned int);
private:
    int enemie_number;
    int wave_line;
    int wave_max_ticks;
    int wave_ticks;
    int id;
    int pos;

    //Enemy *enemy;
    vector<unique_ptr<Enemy>> enemies;
    Level *level;

    void enemies_config();
};

#endif /* ENEMIES_H */

