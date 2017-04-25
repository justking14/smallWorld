//
//  monsters.cpp
//  smallWorld
//
//  Created by Justin Buergi on 4/22/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#include "monsters.hpp"

monster::monster(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType){
    
    health = health * (physicType * 0.25);
    
    renderer = passed_renderer;
    
    image = NULL;
    IMG_Init(IMG_INIT_PNG);
    image = IMG_LoadTexture(passed_renderer, FilePath.c_str());
    
    upImage = IMG_LoadTexture(passed_renderer, "enUp");
    downImage = IMG_LoadTexture(passed_renderer, "enDown.png");
    leftImage = IMG_LoadTexture(passed_renderer, "enLeft.png");
    rightImage = IMG_LoadTexture(passed_renderer, "enRight.png");
    
    if(image == NULL){
        std::cout << " Couldnt load im " << FilePath.c_str() << std::endl;
    }
    
    rect.x = x;
    rect.y = y;
    
    rect.w = w;
    rect.h = h;
}

void monster::Draw(){
    SDL_RenderCopy(renderer, image, NULL, &rect);;
}

bool monster::Update(){
    int distToGoalX = abs(goalX - (rect.x));
    int distToGoalY = abs(goalY - (rect.y));
    
    std::cout << distToGoalX <<  " " << distToGoalY << std::endl;
    
    if(distToGoalX > 35){
        if(goalX > rect.x){
            rect.x += 5;
            image = leftImage;
        }else{
            rect.x -= 5;
            image = rightImage;
        }
    }else if(distToGoalX != 5){
        return true;
    }
    if(distToGoalY > 35){
        if(goalY > rect.y){
            rect.y += 5;
            image = downImage;
        }else{
            rect.y -= 5;
            image = upImage;
        }
    }else if(distToGoalY != 6 && distToGoalY != 5 && distToGoalY != 0){
        return true;
    }
    
    return false;
}





monster::~monster(void){
    SDL_DestroyTexture(image);
    
    rect.x = NULL;
    rect.y = NULL;
    rect.w = NULL;
    rect.h = NULL;
    
    LAST = NULL;
    
    image = NULL;
    renderer = NULL;
}
