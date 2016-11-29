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
		//cout << "Debug : Hand.cpp : searchforDuplicates: print vector"<<endl;
		//Utils::printVector(cardIndexCounter);
		
		//start from the first non zero value in vector
		for(vectorIndex = 0; vectorIndex < cardIndexCounter.size() ; vectorIndex++)
		{
			if( cardIndexCounter.at(vectorIndex) )
			{
				compareDuplic=cardIndexCounter.at(vectorIndex);
				resultIndex=vectorIndex;
				break;
			}
		}
		
		//starts the loop from begining of vector,to make sure we take the lowest value
		for(vectorIndex = 0; vectorIndex < cardIndexCounter.size() ; vectorIndex++)
		{	
			tmpVal=cardIndexCounter.at(vectorIndex);
			if( tmpVal < compareDuplic && tmpVal > 0 )
			{
				compareDuplic=tmpVal;
				resultIndex = vectorIndex;
				
				//cout << "Debug : Hand.cpp : searchforDuplicates: in loop: "<<endl;
				//cout << "tmpVal "<<tmpVal<<"resultIndex "<< resultIndex<<endl;
			}	
		}
		
		//cout << "Debug : Hand.cpp : searchforDuplicates :resultIndex= "<< resultIndex<<endl;
	}
	else//get ths value the players has the most
	{
		compareDuplic=cardIndexCounter.at( cardIndexCounter.size() -1 );
		resultIndex=cardIndexCounter.size() -1;
		
		for(vectorIndex = cardIndexCounter.size() -1 ; vectorIndex > 0 ; vectorIndex--)
		{	
			tmpVal=cardIndexCounter.at(vectorIndex);
			if( tmpVal > compareDuplic  )
			{
				compareDuplic=tmpVal;
				resultIndex = vectorIndex;
				
			}	
		}
		
		
	}
	
	//sending the value string
	const int HighestNumIndex = cardIndexCounter.size() - 4;
	//cout << "Debug : Hand.cpp : searchforDuplicates :HighestNumIndex= "<< HighestNumIndex<<endl;
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
	//cout << "Debug : Hand.cpp : searchforDuplicates :"<<endl;
	//Utils::printVector(cardIndexCounter);
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

			cout << "key: " << key << " counter: " << counter <<endl;
		} else if(reverseIt->first/ 4 == value){
			++counter;
			cout << "same value... " << " counter: " << counter <<endl;
		} else if(reverseIt->first/4 != value){
			int key = reverseIt->first;
			value = key/4;
			cout << "new value key: " << key << " counter: " << counter <<endl;

			if(counter == 4){
				removeCardsByKey(value*4);
				cout << "back to removing" <<endl;
			}

			counter = 1;
		}
	}

	if(counter == 4){
		removeCardsByKey(value*4);
		cout << "back to removing2" <<endl;
	}
}

void Hand::removeCardsByKey(int key){

	int minVal = key - (key%4);
	int maxVal = 4 - (key%4) + key -1;

	cout << "remove cards by key: " << key << " minVal: " << minVal<< " maxVal: " << maxVal <<endl;

	for(int i = maxVal; i >= minVal; i--){
		cout << "remove card in indexy: " << i <<endl;
		removeCard(*(hashMap.at(i)));
	}
}

pair<bool,int> Hand::checkForNumericSerias()
{
	int numToCheck = 0,counter=0;
	Card *card;
	pair<bool,int> answer;
	map<int,Card*>::iterator mapIt;
	vector<int> numbersInHand;
	vector<int>::iterator vectorIt=numbersInHand.begin();
	
	//insert to vector all number values in hand
	for(mapIt=hashMap.begin();mapIt!=hashMap.end();mapIt++)
	{
		vectorIt = numbersInHand.begin();
		card = mapIt->second;
		//cout << card << " numeric card is "<< NUMERIC_CARD << endl;
		if(card!=NULL)
		{
			if(card->cardType() == NUMERIC_CARD)
			{
				//cout << "inserting..." << endl;
				numbersInHand.insert(vectorIt,((NumericCard*)card)->get_number());
				//cout << "inserted." << endl;
			}
		}
	}
	//cout << "OK."<<endl;
	sort(numbersInHand.begin(),numbersInHand.end());
	//check for serias
	vectorIt=numbersInHand.begin();
	numToCheck=*vectorIt;
	
	for(vectorIt=numbersInHand.begin()+1;vectorIt!=numbersInHand.end();vectorIt++)
	{
			if(*vectorIt==numToCheck)
			{	
				counter++;
			}
			else
			{
				counter=0;
				numToCheck=*vectorIt;
			}
			
			if(counter==3)
			{
				answer.first=true;
				answer.second=numToCheck;
				return answer;
			}
	}
	
	answer.first=false;
	answer.second=0;
	return answer;
}
pair<bool,Figure> Hand::checkForFigureSerias()
{
	int counter=0;
	pair<bool,Figure> answer;
	Figure figureToCheck;
	Card *card;
	map<int,Card*>::iterator mapIt;
	vector<Figure> figuresInHand;
	vector<Figure>::iterator vectorIt=figuresInHand.begin();
	
	//insert to vector all number values in hand
	for(mapIt=hashMap.begin();mapIt!=hashMap.end();mapIt++)
	{
		vectorIt = figuresInHand.begin();
		card = mapIt->second;
		//cout << card << " numeric card is "<< NUMERIC_CARD << endl;
		if(card!=NULL)
		{
			if(card->cardType() == FIGURE_CARD)
			{
				//cout << "inserting..." << endl;
				figuresInHand.insert(vectorIt,((FigureCard*)card)->get_figure());
				//cout << "inserted." << endl;
			}
		}
	}
	//cout << "OK."<<endl;
	sort(figuresInHand.begin(),figuresInHand.end());
	//check for serias
	vectorIt=figuresInHand.begin();
	figureToCheck=*vectorIt;
	
	for(vectorIt=figuresInHand.begin()+1;vectorIt!=figuresInHand.end();vectorIt++)
	{
			if(*vectorIt==figureToCheck)
			{	
				counter++;
			}
			else
			{
				counter=0;
				figureToCheck=*vectorIt;
			}
			
			if(counter==3)
			{
				answer.first=true;
				answer.second=figureToCheck;
				return answer;
			}
				
	}
	answer.first=false;
	answer.second=figureToCheck;//cant assign null type or 0
	return answer;
	
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
	