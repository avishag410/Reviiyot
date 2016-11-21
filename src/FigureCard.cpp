#include<iostream>
#include<Card.h>
#include<Utils.h>
using namespace std;
/*
	FigureClass.cpp
*/

FigureCard::FigureCard(string cardStr)
{
	valueString=cardStr;
	
	//parse the card represented string
	string shapeStr;
	shapeStr=valueString.back();
	string valueStr=valueString.substr(0,valueString.size()-1);
	
	
	Card::set_shape(Utils::parseShape(shapeStr));
	
	//parse figure char
	if (valueStr.compare("J")==0)
		figure=Jack;
	else if (valueStr.compare("Q")==0)
		figure=Queen;
	else if (valueStr.compare("K")==0)
		figure=King;
	else if (valueStr.compare("A")==0)
		figure=Ace;	
	else
		throw invalid_argument("FigureClass: Not a valid value");
}

string FigureCard::toString(){
    return "test";
}

FigureCard::~FigureCard(void){

}

