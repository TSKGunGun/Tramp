//
//  Player.h
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#ifndef __Tramp__Player__
#define __Tramp__Player__

#include <stdio.h>
#include <string>
#include "CardDeck.h"

using namespace std;
using namespace TrumpCARD;
namespace Player {

class CPlayer
{
public:
    CPlayer( const string& rString, bool bHuman );
    CPlayer( const CPlayer& rPlayer );
    virtual ~CPlayer(){};

    virtual bool IsHuman() const { return m_bHuman; };
    virtual string GetName() const { return m_sName; };
    virtual void SetName( string& rName ){ m_sName=rName; };
    virtual CCardDeck* GetDeck(){ return &m_Deck; };
    
    //ババ抜き用
    bool IsShowDown();
        
protected:
    string m_sName;
    bool   m_bHuman;
    CCardDeck m_Deck;
};

class CPlayers
{
public:
    CPlayers();
    virtual ~CPlayers();
    
    virtual void add( const string& rName, bool bHuman );
    virtual void add( const CPlayer& rPlayer );
    virtual int GetCount() const;
    virtual CPlayer* GetAt( int nIndex );
    virtual void RemoveAt( int nIndex );
    virtual void RemoveAll();
    
protected:
    vector< CPlayer* > m_PlayerAry;
};
  
    
}
#endif /* defined(__Tramp__Player__) */
