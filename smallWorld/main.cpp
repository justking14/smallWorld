//
//  main.cpp
//  smallWorld
//
//  Created by Justin Buergi on 4/21/17.
//  Copyright © 2017 Justking Games. All rights reserved.
//


#include <iostream>
#include "newMain.hpp"

int main(int argc, const char * argv[]) {
    newMain* cmain = new newMain(21*32, 21*32, 1);
    cmain->updateTime();
    cmain->~newMain();
    
    return 0;
}

