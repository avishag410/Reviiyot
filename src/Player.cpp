#include <iostream>
#include "Player.h"
#include <map>
#include <vector>
#include "Hand.h"
#include "GameManager.h"
#include "../include/Player.h"
#include "Utils.h"

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
	//cout<<"Debug : Player.cpp : giveCards" << "1"<<endl;
    vector<Card*> cards = Hand::searchCardsByValue(value);
	//cout<<"Debug : Player.cpp : giveCards" << "2"<<endl;
    // remove cards from hand
    vector<Card*>::iterator it;
    for(it=cards.begin(); it < cards.end(); it++ ) {
        Hand::removeCard(**it);
    }
	//cout<<"Debug : Player.cpp : giveCards" << "3"<<endl;
    // get cards from deck
    vector<Card*>::iterator it1;
    for(it1=cards.begin(); it1 < cards.end(); it1++ ) {
        Player::drawCard();
    }
	//cout<<"Debug : Player.cpp : giveCards" << "4"<<endl;
    return cards;
}

void Player::drawCard(){
    Card* card = gameManager->getCardFromDeck();
    if(card != NULL){
        Hand::addCard(*card);
    }
}

void Player::setCardCounter(int n)
{
	cardIndexCounter.assign(n+3,0);//initialize vector that counts duplications of value
	//Utils::printVector(cardIndexCounter);
}

Player::~Player() {

}