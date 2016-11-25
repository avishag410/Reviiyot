#include<iostream>
#include<Card.h>
#include<Utils.h>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

FigureCard::FigureCard(string cardStr):Card(Cards::Shape::Club, cardStr), figure(Cards::Figure::Jack) {
	//parse the card represented string
	string shapeStr;
	shapeStr=valueString.back();
	string valueStr=valueString.substr(0,valueString.size()-1);
	
	Cards::Shape Nshape = Utils::parseShape(shapeStr);
	Card::set_shape(Nshape);
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

FigureCard::FigureCard(const FigureCard &rhs):Card(rhs), figure(Cards::Figure::Jack) {
	set_figure(rhs.get_figure());
}

FigureCard& FigureCard::operator=(const FigureCard& rhs)
{
	set_shape(rhs.get_shape());
	set_key(rhs.get_key());
	valueString=rhs.valueString;
	set_figure(rhs.get_figure());
	
	return *this;
}
string FigureCard::toString()
{
    return valueString;
}

void FigureCard::set_figure(Cards::Figure f)
{
	figure=f;
}
	
Cards::Figure FigureCard::get_figure() const
{
	return figure;
}
	
	
FigureCard::~FigureCard()
{
	
}
