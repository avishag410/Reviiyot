#include <iostream>
#include <vector>
#include <Hand.h>
#include <Player.h>
#include <Card.h>
#include <GameManager.h>

using namespace std;

void PlayerType1::makeMove(){
    // search for the most-higher card
    Card* card = PlayerType1::searchStrategyCard();
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)c
    Player* player = Player::gameManager->getPlayerWithMaxCards(*this);
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

void PlayerType2::makeMove(){
    // search for the least-lower card
    Card* card = PlayerType2::searchStrategyCard();
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
    Player* player = Player::gameManager->getPlayerWithMaxCards(*this);
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


void PlayerType3::makeMove(){
    // counter - cyclic order
    int total = Player::gameManager->getTotalOfPlayers();
    int next = (PlayerType3::playerIndex++) % total;
    if(next == PlayerType3::selfPosition)
        next = (next++) % total;
    PlayerType3::playerIndex = next;
    Player* toAsk = Player::gameManager->getPlayerByPosition(next);
    // search for the higher card

}

Card* PlayerType3::searchStrategyCard(){
    return NULL ;
}

void PlayerType4::makeMove(){
    // counter - cyclic order
    int total = Player::gameManager->getTotalOfPlayers();
    int next = (PlayerType4::playerIndex++) % total;
    if(next == PlayerType4::selfPosition)
        next = (next++) % total;
    PlayerType4::playerIndex = next;
    Player* toAsk = Player::gameManager->getPlayerByPosition(next);

    // search for the lowest card
}

Card* PlayerType4::searchStrategyCard(){
    return NULL ;
}