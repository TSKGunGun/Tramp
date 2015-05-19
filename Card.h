//
//  Card.h
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#ifndef __Tramp__Card__
#define __Tramp__Card__

#include <stdio.h>
#include <string>

using namespace std;

namespace TrumpCARD{
 
    enum TrumpMarks{
        MARK_JOKER = -1,
        MARK_SPADE,
        MARK_HEARTS,
        MARK_DIAMONDS,
        MARK_CLUBS,
    };
    
    enum TrumpNumbers{
        NUMBERS_JOKER = 0,
        NUMBERS_ONE,
        NUMBERS_TWO,
        NUMBERS_THREE,
        NUMBERS_FOUR,
        NUMBERS_FIVE,
        NUMBERS_SIX,
        NUMBERS_SEVEN,
        NUMBERS_EIGHT,
        NUMBERS_NINE,
        NUMBERS_TEN,
        NUMBERS_JACK,
        NUMBERS_QEEEN,
        NUMBERS_KING,
    };
    
#define Mark_MAX 4
#define Number_MAX 13
    
class CCard
{
public:
    CCard( TrumpMarks nMark, TrumpNumbers nNum );
    CCard( CCard& SrcCard );
    virtual ~CCard();
    //オペレータ
    bool operator ==( const CCard& SrcCard );
    
    TrumpMarks GetMark() const { return m_Mark; };
    const string GetMarkStr() const;
    TrumpNumbers GetNumber() const { return m_Number; };
    const string GetNumberStr() const;
    
    bool IsJoker() const;
    bool IsSameNumber( TrumpNumbers nNum ) const;
    
private:
    TrumpMarks m_Mark;
    TrumpNumbers m_Number;
};
    
}

#endif /* defined(__Tramp__Card__) */
