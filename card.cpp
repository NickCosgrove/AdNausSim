#include "card.h"
#include <iostream>

using namespace std;

void Card::init(int x, string y){
	CMC = x;

	cardname = y;
}

int Card::getCMC(){
	return CMC;
}


string Card::getCardname(){
	return cardname;
}