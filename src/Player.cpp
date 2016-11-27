#include<iostream>
#include<Player.h>
#include <map>
#include <vector>
#include <Hand.h>
#include <GameManager.h>
#include "../include/Player.h"

using namespace std;

Player::Player(GameManager &_gameManager, string _name): name(_name), gameManager(&_gameManager){}

Player::Player(const Player& other):Hand(other), name(other.name), gameManager(other.gameManager){}


string Player::getName(){
    return name;
}

string Player::toString() {
    return Player::getName()+ ": " + Hand::toString();
}

vector<Card*> Player::giveCards(string value) {
    // gets cards from deck
    vector<Card*> cards = Hand::searchCardsByValue(value);
    // remove cards from hand
    vector<Card*>::iterator it;
    for(it=cards.begin(); it < cards.end(); it++ ) {
        Hand::removeCard(**it);
    }
    // get cards from deck
    vector<Card*>::iterator it1;
    for(it1=cards.begin(); it1 < cards.end(); it1++ ) {
        Player::drawCard();
    }
    return cards;
}

void Player::drawCard(){
    Card* card = gameManager->getCardFromDeck();
    if(card != NULL){
        Hand::addCard(*card);
    }
}

Player::~Player() {

}