#include <iostream>
#include <vector>
#import <Player.h>
#include <Deck.h>
#include <Card.h>
#include <GameManager.h>
using namespace std;
// TODO do I really need vector of player or a pointer to a vector?
GameManager::GameManager(Deck& _deck):deck(&_deck) {}

GameManager::GameManager(const GameManager& other){
   GameManager::copy(other);
}

void GameManager::setPlayers(vector<Player*> _players){
    players = _players;
}

Player* GameManager::getPlayerWithMaxCards(){
    int cardsAmount =0;
    Player* result;
    vector<Player*>::iterator it;
        for(it=players.begin() ; it < players.end(); it++ ) {
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
    for(it1=players.begin(); it1 < players.end(); it1++ ) {
        if(cardsAmount <= (*it1)->getNumberOfCards() && &player != *it1) {
            cardsAmount = (*it1)->getNumberOfCards();
            result = *it1;
        }
    }

    return result;
}
Player* GameManager::getPlayerWithMinCards(){
    int cardsAmount = INT_MAX;
    Player* result;
    vector<Player*>::iterator it1;
    for(it1=players.begin(); it1 < players.end(); it1++ ) {
        if(cardsAmount > (*it1)->getNumberOfCards()) {
            cardsAmount = (*it1)->getNumberOfCards();
            result = *it1;
        }
    }

    return result;
}
Player* GameManager::getPlayerWithMinCards(Player &player){
    int cardsAmount = INT_MAX;
    Player* result;
    vector<Player*>::iterator it1;
    for(it1=players.begin(); it1 < players.end(); it1++ ) {
        if(cardsAmount > (*it1)->getNumberOfCards() && &player != *it1) {
            cardsAmount = (*it1)->getNumberOfCards();
            result = *it1;
        }
    }

    return result;
}
Player* GameManager::getPlayerByPosition(int position){
    if(position < players.size())
        return  players[position];
    else
        return NULL;
}
Card* GameManager::getCardFromDeck(){
    return  deck->fetchCard();
}

int GameManager::getTotalOfPlayers(){
    return players.size();
}


GameManager &GameManager::operator=(const GameManager& other){
    if(this != &other){
        for(int i = 0; i < players.size(); i++){
            delete players[i];
        }

        GameManager::copy(other);
    }
    return *this;
}

void GameManager::copy(const GameManager& other){
    for(int i = 0; i < other.players.size(); i++){
        players[i] = other.players[i];
    }
}
