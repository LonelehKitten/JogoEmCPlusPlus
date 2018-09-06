#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>


class TextureManager {
public:
    static SDL_Texture* load(const char*, SDL_Renderer*);
    TextureManager();
    TextureManager(const TextureManager& orig);
    virtual ~TextureManager();
private:

};

#endif /* TEXTUREMANAGER_H */

