#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <fstream>
#include <iostream>

#include "Stage.h"

using namespace std;

class Level{
public:
    explicit Level(Stage *);
    ~Level();
    void start();
    void next(string&);
    void finish();
    void update();
    int getEnemyNumber(); // lended method of Enemie class to Level class
private:
    int level_number;
    string level_name;
    fstream level;
    Stage *stage;
};

#endif // LEVEL_H
