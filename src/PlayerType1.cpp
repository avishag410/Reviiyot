#include <iostream>
#include <Hand.h>
#include <Player.h>
#include <Card.h>

using namespace std;

bool PlayerType1::makeMove(){
    // search for the most-higher card
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
    return false;
}

void PlayerType1::drawCard(){

}
Card* PlayerType1::giveCards() {
    return NULL;
}

Card* PlayerType1::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType1::SearchStrategyPlayer(){
    return NULL ;
}

bool PlayerType2::makeMove(){
    // search for the least-lower card
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
    return false;
}

void PlayerType2::drawCard(){

}
Card* PlayerType2::giveCards() {
    return NULL;
}

Card* PlayerType2::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType2::SearchStrategyPlayer(){
    return NULL ;
}

bool PlayerType3::makeMove(){
    // counter - cyclic order

    // search for the higher card

    return false;
}

void PlayerType3::drawCard(){

}
Card* PlayerType3::giveCards() {
    return NULL;
}

Card* PlayerType3::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType3::SearchStrategyPlayer(){
    return NULL ;
}

bool PlayerType4::makeMove(){
    // counter - cyclic order

    // search for the lowest card
    return false;
}

void PlayerType4::drawCard(){

}
Card* PlayerType4::giveCards() {
    return NULL;
}

Card* PlayerType4::SearchStrategyCard(){
    return NULL ;
}

Player* PlayerType4::SearchStrategyPlayer(){
    return NULL ;
}