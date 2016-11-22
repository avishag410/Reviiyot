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
	pair<map<int,Card*>::iterator,bool> ret;
	
    ret = hashMap.insert( pair<int,Card*>(card.get_key(),&card) );
	
	//delete taked card?
	numOfCard++;
	
	return ret.second;
}

bool Hand::removeCard(Card &card)
{
	pair<map<int,Card*>::iterator,bool> ret;
	map<int,Card*>::iterator removeIt;
	
	removeIt=HashMap.find( card.get_key() );
	ret=HashMap.erase(removeIt);
	
	numOfCards--;
	
	return ret.second;
}

int Hand::getNumberOfCards()
{
	return numOfCard;
}

string Hand::toString()
{
	map<int,Card*>::iterator printIt;
	
	for(printIt=hashMap.begin() ; printIt!=hashMap.end() ; printIt++)
	{
		 (printIt.second)->toString();
	}
	
}	
	
	