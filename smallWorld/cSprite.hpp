//
//  cSprite.hpp
//  Physics
//
//  Created by Justin Buergi on 3/7/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef cSprite_hpp
#define cSprite_hpp


#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>



#include <ctime>

class cSprite{
public:
    cSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType);
    ~cSprite(void);
    
    float posX;
    float posY;
    
    
    
    float restitution;
    float mass;
    float inv_mass;
    
    
    void Draw();
    
    void Draw2();
    
    SDL_Rect rect;
    Uint64 LAST = 0 ;
    bool hurt = false;
    
    
    int health = 300;
    int score = 0;
    
    bool goingLeft = false;
    bool goingDown = false;
    bool goingRight = false;
    bool goingUp = false;
    
    int count = 0;
    
    SDL_Texture* image;
    
    
    
private:
    SDL_Renderer* renderer;
    
};

#endif
//bool areColliding(cSprite &a, cSprite &b);

//0,0      100,0
//
//
//0,100    100,100
//upper-left corner(x,y)
//center =
