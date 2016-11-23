#include <iostream>
#include <vector>
#include <Hand.h>
#include <Player.h>
#include <Card.h>
#include "../include/Player.h"

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
    int cardsAmount =0;
    Player* result;
    vector<Player*>::iterator it;
    for(it=Player::players.begin() ; it < Player::players.end(); it++ ) {
        if(cardsAmount <= (*it)->getNumberOfCards() && this != *it) {
            cardsAmount = (*it)->getNumberOfCards();
            result = *it;
        }
    }

    return result;
}

void PlayerType2::makeMove(){
    // search for the least-lower card
    Card* card = PlayerType2::searchStrategyCard();
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
    Player* player = PlayerType2::searchStrategyPlayer();
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

Card* PlayerType2::searchStrategyCard(){
    return NULL ;
}

Player* PlayerType2::searchStrategyPlayer(){
    int cardsAmount =0;
    Player* result;
    vector<Player*>::iterator it;
    for(it=Player::players.begin() ; it < Player::players.end(); it++ ) {
        if(cardsAmount <= (*it)->getNumberOfCards() && this != *it) {
            cardsAmount = (*it)->getNumberOfCards();
            result = *it;
        }
    }

    return result;
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