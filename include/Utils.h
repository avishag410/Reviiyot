#ifndef Utils_H
#define Utils_H

#include<iostream>
#include<Card.h>
using namespace std;
//using namespace Cards;

class Utils
{
public:
	static Cards::Shape parseShape(string shapeLetter);
	static bool isNumericCard(string cardValue);
	static int generateKey(string cardString,int HighesteNum);
};
#endif