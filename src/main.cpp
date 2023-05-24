#include <iostream>
#include <SDL2/SDL.h>

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "Init failed with error: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "Hello World!" << std::endl;

    SDL_Quit();
    
    return 0;
}