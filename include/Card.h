#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

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

class Card {
private:
  Shape shape;
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
  Shape get_shape() const;
  int get_key() const;
  void set_key(int key);
};

class FigureCard : public Card {
private:
	Figure figure;
public:
	FigureCard(string cardStr);
	//TODO: Add copy ctor & copy assignment op
	virtual string toString() override;
	Figure get_figure() const;
	
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(string cardStr);
	//TODO: Add copy ctor & copy assignment op
	virtual string toString() override;
	int get_number() const;
};

#endif