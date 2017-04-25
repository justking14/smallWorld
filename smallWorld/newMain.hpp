//
//  newMain.hpp
//  Physics
//
//  Created by Justin Buergi on 3/7/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//

#ifndef newMain_hpp
#define newMain_hpp



#include "cSDL_setup.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>


#include <stdio.h>
#include <fstream>
#include <vector>

#include <string>

#include "cSprite.hpp"
#include "FarmTile.hpp"
#include "monsterSpawn.hpp"
#include "monsters.hpp"
#include "Player.hpp"
#include "Arrows.hpp"

class newMain{
public:
    newMain(int passed_ScreenWidth, int passed_ScreenHeight, int lv);
    ~newMain(void);
    
    void fireArrow();
    int currentNumberOfTiles;
    void reset();
    void checkForCollisions();
    
    bool canFire = true;
    int lastGeneratedEnemy = -1;
    int numberOfArrows;
    
    const int startArrowCount = 14;
    
    const int monsterSpawnTime1 = 2000;
    const int monsterSpawnTime2 = 1000;
    const int monsterSpawnTime3 = 1000;
    
    
    bool canTouch = true;
    Player* player;
    std::vector<monster*> enemies;
    std::vector<monsterSpawn*> monsterSpawners;
    
    std::vector<FarmTile*> tiles;
    std::vector<Arrow*> arrows;
    
    std::vector<cSprite*> others;
    
    void createTile(int X, int Y);
    void spawnMonsters();
    
    void DrawTiles(int numOfTiles);
    
    void GameLoop();
    void updateTime();
    void updateGame(float dt);
    
    
    void FIREyouRATbastiard(int myX, int myY, int xCor, int yCor);
    bool quit;
    
    struct Vec2{
        float x;
        float y;
    };
    
    SDL_Texture* Message;
    SDL_Rect Message_rect;
    
    SDL_Texture* text;
    SDL_Rect renderQuad;
    
    SDL_Rect Message_rect2;
    SDL_Rect Message_rect3;
    
    
    int highScore = 0;
    
    SDL_Color textColor;
    TTF_Font* font;

    float Distance( Vec2 a, Vec2 b ){
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }
private:
    int ScreenWidth;
    int ScreenHeight;
    
    SDL_setup* csdl_setup;
};

#endif
