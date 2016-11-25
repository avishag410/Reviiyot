#include<iostream>
#include<Player.h>
#include <map>
#include <vector>
#include <Hand.h>
#include <GameManager.h>

using namespace std;

Player::Player(GameManager::GameManager &_gameManager, string _name): name(_name), gameManager(&_gameManager){}

string Player::getName(){
    return name;
}

string Player::toString() {
    return Player::getName()+ ": " + Hand::toString();
}

vector<Card*> Player::giveCards(string value) {
    // gets cards from deck
    vector<Card*> cards = Hand::searchCardsByValue(value);
    for(int i = 0; i <= cards.size(); i++){
        Player::drawCard();
    }
    return cards;
}

void Player::drawCard(){
    Card* card = gameManager->getCardFromDeck();
    if(card != NULL){
      //  Hand::addCard(&card);
    }
}