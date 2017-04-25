//
//  FarmTile.hpp
//  smallWorld
//
//  Created by Justin Buergi on 4/21/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef FarmTile_hpp
#define FarmTile_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>



#include <ctime>

class FarmTile{
public:
    FarmTile(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int physicType);
    ~FarmTile(void);
        
    void Draw();
    
    bool amIaLeft = false;
    bool amIaRight = false;
    bool amIaTop = false;
    bool amIaBottom = false;
    
    
    SDL_Rect rect;
    Uint64 startTime = 0 ;
    bool hurt = false;
    float health = 100;
    
    SDL_Texture* image;
    SDL_Texture* downImage;
private:
    SDL_Renderer* renderer;
    
};
#endif /* FarmTile_hpp */
