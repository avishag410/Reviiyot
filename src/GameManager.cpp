#include <iostream>
#include <vector>
#import <Player.h>
#include <Deck.h>
#include <Card.h>
#include <GameManager.h>
using namespace std;
// TODO do I really need vector of player or a pointer to a vector?
GameManager::GameManager(Deck& _deck, vector<Player*> _players): players(_players), deck(&_deck) {}

Player* GameManager::getPlayerWithMaxCards(){
    int cardsAmount =0;
    Player* result;
    vector<Player*>::iterator it;
    for(it=GameManager::players.begin() ; it < GameManager::players.end(); it++ ) {
        if(cardsAmount <= (*it)->getNumberOfCards()) {
            cardsAmount = (*it)->getNumberOfCards();
            result = *it;
        }
    }

    return result;
}
Player* GameManager::getPlayerWithMaxCards(Player &player){
    int cardsAmount =0;
    Player* result;
    vector<Player*>::iterator it1;
    for(it1=GameManager::players.begin(); it1 < GameManager::players.end(); it1++ ) {
        if(cardsAmount <= (*it1)->getNumberOfCards()) {
            cardsAmount = (*it1)->getNumberOfCards();
            result = *it1;
        }
    }

    return result;
}
Player* GameManager::getPlayerWithMinCards(){
    return  NULL;
}
Player* GameManager::getPlayerWithMinCards(Player &player){
    return  NULL;
}
Player* GameManager::getPlayerByPosition(int position){
    return  NULL;
}
Card* GameManager::getCardFromDeck(){
    return  NULL;
}
