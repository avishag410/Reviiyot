#include <iostream>
#include <map>
#include <vector>
#include <Hand.h>
#include<algorithm>
using namespace std;

Hand::Hand():hashMap(), numOfCards(0){
}

Hand::Hand(const Hand& other){
	Hand::copy(other);
}

bool Hand::addCard(Card &card) {
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
		result.append( (printIt->second)->toString());
		result.append(" ");
	}
	return result;
}

vector<Card*> Hand::searchCardsByValue(string value){
    return vector<Card*>();
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
	cout<<"copy hand card"<< endl;
	map<int,Card*> temp = other.hashMap;
	map<int,Card*>::iterator it;

	for(it=temp.begin() ; it!=temp.end() ; it++) {
		cout<<"copy hand card"<< endl;
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
}
	