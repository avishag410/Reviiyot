#include <iostream>
#include <Hand.h>
#include <Player.h>
#include <Card.h>

using namespace std;

void PlayerType1::makeMove(){
    // search for the most-higher card
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
}
Card* PlayerType1::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType1::SearchStrategyPlayer(){
    return NULL ;
}

void PlayerType2::makeMove(){
    // search for the least-lower card
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
}

Card* PlayerType2::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType2::SearchStrategyPlayer(){
    return NULL ;
}

void PlayerType3::makeMove(){
    // counter - cyclic order

    // search for the higher card
}

Card* PlayerType3::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType3::SearchStrategyPlayer(){
    return NULL ;
}

void PlayerType4::makeMove(){
    // counter - cyclic order

    // search for the lowest card
}

Card* PlayerType4::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType4::SearchStrategyPlayer(){
    return NULL ;
}