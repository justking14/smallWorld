//
//  Player.cpp
//  smallWorld
//
//  Created by Justin Buergi on 4/22/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#include "Player.hpp"

Player::Player(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType){
    
    health = health * (physicType * 0.25);
    
    renderer = passed_renderer;
    
    upImage = NULL;
    IMG_Init(IMG_INIT_PNG);
    upImage = IMG_LoadTexture(passed_renderer, FilePath.c_str());
    downImage = IMG_LoadTexture(passed_renderer, "bowDown.png");
    leftImage = IMG_LoadTexture(passed_renderer, "bowLeft.png");
    rightImage = IMG_LoadTexture(passed_renderer, "bowRight.png");
    
    
    if(upImage == NULL){
        std::cout << " Couldnt load im " << FilePath.c_str() << std::endl;
    }
    
    rect.x = x;
    rect.y = y;
    
    rect.w = w;
    rect.h = h;
}

void Player::Draw(){
    if(Up){
        SDL_RenderCopy(renderer, upImage, NULL, &rect);;
    }else if(Down){
        SDL_RenderCopy(renderer, downImage, NULL, &rect);;
    }else if(Left){
        SDL_RenderCopy(renderer, leftImage, NULL, &rect);;
    }else if(Right){
        SDL_RenderCopy(renderer, rightImage, NULL, &rect);;
    }
}







Player::~Player(void){
    SDL_DestroyTexture(upImage);
    
    rect.x = NULL;
    rect.y = NULL;
    rect.w = NULL;
    rect.h = NULL;
    
    LAST = NULL;
    
    upImage = NULL;
    renderer = NULL;
}
