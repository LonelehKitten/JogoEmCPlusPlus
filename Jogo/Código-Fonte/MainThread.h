#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <SDL2/SDL_timer.h>
#include <chrono>
#include "GamePanel.h"

#define MAX_FPS 30

class MainThread {
public:
    MainThread();
    MainThread(const MainThread& orig);
    virtual ~MainThread();
    void start(SDL_Renderer&);
    void stop();
    void pause();
    void resume();
private:
    void gameloop(SDL_Renderer&);
    void sleep(Uint32);
    
    GamePanel gpanel;
    
    bool is_actived;
    bool is_running;
    
    double average_FPS;
    
};

#endif /* MAINTHREAD_H */

