

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include "ran.h"
#include "card.h"
#include <string>

using namespace std;


int main()
{

	int i;
	int floating_mana, land_drop, lands_played, storm_count, life_total, opponent_life; //initial conditions to run the simulation

	cout << "In order to start the simulation we must construct the board state. Please enter the initial conditions when prompted.";

	cout << "\nWhat is your current life total?: ";

	cin >> life_total; //determines what life total to start subtracting from with adnauseum 

	cout << "\nWhat is your opponent's life total?: ";

	cin >> opponent_life;

	cout << "\nHow much floating mana do you have?: ";

	cin >> floating_mana; //determines how much mana we have available in order to find what what cards are live hits

	cout << "\nHave you played a land this turn?(For yes enter 1, and for no enter 0): ";

	cin >> land_drop; //determines if hitting a land with ad naus will add a mana or not

	cout << "\nHow many lands have been played? (Graveyard and on the field): ";

	cin >> lands_played; //determines how many lands to remove from class "deck"

	cout << "\nWhat is the storm count?: ";

	cin >> storm_count; //sets the storm count 

	Card deck[59];
	for (i = 0; i < 15; i++){

		deck[i].init(0, "Land");
	}
	for (i = 15; i < 19; i++){

		deck[i].init(0, "Lotus Petal");
	}
	for (i = 19; i < 23; i++){

		deck[i].init(0, "Lion's Eye Diamond");
	}
	for (i = 23; i < 27; i++){

		deck[i].init(1, "Dark Ritual");
	}
	for (i = 27; i < 31; i++){

		deck[i].init(1, "Brainstorm");
	}
	for (i = 31; i < 35; i++){

		deck[i].init(1, "Ponder");
	}
	for (i = 35; i < 39; i++){

		deck[i].init(1, "Preordain");
	}
	for (i = 39; i < 43; i++){

		deck[i].init(1, "Duress");
	}
	for (i = 43; i < 47; i++){

		deck[i].init(1, "Thoughtseize");
	}
	for (i = 47; i < 51; i++){

		deck[i].init(2, "Cabal Ritual");
	}
	for (i = 51; i < 55; i++){

		deck[i].init(2, "Infernal Tutor");
	}
	for (i = 55; i < 57; i++){

		deck[i].init(4, "Past in Flames");
	}
	deck[57].init(4, "Tendrils of Agony");
	deck[58].init(5, "Dark Petition");

	deck[5].getCardname();

	deck[5].getCMC();



	return 0;
}
