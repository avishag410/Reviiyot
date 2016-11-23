#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

namespace Cards {
	enum Shape {
		Club,
		Diamond,
		Heart,
		Spade
	};

	enum Figure {
		Jack,
		Queen,
		King,
		Ace
	};
}

using namespace Cards;

class Card {
private:
	Cards::Shape shape;
	int key;//number represents the card
protected:
	string valueString;

public:
	virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
	virtual ~Card();

	/*
	returns 0 if equals
	returns 1 if this>otherCard
	returns -1 if this<otherCard
	*/
	int compare(Card &otherCard);

	int get_key() ;
	void set_key(int key);

	void set_shape(Cards::Shape nShape);
	Cards::Shape get_shape();
};

class FigureCard : public Card {
private:
	//not in use,therefore not initialized
	Cards::Figure figure;
public:
	FigureCard(string cardStr);

	//TODO: Add copy ctor & copy assignment op
	virtual string toString() override;

	virtual ~FigureCard() override;

};

class NumericCard : public Card {
private:
	//not in use,therefore not initialized
	int number;
public:
	NumericCard(string cardStr);

	//TODO: Add copy ctor & copy assignment op
	virtual string toString() override;

	virtual ~NumericCard() override;
};


#endif