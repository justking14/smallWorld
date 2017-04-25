//
//  monsterSpawn.cpp
//  smallWorld
//
//  Created by Justin Buergi on 4/22/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#include "monsterSpawn.hpp"

monsterSpawn::monsterSpawn(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType){
    
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

void monsterSpawn::Draw(){
    SDL_RenderCopy(renderer, image, NULL, &rect);;
}







monsterSpawn::~monsterSpawn(void){
    SDL_DestroyTexture(image);
    
    rect.x = NULL;
    rect.y = NULL;
    rect.w = NULL;
    rect.h = NULL;
    
    LAST = NULL;
    
    image = NULL;
    renderer = NULL;
}
