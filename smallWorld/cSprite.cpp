//
//  cSprite.cpp
//  Physics
//
//  Created by Justin Buergi on 3/7/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#include "cSprite.hpp"

cSprite::cSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType){
    
    health = health * (physicType * 0.25);
    
    renderer = passed_renderer;
    
    image = NULL;
    IMG_Init(IMG_INIT_PNG);
    image = IMG_LoadTexture(passed_renderer, FilePath.c_str());
    
    
    if(image == NULL){
        std::cout << " Couldnt load im " << FilePath.c_str() << std::endl;
    }
    
    rect.x = x;
    rect.y = y;
    
    rect.w = w;
    rect.h = h;
}

void cSprite::Draw(){
        SDL_RenderCopy(renderer, image, NULL, &rect);;
}







cSprite::~cSprite(void){
    SDL_DestroyTexture(image);
    
    rect.x = NULL;
    rect.y = NULL;
    rect.w = NULL;
    rect.h = NULL;
    
    LAST = NULL;
    
    image = NULL;
    renderer = NULL;
}
