//
//  engine.cpp
//  FirstProyect
//
//  Created by Mary Palt on 8/09/24.
//

#include "engine.hpp"

#include "CoreFoundation/CoreFoundation.h"
#include <cstdio>

GameEngine::GameEngine() {
    success = true;
    quit = false;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        sprintf(errMsg, "Error while initializing SDL2: %s", SDL_GetError());
        success = false;
        return;
    }
}
GameEngine::~GameEngine() {
    SDL_Quit();
}

bool GameEngine::init(const std::string title, int width, int height) {
    if (!success) return false;
    
    // create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        sprintf(errMsg, "Error while creating window: %s", SDL_GetError());
        success = false;
    }
    if (!success) return false;
    this->width = width;
    this->height = height;
    
    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        sprintf(errMsg, "Error while creating renderer: %s", SDL_GetError());
        success = false;
    }

    return success;
}

void GameEngine::clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void GameEngine::loop() {
    SDL_Event event;
    while (!quit) {
        
        while (SDL_PollEvent(&event)) {
            handleEvent(event);
        }
        render();
        update();
        }
    }

void GameEngine::handleEvent(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        quit = true;
    }
}
