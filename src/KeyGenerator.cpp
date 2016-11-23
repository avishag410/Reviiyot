#include<KeyGenerator.h>
#include<iostream>
#include<exception>
#include "Utils.h"
#include "../include/Card.h"

//using namespace Cards;

KeyGenerator::KeyGenerator(int n):N(n){}

int KeyGenerator::generate(string cardString)
{
	string shapeStr,valueStr;
	Cards::Shape shape;
	int value,result;
	
	//parse the card represented string
	shapeStr=cardString.back();
	valueStr=cardString.substr(0,cardString.size()-1);
	
	
	shape=Utils::parseShape(shapeStr);
	
	//parse value card
	//figure card
	// TODO does this also need to be *4?
	if (valueStr.compare("J")==0)
		value=(N+1+ static_cast<int>(Cards::Figure::Jack)*4);
	else if (valueStr.compare("Q")==0)
		value=(N+1+static_cast<int>(Cards::Figure::Queen)*4);
	else if (valueStr.compare("K")==0)
		value=(N+1+static_cast<int>(Cards::Figure::King)*4);
	else if (valueStr.compare("A")==0)
		value=(N+1+static_cast<int>(Cards::Figure::Ace)*4);
	//numeric card
	else
		value=(stoi(valueStr)-2)*4;
		
		
	result=value+shape;
	return result;
}