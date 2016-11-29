#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <map>
#include <vector>
#include "Card.h"

using namespace std;

class Hand {
private:
    // Declare here the collection of "Card *" of the hand
	//<key,ptr_to_card_obj>
	map<int,Card*> hashMap;
	int numOfCards;
	void copy(const Hand& other);
protected:
    vector<Card*> searchCardsByValue(string value);
	vector<int> cardIndexCounter;
	virtual void setCardCounter(int n) = 0;//size for cardIndexCounter
	string searchforDuplicates(bool searchMostCommon);//return string of card value. Min=0 Max=1
public:
	Hand();
	Hand(const Hand& other);
    bool addCard(Card &card);
    bool removeCard(Card &card);
	pair<bool,int> checkForNumericSerias();//returns true is there is serias & the repeated card , false otherwise
	pair<bool,Figure> checkForFigureSerias();
    int getNumberOfCards(); // Get the number of cards in hand
    string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
	virtual ~Hand()=0;
	Hand& operator=(const Hand& other);
	void removeSerialCards();
	void removeCardsByKey(int key);
    string getMaxKeyValue();
    string getMinKeyValue();
};

#endif