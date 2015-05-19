//
//  Card.cpp
//  Tramp
//
//  Created by TskGunGun on 2015/02/25.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#include "Card.h"

using namespace TrumpCARD;

CCard::CCard( TrumpMarks nMark, TrumpNumbers nNum ) : m_Mark(nMark), m_Number(nNum)
{
}

CCard::CCard( CCard& SrcCard ) : m_Mark(SrcCard.m_Mark), m_Number(SrcCard.m_Number)
{
}

CCard::~CCard()
{
}

//オペレータ
bool CCard::operator == ( const CCard& SrcCard )
{
    return m_Mark == SrcCard.m_Mark && m_Number == SrcCard.m_Number;
}

const string CCard::GetMarkStr() const
{
    switch( m_Mark ){
        case MARK_JOKER:
            return "J";
            break;
        case MARK_CLUBS:
            return "C";
            break;
    
        case MARK_DIAMONDS:
            return "D";
            break;
  
        case MARK_SPADE:
            return "S";
            break;
  
        case MARK_HEARTS:
            return "H";
            break;
            
    }
}

const string CCard::GetNumberStr() const
{
    switch( m_Number ){
        case NUMBERS_JOKER:
            return "";
            break;
        case NUMBERS_ONE:
            return "1";
            break;
            
        case NUMBERS_TWO:
            return "2";
            break;
            
        case NUMBERS_THREE:
            return "3";
            break;
            
        case NUMBERS_FOUR:
            return "4";
            break;
            
        case NUMBERS_FIVE:
            return "5";
            break;
            
        case NUMBERS_SIX:
            return "6";
            break;
            
        case NUMBERS_SEVEN:
            return "7";
            break;
            
        case NUMBERS_EIGHT:
            return "8";
            break;

        case NUMBERS_NINE:
            return "9";
            break;
            
        case NUMBERS_TEN:
            return "10";
            break;
            
        case NUMBERS_JACK:
            return "J";
            break;
            
        case NUMBERS_QEEEN:
            return "Q";
            break;
            
        case NUMBERS_KING:
            return "K";
            break;
    }
}


bool CCard::IsJoker() const
{
    return m_Mark == MARK_JOKER;
}

bool CCard::IsSameNumber( TrumpNumbers nNum) const
{
    return m_Number == nNum;
}
