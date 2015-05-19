//
//  COldMaidGame.h
//  Tramp
//
//  Created by TskGunGun on 2015/02/26.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#ifndef __Tramp__COldMaidGame__
#define __Tramp__COldMaidGame__

#include <stdio.h>
#include "CustomGame.h"

namespace TRUMPGAME{
class COldMaidGame : public CustomGame
{
public:
    COldMaidGame();
    virtual ~COldMaidGame();
    
    
    virtual bool OnRun();
 
protected:
    virtual bool Initialize();
    virtual int DoOperation();
    virtual void EndGame( int nIndex );
    void RemoveSameNumber( CPlayer* pPlayer );
};
}
#endif /* defined(__Tramp__COldMaidGame__) */
