#include<KeyGenerator.h>
#include<iostream>
#include<exception>
KeyGenerator::KeyGenerator(int n):N(n){}

int KeyGenerator::generate(string cardString)
{
	string shapeStr,valueStr;
	Shape shape;
	int value,result;
	
	//parse the card represented string
	shapeStr=cardString.back();
	valueStr=cardString.substr(0,cardString.size()-1);
	
	//parse shape card
	if (shapeStr.compare("C") == 0 )
		shape=Club;
	else if (shapeStr.compare("D") == 0 )
		shape=Diamond;
	else if (shapeStr.compare("H") == 0 )
		shape=Heart;
	else if (shapeStr.compare("S") == 0 )
		shape=Spade;
	else
		throw invalid_argument("KeyGenerator: Not a valid shape");
	
	//parse value card
	//figure card
	if (valueStr.compare("J")==0)
		value=N+Jack;
	else if (valueStr.compare("Q")==0)
		value=N+Queen;
	else if (valueStr.compare("K")==0)
		value=N+King;
	else if (valueStr.compare("A")==0)
		value=N+Ace;
	//numeric card
	else
		value=(stoi(valueStr)-2)*4;
		
		
	result=value+shape;
	return result;
}