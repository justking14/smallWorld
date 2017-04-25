//
//  cSDL_setup.hpp
//  Physics
//
//  Created by Justin Buergi on 3/7/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef c_setup_hpp
#define c_setup_hpp


#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

class SDL_setup{
public:
    SDL_setup(bool* quit, int scW, int scH);
    ~SDL_setup(void);
    
    SDL_Renderer* GetRenderer();
    SDL_Event* GetEvent();
    
    void Begin();
    void End();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* mainEvent;
};

#endif
