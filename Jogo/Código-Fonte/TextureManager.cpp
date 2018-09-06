#include "TextureManager.h"

SDL_Texture* TextureManager::load(const char* file, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(file);
    SDL_Texture* sprite = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    return sprite;
}


TextureManager::TextureManager() {
}

TextureManager::TextureManager(const TextureManager& orig) {
}

TextureManager::~TextureManager() {
}

