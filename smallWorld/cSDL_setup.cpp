//
//  cSDL_setup.cpp
//  Physics
//
//  Created by Justin Buergi on 3/7/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#include "cSDL_setup.hpp"

SDL_setup::SDL_setup(bool* quit, int scW, int scH){
    window = NULL;
    window = SDL_CreateWindow("Hello", 0, 0, scW, scH, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    
    if (window == NULL) {
        std::cout << "window Error X3f5" << std::endl;
        *quit = true;
    }
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    mainEvent = new SDL_Event();
}

SDL_setup::~SDL_setup(void){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    delete mainEvent;
}

SDL_Renderer* SDL_setup::GetRenderer(){
    return renderer;
}

SDL_Event* SDL_setup::GetEvent(){
    return mainEvent;
}

void SDL_setup::Begin(){
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
}

void SDL_setup::End(){
    SDL_RenderPresent(renderer);
}
