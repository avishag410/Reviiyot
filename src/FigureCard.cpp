#include<iostream>
#include<Card.h>
using namespace std;
/*
	FigureClass.cpp
*/

FigureCard::FigureCard(string cardStr)
{
	valueString=cardStr;
}

Figure FigureCard::get_figure() const
{
	return figure;
}


