#include <iostream>
#include <vector>
#include "Hand.h"
#include "Player.h"
#include "Card.h"
#include "GameManager.h"

using namespace std;

PlayerType1::PlayerType1(GameManager &gameManager, string name):Player::Player(gameManager,name){}

PlayerType1::PlayerType1(const PlayerType1 &other):Player(other){}

void PlayerType1::makeMove(bool printMove){
    // search for the most-higher card
    string cardValue = PlayerType1::searchStrategyCard();
	//cout << "Debug : PlayerType1 : makeMove : player name="<<getName()<<endl;
	//cout << "Debug : PlayerType1 : makeMove : cardValue="<<cardValue<<endl;
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)c
    Player* player = Player::gameManager->getPlayerWithMaxCards(*this);
    vector<Card*> given = player->giveCards(cardValue);//replace with cardValue
    if(given.size() > 0) {
        vector<Card*>::iterator it;
        for(it=given.begin() ; it < given.end(); it++ ) {
            //Hand::addCard(it);
        }
		
    } else{
        Player::drawCard();
    }
}

Player* PlayerType1::clone(){
    return new PlayerType1(*this);
}

string PlayerType1::searchStrategyCard()
{
	//search for the card he has the most
	//Card* card;
	//cout<<"Debug : PlayerType.cpp : searchStrategyCard" << "1"<<endl;
	return getDuplicatedCard(true);
	
}

PlayerType1::~PlayerType1(){

}

PlayerType2::PlayerType2(GameManager &gameManager, string name):Player::Player(gameManager,name){}
PlayerType2::PlayerType2(const PlayerType2 &other):Player(other){}
void PlayerType2::makeMove(bool printMove){
    // search for the least-lower card
    string cardValue = PlayerType2::searchStrategyCard();
    // choose the player with the most cards
    // if there are two, then choose the one in higher position (whats that means?)
    Player* player = Player::gameManager->getPlayerWithMaxCards(*this);
    vector<Card*> given = player->giveCards(cardValue);

    if(given.size() > 0) {
        vector<Card*>::iterator it;
        for(it=given.begin() ; it < given.end(); it++ ) {
            //Hand::addCard(it);
        }
    } else{
        Player::drawCard();
    }
}

Player* PlayerType2::clone(){
    return new PlayerType2(*this);
}

string PlayerType2::searchStrategyCard(){
    return NULL ;
}

PlayerType2::~PlayerType2(){

}

PlayerType3::PlayerType3(GameManager &gameManager, string name, int _selfPosition):Player::Player(gameManager,name), playerIndex(0), selfPosition(_selfPosition){}
PlayerType3::PlayerType3(const PlayerType3 &other):Player(other), playerIndex(other.playerIndex), selfPosition(other.selfPosition){}
void PlayerType3::makeMove(bool printMove){
    // counter - cyclic order
    int total = Player::gameManager->getTotalOfPlayers();
    int next = (PlayerType3::playerIndex+1) % total;
    if(next == PlayerType3::selfPosition)
        next = (next+1) % total;
    PlayerType3::playerIndex = next;
    Player* player = Player::gameManager->getPlayerByPosition(next);
    // search for the higher card
    string cardValue= PlayerType3::searchStrategyCard();

    vector<Card*> given = player->giveCards(cardValue);

    if(given.size() > 0) {
        vector<Card*>::iterator it;
        for(it=given.begin() ; it < given.end(); it++ ) {
            //Hand::addCard(it);
        }
    } else{
        Player::drawCard();
    }
}

Player* PlayerType3::clone(){
    return new PlayerType3(*this);
}

string PlayerType3::searchStrategyCard(){
    return NULL ;
}


PlayerType3::~PlayerType3(){

}

PlayerType4::PlayerType4(GameManager &gameManager, string name, int _selfPosition):Player::Player(gameManager,name), playerIndex(0), selfPosition(_selfPosition){}
PlayerType4::PlayerType4(const PlayerType4 &other):Player(other), playerIndex(other.playerIndex), selfPosition(other.selfPosition){}
void PlayerType4::makeMove(bool printMove){
    // counter - cyclic order
    int total = Player::gameManager->getTotalOfPlayers();
    int next = (PlayerType4::playerIndex+1) % total;
    if(next == PlayerType4::selfPosition)
        next = (next+1) % total;
    PlayerType4::playerIndex = next;
    Player* player = Player::gameManager->getPlayerByPosition(next);

    // search for the lowest card
    string cardValue= PlayerType4::searchStrategyCard();

    vector<Card*> given = player->giveCards(cardValue);

    if(given.size() > 0) {
        vector<Card*>::iterator it;
        for(it=given.begin() ; it < given.end(); it++ ) {
            //Hand::addCard(it);
        }
    } else{
        Player::drawCard();
    }
}

Player* PlayerType4::clone(){
    return new PlayerType4(*this);
}

string PlayerType4::searchStrategyCard(){
    return NULL ;
}


PlayerType4::~PlayerType4(){

}