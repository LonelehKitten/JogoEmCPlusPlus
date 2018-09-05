#ifndef GAMESOLIDS_H
#define GAMESOLIDS_H

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <cmath>

class GameSolids {
public:
    GameSolids();
    GameSolids(const GameSolids& orig);
    virtual ~GameSolids();
protected:
    SDL_Rect bounds;
    SDL_Texture* sprite;
    bool sprite_load;
};

#endif /* GAMESOLIDS_H */

