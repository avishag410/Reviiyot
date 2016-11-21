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

string FigureCard::toString(){
    return "test";
}


int FigureCard::compare(Card &otherCard){
    return 1;
}

FigureCard::~FigureCard(void){

}

