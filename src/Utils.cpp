#include<iostream>
#include<Utils.h>
using namespace std;
//using namespace Cards;


Cards::Shape Utils::parseShape(string shapeLetter)
{
	//parse shape card
	if (shapeLetter.compare("C") == 0 )
		return Cards::Shape::Club;
	else if (shapeLetter.compare("D") == 0 )
		return Cards::Shape::Diamond;
	else if (shapeLetter.compare("H") == 0 )
		return Cards::Shape::Heart;
	else if (shapeLetter.compare("S") == 0 )
		return Cards::Shape::Spade;
	else{
		throw invalid_argument("FigureClass: Not a valid shape");
	}
}

bool Utils::isNumericCard(string cardValue) {
	//cout << cardValue.size() << endl;
	string valueStr = cardValue.substr(0, cardValue.size() - 1);
	//cout << "valueStr" << endl;
	//cout << valueStr << endl;
	try {

		int value = atoi(valueStr.c_str());
	//	cout << "value" << endl;
	//	cout << value << endl;
		return value > 1;
	}
	catch (exception &e) {
	//	cout << "exception" << endl;
		return false;
	}
}


int Utils::generateKey(string cardString,int HighestNum)
{
	if( HighestNum < 1 )
	{	
		throw invalid_argument("HighestNum should be bigger then 0");
	}
	string shapeStr,valueStr;
	Cards::Shape shape;
	int value,result;
	
	//parse the card represented string
	shapeStr=cardString[cardString.length()-1];
	valueStr=cardString.substr(0,cardString.length()-1);
	
	shape=Utils::parseShape(shapeStr);
	//cout << "Debug: [Utils::generate] \"shape\" is " << shapeStr << " ; enum says: " << shape << endl;
	
	//parse value card
	//figure card
	if (valueStr.compare("J")==0)
		value=(((HighestNum-1)*4)+ static_cast<int>(Cards::Figure::Jack)*4);
	else if (valueStr.compare("Q")==0)
		value=(((HighestNum-1)*4)+static_cast<int>(Cards::Figure::Queen)*4);
	else if (valueStr.compare("K")==0)
		value=(((HighestNum-1)*4)+static_cast<int>(Cards::Figure::King)*4);
	else if (valueStr.compare("A")==0)
		value=(((HighestNum-1)*4)+static_cast<int>(Cards::Figure::Ace)*4);
	//numeric card
	else
		value=(stoi(valueStr)-2)*4;
		
		
	result=value+shape;
	return result;
}