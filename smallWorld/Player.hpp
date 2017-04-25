//
//  Player.hpp
//  smallWorld
//
//  Created by Justin Buergi on 4/22/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>



#include <ctime>

class Player{
public:
    Player(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType);
    ~Player(void);
    
    float posX;
    float posY;
    
    int minX;
    int currentX;
    int maxX;
    
    
    int minY;
    int currentY;
    int maxY;
    
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
    
    bool Left = false;
    bool Down = false;
    bool Right = false;
    bool Up = false;
    
    int count = 0;
    
    SDL_Texture* upImage;
    SDL_Texture* downImage;
    SDL_Texture* leftImage;
    SDL_Texture* rightImage;
    
    
private:
    SDL_Renderer* renderer;
    
};
#endif /* Player_hpp */
