//
//  CardDeck.cpp
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#include "CardDeck.h"
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace TrumpCARD;

CCardDeck::CCardDeck() : m_CardAry()
{
}

CCardDeck::~CCardDeck()
{
    RemoveAll();
}

void CCardDeck::Initialize()
{
    add( MARK_JOKER, NUMBERS_JOKER );
    for( int iMark=0; iMark < Mark_MAX; iMark++ ){
        for( int iNumber=1; iNumber<= Number_MAX; iNumber++){
            add( static_cast<TrumpMarks>(iMark), static_cast<TrumpNumbers>(iNumber) );
        }
    }
}

void CCardDeck::add( TrumpMarks nMark, TrumpNumbers nNum )
{
    CCard Card( nMark, nNum );
    add( Card );
}

void CCardDeck::add( CCard Card )
{
    CCard* pCard = new CCard( Card );
    m_CardAry.push_back( pCard );
}

int CCardDeck::GetCount() const
{
    return static_cast<int>( m_CardAry.size() );
}

CCard* CCardDeck::GetAt( int nIndex )
{
    return m_CardAry.at( nIndex );
}

void CCardDeck::RemoveAt( int nIndex )
{
    //CCard* pCard = GetAt(nIndex);
    //delete pCard;
    m_CardAry.erase( m_CardAry.begin()+nIndex );
}

void CCardDeck::RemoveAll()
{
    for( int ii = 0; ii < GetCount(); ii++ )
        RemoveAt(ii);

    m_CardAry.clear();
}

bool CCardDeck::MoveDeck( int nIndex, CCardDeck& rDeck )
{
    CCard* pCard = GetAt(nIndex);
    if( !pCard ) return false;
    
    rDeck.add( *pCard );
    RemoveAt( nIndex );
    return true;
}

int CCardDeck::GetSameNumberIndex( CCard* pCard )
{
    for( int ii=0; ii < GetCount(); ii++ ){
        CCard* pDirCard = GetAt(ii);
        if( pCard == pDirCard ) continue;
        if( pDirCard->IsSameNumber( pCard->GetNumber() ) )
            return ii;
    }
    return -1;
}

bool CCardDeck::IsLastOneJoker()
{
    return 1 == GetCount() && MARK_JOKER ==  GetAt(0)->GetMark();
}

void CCardDeck::Shuffle()
{
    srand(static_cast<uint>(std::time(nullptr)) );
    int n=rand() % 10;
    
    for( int ii=0; ii < n; ii++ )
        std::random_shuffle( m_CardAry.begin(), m_CardAry.end());
}

void CCardDeck::Deal( vector<CCardDeck*>& rDecks )
{
    int nPlayers = static_cast<int>(rDecks.size() );
    for( int ii=0; ii < nPlayers -1; ii++ ){
        CCardDeck* pDeck = rDecks.at(ii);
        pDeck->RemoveAll();
    }
    
    int nNowPlayer = 0;
    int CardCount = GetCount();
    for( int ii=0; ii < CardCount; ii++ ){
        CCardDeck* pDeck = rDecks.at(nNowPlayer);
        if( !MoveDeck( 0, *pDeck ) )  printf("Move失敗！");
        nNowPlayer = nNowPlayer == nPlayers -1 ? 0 : nNowPlayer+1;
    }
    
}

//Debug用
void CCardDeck::PrintCards()
{
    for( int ii=0; ii < GetCount(); ii++ )
    {
        CCard* pCard = GetAt(ii);
        std::cout << pCard->GetMarkStr() << pCard->GetNumberStr() << endl;
    }
}
