#include "newMain.hpp"
#include <map>
#include <numeric>

Mix_Chunk* wave = NULL;
Mix_Chunk* coin = NULL;
Mix_Chunk* land = NULL;
Mix_Chunk* fire = NULL;
Mix_Chunk* ply2 = NULL;


newMain::newMain(int passed_ScreenWidth, int passed_ScreenHeight, int lv){
    quit = false;
    
    ScreenWidth = passed_ScreenWidth;
    ScreenHeight = passed_ScreenHeight;
    
    csdl_setup = new SDL_setup(&quit, ScreenWidth, ScreenHeight);

    
    player = new Player(csdl_setup->GetRenderer(), "bowUp.png", ScreenWidth/2 - 20, ScreenHeight/2, 32, 32, 100);
    player->Up = true;
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        quit = true;
    }
    fire = Mix_LoadWAV("pluck.wav");
    land = Mix_LoadWAV("dead.wav");
    
    currentNumberOfTiles = 2;
    std:: srand(static_cast<unsigned int>(time(nullptr)));
    
}

void newMain::DrawTiles(int numOfTiles){
    int i = 0;
    int startX = ScreenWidth/2 - (numOfTiles * 0.7 * 32);
    int startY = ScreenHeight/2 + (numOfTiles/2 * 32);
    for (; i <= numOfTiles + 1; i++) {
        for (int j = 0; j <= numOfTiles + 1; j++) {
            
            if(i == 0 && j == numOfTiles + 1){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "topLeft.png",
                                                 startX + (i * 32),
                                                 startY - (j * 32),
                                                 32, 32, 100);
                others.push_back(tmpTile);
            }else if(i == 0 && j == 0){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "bottomLeft.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
            }else if(i == 0){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "left.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
            }else if(j == numOfTiles + 1 && i == numOfTiles + 1){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "topRight.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
                
            }else if(j == numOfTiles + 1){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "top.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
            }else if(i == numOfTiles + 1 && j == 0){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "bottomRight.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
            }else if(i == numOfTiles + 1){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "right.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
            }else if(j == 0){
                cSprite* tmpTile = new cSprite(csdl_setup->GetRenderer(), "bottom.png",
                                               startX + (i * 32),
                                               startY - (j * 32),
                                               32, 32, 100);
                others.push_back(tmpTile);
                
                
            }else{

            FarmTile* tmpTile = new FarmTile(csdl_setup->GetRenderer(), "farm.png",
                startX + (i * 32),
                startY - (j * 32),
            32, 32, 100);
            
            if(i == 1 && j == numOfTiles){
                player->rect.x = tmpTile->rect.x;
                player->rect.y = tmpTile->rect.y - 32;
                
                player->minX = 0;
                player->maxX = numOfTiles + 1;
                player->currentX = 1;
                
                player->minY = 0;
                player->maxY = numOfTiles + 1;
                player->currentY = 0;
            }
            
            if(i == 1){
                tmpTile->amIaLeft = true;
            }else if(i == numOfTiles){
                tmpTile->amIaRight = true;
            }
            if(j == numOfTiles){
                tmpTile->amIaTop = true;
            }else if(j == 1){
                tmpTile->amIaBottom = true;
            }
            tiles.push_back(tmpTile);
                
            }
        }
    }
}


void newMain::FIREyouRATbastiard(int myX, int myY, int X, int Y){
    monsterSpawn* bullet = new monsterSpawn(csdl_setup->GetRenderer(), "path.png", myX + (32 * X) - 5, myY + (32 * Y) + 10, 10, 10, 100);
    
    bullet->goalX = myX;// - 5;
    bullet->goalY = myY + 16;// + 5;
    
    //const float xDistance = bullet->rect.x - player->rect.x;
    //const float yDistance = bullet->rect.y - player->rect.y;
    
    //bullet->velocity.x = xDistance;//2;
    //bullet->velocity.y = yDistance;//2;
    
    monsterSpawners.push_back(bullet);
}

