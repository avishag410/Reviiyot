#include<iostream>
#include<Card.h>
#include<Utils.h>
#include<string>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

NumericCard::NumericCard(string cardStr):Card(Cards::Shape::Club, cardStr), number(0) {
	valueString=cardStr;
	//parse the card represented string
	string shapeStr;
	shapeStr=valueString.back();
	string valueStr=valueString.substr(0,valueString.size()-1);

	Cards::Shape shape = Utils::parseShape(shapeStr);
	Card::set_shape(shape);
	
	number=stoi(valueStr);
}
NumericCard::NumericCard(const NumericCard &rhs):Card(rhs), number(0) {
	set_number(rhs.get_number());
}

NumericCard& NumericCard::operator=(const NumericCard& rhs) {
	if(this != &rhs) {
		set_shape(rhs.get_shape());
		set_key(rhs.get_key());
		valueString = rhs.valueString;
		set_number(rhs.get_number());
	}
	return *this;
}

void NumericCard::set_number(int n)
{
	number=n;
}
int NumericCard::get_number() const
{
	return number;
}
string NumericCard::toString(){
	return valueString;
}

Card* NumericCard::clone(){
    return new NumericCard(*this);
}

int NumericCard::cardType()
{
	return NUMERIC_CARD;
}

NumericCard::~NumericCard(void) {
}

