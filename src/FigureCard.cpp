#include<iostream>
#include<Card.h>
#include<Utils.h>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

FigureCard::FigureCard(string cardStr) {
	valueString=cardStr;

	//parse the card represented string
	string shapeStr;
	shapeStr=valueString.back();
	string valueStr=valueString.substr(0,valueString.size()-1);
	
	Cards::Shape  shape = Utils::parseShape(shapeStr);
	Card::set_shape(shape);

	std::cout << shape << std::endl;

	//parse figure char
	if (valueStr.compare("J")==0)
		figure=Cards::Figure::Jack;
	else if (valueStr.compare("Q")==0)
		figure=Cards::Figure::Queen;
	else if (valueStr.compare("K")==0)
		figure=Cards::Figure::King;
	else if (valueStr.compare("A")==0)
		figure=Cards::Figure::Ace;
	else
		throw invalid_argument("FigureClass: Not a valid value");
}

string FigureCard::toString(){
    return valueString;
}

FigureCard::~FigureCard(void){

}

