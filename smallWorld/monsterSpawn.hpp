//
//  monsterSpawn.hpp
//  smallWorld
//
//  Created by Justin Buergi on 4/22/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef monsterSpawn_hpp
#define monsterSpawn_hpp

#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>



#include <ctime>

class monsterSpawn{
public:
    monsterSpawn(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType);
    ~monsterSpawn(void);
    
    float goalX;
    float goalY;
    
    
    
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
#endif /* monsterSpawn_hpp */
