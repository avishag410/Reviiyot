#include<iostream>
#include<Card.h>
#include<Utils.h>
using namespace std;
using namespace Cards;

NumericCard::NumericCard(string cardStr)
{
	valueString=cardStr;
	
	//parse the card represented string
	string shapeStr=valueString.substr(valueString.size()-2, valueString.size()-1);
	string valueStr=valueString.substr(0,valueString.size()-2);
	
	//Card::set_shape(Utils::parseShape(shapeStr));
	
	number=stoi(valueStr);
}

string NumericCard::toString(){
	return "test";
}


NumericCard::~NumericCard(void) {
}

