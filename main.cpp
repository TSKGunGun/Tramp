//
//  main.cpp
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#include <iostream>
#include "COldMaidGame.h"

using namespace TRUMPGAME;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Select Game?\n Input 0 to ババ抜き\n";
    
    COldMaidGame Game;
    Game.OnRun();
    return 0;
}
