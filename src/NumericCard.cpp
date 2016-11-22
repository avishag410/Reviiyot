#include<iostream>
#include<Card.h>
#include<Utils.h>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

NumericCard::NumericCard(string cardStr){
	valueString=cardStr;
	//parse the card represented string
	string shapeStr;
	shapeStr=valueString.back();
	string valueStr=valueString.substr(0,valueString.size()-1);

	Cards::Shape shape = Utils::parseShape(shapeStr);
	std::cout << shape << std::endl;
	Card::set_shape(shape);
	
	number=stoi(valueStr);
}

string NumericCard::toString(){
	return valueString;
}


NumericCard::~NumericCard(void) {
}

