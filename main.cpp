#include <iostream>
#include <vector>

#include <SDL.h>
#include "functions.cpp"

int main() {
    int resWidth = 1280;
    int resHeight = 720;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    } else {
        std::cout << "SDL initialized.\n";
    }

    window = SDL_CreateWindow(
        "Ray Casting",           // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        resWidth,                // width, in pixels
        resHeight,               // height, in pixels
        SDL_WINDOW_SHOWN         // flags - see below
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
        return 1;
    }




    std::vector< std::vector<int> > layout {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1 },
    };

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}