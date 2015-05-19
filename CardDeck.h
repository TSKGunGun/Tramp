//
//  CardDeck.h
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#ifndef __Tramp__CardDeck__
#define __Tramp__CardDeck__

#include <stdio.h>
#include <vector>
#include "Card.h"

namespace  TrumpCARD {

class CCardDeck
{
public:
    CCardDeck();
    virtual ~CCardDeck();
    
    virtual void Initialize();
    
    virtual void add( TrumpMarks nMark, TrumpNumbers nNum );
    virtual void add( CCard Card );
    virtual int GetCount() const;
    virtual CCard* GetAt( int nIndex );
    virtual void RemoveAt( int nIndex );
    virtual void RemoveAll();
    virtual bool MoveDeck( int nIndex, CCardDeck& rDeck );
    
    int GetSameNumberIndex( CCard* pCard );
    
    virtual bool IsLastOneJoker();
    
    virtual void Shuffle();
    virtual void Deal( vector<CCardDeck*>& rDecks );
    
    //Debug用!
    void PrintCards();
    
protected:
    vector< CCard* > m_CardAry;
    
};
    
}


#endif /* defined(__Tramp__CardDeck__) */
