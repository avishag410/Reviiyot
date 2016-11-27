#include <iostream>
#include <vector>
#include <climits>
#include <Player.h>
#include <Deck.h>
#include <Card.h>
#include <GameManager.h>
using namespace std;
// TODO do I really need vector of player or a pointer to a vector?
GameManager::GameManager():players(), deck(){
}

GameManager::GameManager(Deck& _deck):players(), deck(&_deck) {
}

GameManager::GameManager(const GameManager& other):players(), deck() {
   GameManager::copy(other);
}

void GameManager::setPlayers(vector<Player*> _players){
    vector<Player*> temp = _players;
    vector<Player*>::iterator it;
    for(it=temp.begin() ; it < temp.end(); it++) {
        players.push_back((*it));
    }
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
    if(position < static_cast<int>(players.size()))
        return  players[position];
    else
        return NULL;
}
Card* GameManager::getCardFromDeck(){
    cout<< deck->toString() << endl;
    Card* card = deck->fetchCard();
    return  card;
}

int GameManager::getTotalOfPlayers(){
    return players.size();
}


GameManager &GameManager::operator=(const GameManager& other){
    if(this != &other){
        GameManager::copy(other);
    }
    return *this;
}

void GameManager::copy(const GameManager& other){

    vector<Player*> temp = other.players;
    vector<Player*>::iterator it;
    for(it=temp.begin() ; it < temp.end(); it++) {
        players.push_back((*it));
    }
}

GameManager::~GameManager(){

}
