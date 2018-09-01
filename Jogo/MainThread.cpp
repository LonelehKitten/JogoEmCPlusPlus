#include "MainThread.h"


using namespace std::chrono;

void MainThread::start(SDL_Renderer& renderer) {
    is_actived = true;
    is_running = true;
    gameloop(renderer);
}

void MainThread::stop() {
    is_actived = false;
    is_running = false;
}

void MainThread::pause() {
    is_running = false;
}

void MainThread::resume() {
    is_running = true;
}

void MainThread::sleep(Uint32 milliseconds) {
    SDL_Delay(milliseconds);
}

void MainThread::gameloop(SDL_Renderer& renderer) {
    long int start_time;
    long int time_millis = 1000 / MAX_FPS;
    long int wait_time;
    int frame_count = 0;
    long int total_time = 0;
    long int target_time = 1000 / MAX_FPS;
    
    while(is_actived){
        SDL_RenderClear(&renderer);
        
        start_time = (long int) duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
        
        
        if(is_running){
            if(!gpanel.eventHandler()) stop();    // RETORNA FALSE SE FECHAR A JANELA
            gpanel.update();                      // ATUALIZA O ANDAMENTO DO GAME
            gpanel.draw(renderer);                        // DESENHA O GAME NA TELA
        }
        
        time_millis = (long int)(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count() - start_time) / 1000000;
        wait_time = target_time - time_millis;
        
        if(wait_time > 0) sleep(wait_time);
        
        total_time += (long int) duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count() - start_time;
        frame_count++;
        
        if(frame_count == MAX_FPS){
            average_FPS = 1000 / ((total_time / frame_count) / 1000000);
            frame_count = 0;
            total_time = 0;
            std::cout << average_FPS << std::endl;
        }
        
        SDL_RenderPresent(&renderer);
    }
}

//==================================================}>

MainThread::MainThread() {
     
}

MainThread::MainThread(const MainThread& orig) {
}

MainThread::~MainThread() {
}