void newMain::spawnMonsters(){
    int i = std::rand() % monsterSpawners.size();

    while (i == lastGeneratedEnemy) {
        i = std::rand() % monsterSpawners.size();
    }
    std::cout << i << enemies.size() << std::endl;
    lastGeneratedEnemy = i;
    //for (int i = 0; i < monsterSpawners.size(); i++) {
    
    int cX = monsterSpawners[i]->rect.x;
    int cY = monsterSpawners[i]->rect.y;
    monster* bullet = new monster(csdl_setup->GetRenderer(), "DownBox.png", cX, cY, 10, 10, 100);
    bullet->goalX = monsterSpawners[i]->goalX;
    bullet->goalY = monsterSpawners[i]->goalY;
    enemies.push_back(bullet);
    //}
    std::cout << i << enemies.size() << std::endl;

}



void newMain::updateTime(){
    DrawTiles(currentNumberOfTiles);
    for (int i = 0; i < tiles.size(); i++) {
        tiles[i]->Draw();
        int X = 0;
        if(tiles[i]->amIaLeft){
            X = -5;
        }else if(tiles[i]->amIaRight){
            X = 5;
        }
        if(X != 0){
            FIREyouRATbastiard(tiles[i]->rect.x + tiles[i]->rect.w/2, tiles[i]->rect.y, X, 0);
        }
        int Y = 0;
        if(tiles[i]->amIaTop){
            Y = -5;
        }else if(tiles[i]->amIaBottom){
            Y = 5;
        }
        if(Y != 0 && tiles[i]->amIaBottom == false){
            FIREyouRATbastiard(tiles[i]->rect.x + tiles[i]->rect.w/2, tiles[i]->rect.y , 0, Y);
        }
    }
    
    const float fps = 100;
    const float dt = 1 / fps;
    float accumulator = 0;
    
    float timeOflastShot = SDL_GetTicks();
    float timeOflastMove = SDL_GetTicks();
    float endTime = 25000 + SDL_GetTicks();

    // In units seconds
    float frameStart = SDL_GetTicks();
    
    TTF_Init();
    font = TTF_OpenFont("Roboto.ttf", 24);
    textColor = { 255, 255, 255, 0 };
    numberOfArrows = startArrowCount;
    spawnMonsters();
    while (!quit && csdl_setup->GetEvent()->type != SDL_QUIT) {
        csdl_setup->Begin();
        const float currentTime = SDL_GetTicks();
        
        int score = player->score;
        std::string score_text = "Time Left: " + std::to_string((endTime - currentTime)/1000);
        
        if((endTime - currentTime)/1000 <= 0){
            if(currentNumberOfTiles <= 7){
                currentNumberOfTiles+=1;
            }
            reset();
            return;
        }
        
        SDL_Surface* textSurface2 = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
        text = SDL_CreateTextureFromSurface(csdl_setup->GetRenderer(), textSurface2);
        
        int text_width = textSurface2->w;
        int text_height = textSurface2->h;
        SDL_FreeSurface(textSurface2);
        renderQuad = { 0,0 , text_width, text_height };
        SDL_RenderCopy(csdl_setup->GetRenderer(), text, NULL, &renderQuad);
        SDL_DestroyTexture(text);
        
        
        if(player->score > highScore){
            highScore = player->score;
        }
        
        score = highScore;//player->score;
        score_text = "Arrows: " + std::to_string(numberOfArrows);
        
        SDL_Surface* textSurface4 = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
        text = SDL_CreateTextureFromSurface(csdl_setup->GetRenderer(), textSurface4);
        
        text_width = textSurface4->w;
        text_height = textSurface4->h;
        SDL_FreeSurface(textSurface4);
        renderQuad = { static_cast<int>(ScreenWidth) - text_width, static_cast<int>(0), text_width, text_height};
        SDL_RenderCopy(csdl_setup->GetRenderer(), text, NULL, &renderQuad);
        SDL_DestroyTexture(text);
        
        
        
        accumulator += currentTime - frameStart;
        frameStart = currentTime;
        
        if(currentTime - timeOflastShot > monsterSpawnTime1){
            spawnMonsters();
            timeOflastShot = currentTime;
            
        }
        if(currentTime - timeOflastMove > 500){
            
            timeOflastMove = currentTime;
            //FIREyouRATbastiard();
            for (int i = 0; i < enemies.size(); i++) {
                if(enemies[i]->Update() == true){
                    reset();
                    return;
                }
            }
            for (int i = 0; i < arrows.size(); i++) {
                arrows[i]->Update();
            }
        }
        
        if(accumulator > 0.25f){
            accumulator = 0.25f;
            
            while(accumulator > dt){
                updateGame( dt );
                accumulator -= dt;
            }
        }
        if(arrows.size() > 0){
            //std::cout << "frt" << std::endl;
            //std::cout << arrows.size() << " " << arrows[0]->rect.x << " " << arrows[0]->rect.y << std::endl;
            checkForCollisions();
            //std::cout << arrows.size() << " " << arrows[0]->rect.x << " " << arrows[0]->rect.y << std::endl;
        }
        for (int i = 0; i < others.size(); i++) {
            others[i]->Draw();
        }
        for (int i = 0; i < tiles.size(); i++) {
            tiles[i]->Draw();
        }
        for (int i = 0; i < monsterSpawners.size(); i++) {
            monsterSpawners[i]->Draw();
        }
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->Draw();
        }
        for (int i = 0; i < arrows.size(); i++) {
            arrows[i]->Draw();
        }
        player->Draw();
        csdl_setup->End();
    }
}

