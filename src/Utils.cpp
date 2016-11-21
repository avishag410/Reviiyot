#include<iostream>
#include<Utils.h>
using namespace std;


static Shape Utils::parseShape(string shapeLetter)
{
	//parse shape card
	if (shapeStr.compare("C") == 0 )
		return Club;
	else if (shapeStr.compare("D") == 0 )
		return Diamond;
	else if (shapeStr.compare("H") == 0 )
		return Heart;
	else if (shapeStr.compare("S") == 0 )
		return Spade;
	else{
		throw invalid_argument("FigureClass: Not a valid shape");
		return null;
	}

}