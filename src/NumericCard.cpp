#include<iostream>
#include<Card.h>
using namespace std;
/*
	NumericClass.cpp
*/

NumericCard::NumericCard(string cardStr)
{
	valueString=cardStr;
}

string NumericCard::toString(){
	return "test";
}


NumericCard::~NumericCard(void) {
}

