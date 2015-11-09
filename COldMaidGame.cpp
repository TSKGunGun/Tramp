//
//  COldMaidGame.cpp
//  Tramp
//
//  Created by TskGunGun on 2015/02/26.
//  Copyright (c) 2015年 TskGunGun. All rights reserved.
//

#include "COldMaidGame.h"
#include <iostream>
#include <unistd.h>

using namespace TRUMPGAME;
using namespace Player;
using namespace TrumpCARD;
using namespace std;

COldMaidGame::COldMaidGame()
{
}

COldMaidGame::~COldMaidGame()
{
}

bool COldMaidGame::OnRun()
{
    Initialize();
    int nWinner = DoOperation();
    EndGame(nWinner);
    return true;
}

void COldMaidGame::EndGame(int nIndex)
{
    cout << m_Players.GetAt(nIndex)->GetName() << "の敗北です！" << endl;
}

bool COldMaidGame::Initialize()
{
    std::cout<< "プレイヤー人数２人、　プレイヤー１、CPU1でゲームを開始します。\n" << endl;
    m_Players.add( "プレイヤー１", true );
    m_Players.add( "CPU1", false );
    m_Players.add( "CPU2", false );
    
    cout<< "デッキをシャッフルして配ります...\n" << endl;
    CCardDeck Deck;
    Deck.Initialize();
    //Deck.PrintCards();
    
    Deck.Shuffle();
    //Deck.PrintCards();
    vector< CCardDeck* > Decks;  
    for( int ii = 0; ii < m_Players.GetCount(); ii++ )
        Decks.push_back( m_Players.GetAt(ii)->GetDeck() );
    
    Deck.Deal( Decks );
    
    cout<< "同じ番号のカードを捨てます..\n" << endl;
    for( int ii = 0; ii < m_Players.GetCount(); ii++ )
        RemoveSameNumber( m_Players.GetAt(ii) );
    
    //Debug用
    /*for( int ii = 0; ii < m_Players.GetCount(); ii++ ){
        cout << m_Players.GetAt(ii)->GetName() << " : Have Cards" << endl;
        m_Players.GetAt(ii)->GetDeck()->PrintCards();
    }
    */
    
    
    return true;
}

int COldMaidGame::DoOperation()
{
    //最初からアガリ状態もありえるのでアガリ判定します。
    for( int ii = 0; ii < m_Players.GetCount(); ii++ ){
        if( m_Players.GetAt(ii)->IsShowDown() )
            return ii;
    }
    
    int nActivePlayer=0;
    while(1){
        int nLoadPlayer = ( nActivePlayer == 0? m_Players.GetCount()-1 : nActivePlayer-1 );
        CPlayer* pActPlayer = m_Players.GetAt(nActivePlayer);
        CPlayer* pLoadPlayer = m_Players.GetAt(nLoadPlayer);
        
        if( pActPlayer->IsHuman() ){
            cout << pActPlayer->GetName() << "  :   " << pLoadPlayer->GetName() << "のカードを選択します。\n" << "0~" << m_Players.GetAt(nLoadPlayer)->GetDeck()->GetCount()-1 << "の数を指定してください。" << endl;
        }
        else{
            cout << pActPlayer->GetName() << "  :  "<< pLoadPlayer->GetName() <<"のカードを選択中です"<<flush;
            for( int ii =0; ii < 3; ii++ ){
                usleep(750000);
                cout << "."<<flush;
            }
            cout << endl;
        }
        
        nActivePlayer = nActivePlayer == m_Players.GetCount()-1 ? 0 : nActivePlayer + 1;
    }
    return 1;
}

void COldMaidGame::RemoveSameNumber( CPlayer* pPlayer )
{
    CCardDeck* pDeck = pPlayer->GetDeck();
    for( int ii=0; ii < pDeck->GetCount(); ii++ ){
        CCard* pSrcCard = pDeck->GetAt(ii);
        int nIndex = pDeck->GetSameNumberIndex( pSrcCard );
        if( 0 <= nIndex ){
            CCard* pDirCard = pDeck->GetAt(nIndex);
            cout<< pPlayer->GetName() << ": " << pSrcCard->GetMarkStr() << pSrcCard->GetNumberStr() <<"と"
            << pDirCard->GetMarkStr() << pDirCard->GetNumberStr() << "を捨てます。" <<endl;
            pDeck->RemoveAt(nIndex);
            pDeck->RemoveAt(ii);
            ii--;
        }
    }
}
