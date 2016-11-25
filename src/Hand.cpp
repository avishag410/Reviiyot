#include <iostream>
#include <map>
#include <vector>
#include "Hand.h"

using namespace std;

Hand::Hand()
{
	numOfCards=0;
}

bool Hand::addCard(Card &card)
{	
	pair<map<int,Card*>::iterator,bool> ret;
	
    ret = hashMap.insert( pair<int,Card*>(card.get_key(),&card) );
	
	//delete taked card?
	numOfCards++;
	
	return ret.second;
}

bool Hand::removeCard(Card &card)
{
	// what is the use of ret?!
	pair<map<int,Card*>::iterator,bool> ret;
	map<int,Card*>::iterator removeIt;
	
	removeIt=hashMap.find( card.get_key() );
	// remove using iterator is void!
	hashMap.erase(removeIt);
	
	numOfCards--;
	
	return ret.second;
}

int Hand::getNumberOfCards()
{
	return numOfCards;
}

string Hand::toString()
{
	string result = "";
	map<int,Card*>::iterator printIt;
	
	for(printIt=hashMap.begin() ; printIt!=hashMap.end() ; printIt++)
	{
		result += (printIt->second)->toString();
	}
	return result;
}

vector<Card*> Hand::searchCardsByValue(string value){
    return vector<Card*>();
}

Hand::~Hand() {

	string result = "";
	map<int,Card*>::iterator printIt;

	for(printIt=hashMap.begin() ; printIt!=hashMap.end() ; printIt++)
	{
		delete (*printIt).second;

	}
}
	