void newMain::checkForCollisions(){
    
    for (int j = 0; j < enemies.size(); j++) {
        int enemyCenterX = enemies[j]->rect.x + enemies[j]->rect.w/2;
        int enemyCenterY = enemies[j]->rect.y + enemies[j]->rect.h/2;
        for (int i = 0; i < arrows.size(); i++) {
            int arrowCenterX = arrows[i]->rect.x + arrows[i]->rect.w/2;
            int arrowCenterY = arrows[i]->rect.y + arrows[i]->rect.h/2;
            /*
            if (     enemies[j]->rect.x + enemies[j]->rect.w < arrows[i]->rect.x || enemies[j]->rect.x > arrows[i]->rect.x + arrows[i]->rect.w) {
            }else if(enemies[j]->rect.y + enemies[j]->rect.h < arrows[i]->rect.y || enemies[j]->rect.y > arrows[i]->rect.y + arrows[i]->rect.h){
            }else{
                */
            if(abs(enemyCenterX - arrowCenterX) <= 10 && abs(enemyCenterY - arrowCenterY) <= 10){
                delete enemies[j];
                enemies.erase(enemies.begin() + j);
                
                delete arrows[i];
                arrows.erase(arrows.begin() + i);
                
                if( Mix_PlayChannel( 4, land, 0 ) == -1 )
                {
                }
                //checkForCollisions();
                //break;
                
        
            }
        }
    }
}

