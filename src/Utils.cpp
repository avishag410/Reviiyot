#include<iostream>
#include<Utils.h>
using namespace std;
using namespace Cards;


Cards::Shape Utils::parseShape(string shapeLetter)
{
	//parse shape card
	if (shapeLetter.compare("C") == 0 )
		return Cards::Shape::Club;
	else if (shapeLetter.compare("D") == 0 )
		return Cards::Shape::Diamond;
	else if (shapeLetter.compare("H") == 0 )
		return Cards::Shape::Heart;
	else if (shapeLetter.compare("S") == 0 )
		return Cards::Shape::Spade;
	else{
		throw invalid_argument("FigureClass: Not a valid shape");
	}

}