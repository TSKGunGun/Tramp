//
//  CustomGame.h
//  Tramp
//
//  Created by TskGunGun on 2015/02/26.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#ifndef __Tramp__CustomGame__
#define __Tramp__CustomGame__

#include <stdio.h>
#include "Player.h"

using namespace Player;
namespace TRUMPGAME{

class CustomGame
{
public:
    CustomGame(){};
    virtual ~CustomGame(){};
    
    virtual bool OnRun()=0;
    
protected:
    CPlayers m_Players;
    
    virtual bool Initialize()=0;
    virtual int DoOperation()=0;
};







}
#endif /* defined(__Tramp__CustomGame__) */
