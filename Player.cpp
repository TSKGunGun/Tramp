//
//  Player.cpp
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#include "Player.h"

using namespace Player;

CPlayer::CPlayer( const string& rName, bool bHuman ) : m_sName(rName), m_bHuman(bHuman)
{
}

CPlayer::CPlayer( const CPlayer& rPlayer ) : m_sName(rPlayer.m_sName), m_bHuman( rPlayer.m_bHuman )
{
}

bool CPlayer::IsShowDown()
{
    return m_Deck.IsLastOneJoker();
}

CPlayers::CPlayers()
{
}

CPlayers::~CPlayers()
{
}

void CPlayers::add( const string& rName, bool bHuman )
{
    add( CPlayer( rName, bHuman ));
}

void CPlayers::add( const CPlayer& rPlayer )
{
    CPlayer* pPlayer = new CPlayer( rPlayer );
    m_PlayerAry.push_back( pPlayer );
}

int CPlayers::GetCount() const
{
    return static_cast<int>( m_PlayerAry.size() );
}

CPlayer* CPlayers::GetAt( int nIndex )
{
    return m_PlayerAry.at( nIndex );
}

void CPlayers::RemoveAt( int nIndex )
{
    m_PlayerAry.erase(m_PlayerAry.begin()+nIndex);
}

void CPlayers::RemoveAll()
{
    m_PlayerAry.clear();
}
