#include "card.h"
#include <iostream>
#include <string>

using namespace std;

void Card::init(int x, string y){
	CMC = x;

	cardname = y;
}

int Card::getCMC(){
	cout << CMC;

	return 0;
}


string Card::getCardname(){
	cout << cardname;

	return 0;
}