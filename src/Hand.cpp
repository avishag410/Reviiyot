#include <iostream>
#include <map>
#include <vector>
#include "Hand.h"
#include "Utils.h"
#include <algorithm>
#include <string.h>
using namespace std;

Hand::Hand():hashMap(), numOfCards(0), cardIndexCounter(){
	
}

Hand::Hand(const Hand& other):hashMap(), numOfCards(0), cardIndexCounter(){
	Hand::copy(other);
}

bool Hand::addCard(Card &card) {
	pair<map<int,Card*>::iterator,bool> ret;
	
    ret = hashMap.insert( pair<int,Card*>(card.get_key(),&card) );
	
	//delete taked card?
	numOfCards++;
	cardIndexCounter.at(card.get_key()/4)++;
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
	cardIndexCounter.at(card.get_key()/4)--;
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
		result.append( (printIt->second)->toString());
		result.append(" ");
	}
	return result;
}

vector<Card*> Hand::searchCardsByValue(string value)
{
	vector<Card*> resultVec;
	string cardValue,cardString;
	map<int,Card*>::iterator it;

	for(it=hashMap.begin() ; it!=hashMap.end() ; it++)
	{
		//get only the value of the card
		cardString=(it->second)->toString() ;
		cardValue= (cardString).substr(0,cardString.length() -1);
		if( value.compare( cardValue ) == 0 )
			resultVec.push_back(it->second);
	}
	
    return resultVec;
}

string Hand::searchforDuplicates(bool searchMostCommon)
{
	string result;
	int resultIndex,vectorIndex,compareDuplic,tmpVal;
	
	if(!searchMostCommon)//get ths value the players has the least
	{
		//start from the first non zero value in vector
		for(vectorIndex = 0; vectorIndex < (signed int)cardIndexCounter.size() ; vectorIndex++)
		{
			if( cardIndexCounter.at(vectorIndex) )
			{
				compareDuplic=cardIndexCounter.at(vectorIndex);
				resultIndex=vectorIndex;
				break;
			}
		}
		
		//starts the loop from begining of vector,to make sure we take the lowest value
		for(vectorIndex = 0; vectorIndex < (signed int)cardIndexCounter.size() ; vectorIndex++)
		{	
			tmpVal=cardIndexCounter.at(vectorIndex);
			if( tmpVal < compareDuplic && tmpVal > 0 )
			{
				compareDuplic=tmpVal;
				resultIndex = vectorIndex;
			}
		}
	}
	else//get ths value the players has the most
	{
		//cout << "Debug: hand.cpp: searchforDuplicates :vector " << endl;
		//Utils::printVector(cardIndexCounter);
		compareDuplic=cardIndexCounter.at( cardIndexCounter.size() -1 );
		resultIndex=cardIndexCounter.size() -1;
		
		for(vectorIndex = (signed int)cardIndexCounter.size() -1 ; vectorIndex >= 0 ; vectorIndex--)
		{	
			tmpVal=cardIndexCounter.at(vectorIndex);
			if( tmpVal > compareDuplic  )
			{
				compareDuplic=tmpVal;
				resultIndex = vectorIndex;
			}
		}
		//cout<<"Debug: hand.cpp: searchforDuplicates: compareDuplic"<<compareDuplic<<"resultIndex"<<resultIndex<< endl;
	}
	
	//sending the value string
	const int HighestNumIndex = cardIndexCounter.size() - 4;
	//numeric value
	if(resultIndex < HighestNumIndex )
	{
		result= std::to_string(resultIndex+2);
	}
	//figure value
	else
	{
		if( resultIndex == HighestNumIndex)
			result="J";
		else if( resultIndex == HighestNumIndex+1 )
			result="Q";
		else if( resultIndex == HighestNumIndex+2 )
			result="K";
		else if( resultIndex == HighestNumIndex+3 )
			result="A";
		else
			cout << "parsing ERROR in searchforDuplicates " <<endl;
	}
	return result;
}

void Hand::removeSerialCards(){
	int counter = 0;
	int value = 0;
	map<int, Card*>::reverse_iterator reverseIt;
	for(reverseIt = hashMap.rbegin(); reverseIt != hashMap.rend(); ++reverseIt){
		if(counter == 0){
			int key = reverseIt->first;
			value = key/4;
			++counter;
		} else if(reverseIt->first/ 4 == value){
			++counter;
		} else if(reverseIt->first/4 != value){
            int key = reverseIt->first;

            if(counter == 4){
                removeCardsByKey(value*4);
            }

			value = key/4;
			counter = 1;
		}
	}

	if(counter == 4){
		removeCardsByKey(value*4);
	}
}

void Hand::removeCardsByKey(int key){

	int minVal = key - (key%4);
	int maxVal = 4 - (key%4) + key -1;

	for(int i = maxVal; i >= minVal; i--){
		removeCard(*(hashMap.at(i)));
	}
}

string Hand::getMaxKeyValue(){
	map<int, Card*>::reverse_iterator reverseIt;
	reverseIt = hashMap.rbegin();
	string cardValue = (*reverseIt).second->toString();
	return (cardValue.substr(0, cardValue.size() - 1));
}

string Hand::getMinKeyValue(){
	map<int, Card*>::iterator it;
	it = hashMap.begin();
	string cardValue = (*it).second->toString();
	return (cardValue.substr(0, cardValue.size() - 1));
}

void Hand::copy(const Hand& other){
	numOfCards = other.numOfCards;
	map<int,Card*> temp = other.hashMap;
	map<int,Card*>::iterator it;

	for(it=temp.begin() ; it!=temp.end() ; it++) {
		hashMap.insert(pair<int,Card*>((*it).first,(*it).second->clone()));
	}
}

Hand& Hand::operator=(const Hand& other){
	if(this != &other){
		// delete
		map<int,Card*>::iterator it;
		for(it=hashMap.begin() ; it!=hashMap.end() ; it++) {
			delete (*it).second;
		}
		// copy
		Hand::copy(other);
	}
	return *this;
}

Hand::~Hand() {
	map<int,Card*>::iterator it;
	for(it=hashMap.begin() ; it!=hashMap.end() ; it++) {
		delete (*it).second;
	}
	//TODO delete vector
}
	