void newMain::reset(){
    std::cout << "RESET " << std::endl;
    for (int i = 0; i < others.size(); i++) {
        delete others[i];
    }
    others.clear();
    
    for (int i = 0; i < tiles.size(); i++) {
        delete tiles[i];
    }
    tiles.clear();
    for (int i = 0; i < monsterSpawners.size(); i++) {
        delete monsterSpawners[i];
    }
    monsterSpawners.clear();
    for (int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies.clear();
    for (int i = 0; i < arrows.size(); i++) {
        delete arrows[i];
    }
    arrows.clear();
    player->Up = true;
    player->Down = false;
    player->Left = false;
    player->Right = false;
    
    updateTime();
}




void newMain::updateGame(float dt){
    

    switch (csdl_setup->GetEvent()->type) {
        case SDL_KEYDOWN:
            switch (csdl_setup->GetEvent()->key.keysym.sym) {
                case SDLK_RIGHT:
                    if(canTouch && player->currentX < player->maxX && (player->currentY == 0 || player->currentY == player->maxY)){
                        player->currentX = player->currentX + 1;
                        player->rect.x = player->rect.x + 32;
                        if(player->currentX == player->maxX){
                            if(player->currentY == player->minY){
                                player->Up = false;
                                player->Right = true;
                                player->currentY = player->currentY + 1;
                                player->rect.y = player->rect.y + 32;
                            }else{
                                player->Up = false;
                                player->Down = false;
                                player->Right = true;
                                player->currentY = player->currentY - 1;
                                player->rect.y = player->rect.y - 32;
                            }
                        }
                        canTouch = false;
                    }
                    break;
                case SDLK_LEFT:
                    if(canTouch && player->currentX > 0  && (player->currentY == 0 || player->currentY == player->maxY)){
                        player->currentX = player->currentX - 1;
                        player->rect.x =player->rect.x -  32;
                        canTouch = false;
                        if(player->currentX == 0){
                            player->Up = false;
                            player->Down = false;
                            if(player->currentY == player->minY){
                                player->Left = true;
                                player->currentY = player->currentY + 1;
                                player->rect.y = player->rect.y + 32;
                            }else{
                                player->Left = true;

                                player->currentY = player->currentY - 1;
                                player->rect.y = player->rect.y - 32;
                            }
                        }
                    }
                    break;
                case SDLK_UP:
                    if(canTouch && player->currentY > player->minY  && (player->currentX == 0 || player->currentX == player->maxX)){
                        player->currentY = player->currentY - 1;
                        player->rect.y = player->rect.y - 32;
                        
                        if(player->currentY == player->minY){
                            player->Left = false;
                            player->Right = false;
                            if(player->currentX == 0){
                                player->Up = true;
                                player->currentX = player->currentX + 1;
                                player->rect.x = player->rect.x + 32;
                            }else{
                                player->Up = true;
                                player->currentX = player->currentX - 1;
                                player->rect.x = player->rect.x - 32;
                            }
                        }
                        canTouch = false;
                    }
                    break;
                case SDLK_DOWN:
                    if(canTouch && player->currentY < player->maxY && (player->currentX == 0 || player->currentX == player->maxX)){
                        player->currentY = player->currentY + 1;
                        player->rect.y =player->rect.y +  32;
                      
                        if(player->currentY == player->maxY){
                            player->Left = false;
                            player->Right = false;
                            
                            if(player->currentX == 0){
                                player->Down = true;
                                player->currentX = player->currentX + 1;
                                player->rect.x = player->rect.x + 32;
                            }else{
                                player->Down = true;
                                player->currentX = player->currentX - 1;
                                player->rect.x = player->rect.x - 32;
                            }
                        }
                        
                        canTouch = false;
                    }
                    break;
                    
                case SDLK_SPACE:
                    if(canFire && numberOfArrows > 0){
                        if( Mix_PlayChannel( 4, fire, 0 ) == -1 )
                        {
                        }
                        fireArrow();
                        numberOfArrows = numberOfArrows - 1;
                        canFire = false;
                    }
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (csdl_setup->GetEvent()->key.keysym.sym) {
                case SDLK_RIGHT:
                    canTouch = true;
                    break;
                case SDLK_LEFT:
                    canTouch = true;
                    break;
                case SDLK_DOWN:
                    canTouch = true;
                    break;
                case SDLK_UP:
                    canTouch = true;
                    break;
                    
                case SDLK_SPACE:
                    canFire = true;
                default:
                    break;
            }
            
    }
}

void newMain::fireArrow(){
    if(player->currentY == player->maxY){
        Arrow* newArrow = new Arrow(csdl_setup->GetRenderer(), "downArrow.png", player->rect.x + player->rect.w/2 - 5, player->rect.y + player->rect.h , 10, 10, 100);
        
        newArrow->yVel = 1;
        
        arrows.push_back(newArrow);
    }else if(player->currentY == 0){
        Arrow* newArrow = new Arrow(csdl_setup->GetRenderer(), "upArrow.png", player->rect.x + player->rect.w/2 - 5, player->rect.y - 10, 10, 10, 100);
        
        newArrow->yVel = -1;
        
        arrows.push_back(newArrow);
    }
    if(player->currentX == 0){
        Arrow* newArrow = new Arrow(csdl_setup->GetRenderer(), "leftArrow.png", player->rect.x - 10, player->rect.y + player->rect.h/2 - 5, 10, 10, 100);
        
        newArrow->xVel = -1;
        
        arrows.push_back(newArrow);
    }else if(player->currentX == player->maxX){
        Arrow* newArrow = new Arrow(csdl_setup->GetRenderer(), "rightArrow.png", player->rect.x + player->rect.w, player->rect.y + player->rect.h/2 - 5, 10, 10, 100);
        
        newArrow->xVel = 1;
        
        arrows.push_back(newArrow);
    }
}


newMain::~newMain(void){
    //delete player;
    
    csdl_setup->~SDL_setup();
    
}
