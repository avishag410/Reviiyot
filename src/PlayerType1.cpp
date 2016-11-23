#include <iostream>
#include <vector>
#include <Hand.h>
#include <Player.h>
#include <Card.h>

using namespace std;

void PlayerType1::makeMove(){
    // search for the most-higher card
    Card* card = PlayerType1::searchStrategyCard();
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)c
    Player* player = PlayerType1::searchStrategyPlayer();
    vector<Card*> given = player->giveCards(card->toString());
    if(given.size() > 0) {
        vector<Card*>::iterator it;
        for(it=given.begin() ; it < given.end(); it++ ) {
            //Hand::addCard(it);
        }
    } else{
        Player::drawCard();
    }
}


Card* PlayerType1::searchStrategyCard(){

    return NULL ;
}

Player* PlayerType1::searchStrategyPlayer(){
    return NULL ;
}

void PlayerType2::makeMove(){
    // search for the least-lower card
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
}

Card* PlayerType2::searchStrategyCard(){
    return NULL ;
}

Player* PlayerType2::searchStrategyPlayer(){
    return NULL ;
}

void PlayerType3::makeMove(){
    // counter - cyclic order

    // search for the higher card

}

Card* PlayerType3::searchStrategyCard(){
    return NULL ;
}

Player* PlayerType3::searchStrategyPlayer(){
    return NULL ;
}

void PlayerType4::makeMove(){
    // counter - cyclic order

    // search for the lowest card
}

Card* PlayerType4::searchStrategyCard(){
    return NULL ;
}

Player* PlayerType4::searchStrategyPlayer(){
    return NULL ;
}