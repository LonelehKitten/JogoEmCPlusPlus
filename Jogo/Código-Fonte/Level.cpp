#include "Level.h"

void Level::start(){
    level_name = ("0" + to_string(stage->getLevelNumber()));
    level.open(level_name);
}

void Level::next(string& line){
    getline(level, line);
}

void Level::finish(){
    level.close();
}

void Level::update(){

}

//====================================

int Level::getEnemyNumber(){
    int number = 0;
    if(level.is_open()){
        level.seekg(0, level.end);
        int length = static_cast<int>(level.tellg());
        char* data = new char[length];
        level.seekg(0, level.beg);
        level.read(data, length);
        for(int i = 0; i < length; i++){
            if(data[i] == 'x')number++;
        }
        level.seekg(0, level.beg);
    }
    return number;
}

//====================================

Level::Level(Stage *stage){
    this->stage = stage;
}

Level::~Level(){

}
