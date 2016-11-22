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
	
	
	shape=Utils::parseShape(shapeStr);
	
	//parse value card
	//figure card
	if (valueStr.compare("J")==0)
		value=N+1+Jack;
	else if (valueStr.compare("Q")==0)
		value=N+1+Queen;
	else if (valueStr.compare("K")==0)
		value=N+1+King;
	else if (valueStr.compare("A")==0)
		value=N+1+Ace;
	//numeric card
	else
		value=(stoi(valueStr)-2)*4;
		
		
	result=value+shape;
	return result;
}