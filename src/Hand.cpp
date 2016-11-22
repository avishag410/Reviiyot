#incldue <iostream>
#include <map>
#include "Hand.h"

using namespace std;
/*
	Hand.cpp
*/

Hand::Hand()
{
	numOfCards=0;
}

bool Hand::addCard(Card &card)
{	
	pair<map<char,int>::iterator,bool> ret;
    ret = hashMap.insert( pair<int,Card*>(card.get_key(),&card) );
	//delete taked card?
	numOfCard++;
	return ret.second;
}