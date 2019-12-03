#include "card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(){
	CMC = 0;

	cardname = "card";
}

void Card::resetCard(){
	CMC = 0;

	cardname = "card";

}

void Card::init(int x, string y){
	CMC = x;

	cardname = y;
}

int Card::getCMC(){
	//cout << CMC << endl;

	return CMC;
}


string Card::getCardname(){
	//cout << cardname << endl;

	return cardname;
}