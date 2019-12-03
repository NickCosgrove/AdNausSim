

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
	double number_of_iterations = 20;
	double wins = 0;
	double loss = 0;
	long int s2 = -25;
	

		int i;
		int floating_mana, land_drop, lands_played, storm_count, life_total,f_m,l_d,l_p,s_c,l_t; //initial conditions to run the simulation, and interative equivalents
		double opponent_life, o_l;
		cout << "In order to start the simulation we must construct the board state. Please enter the initial conditions when prompted.";

		cout << "\nWhat is your current life total?: ";

		cin >> l_t; //determines what life total to start subtracting from with adnauseum 

		cout << "\nWhat is your opponent's life total?: ";

		cin >> o_l;

		cout << "\nHow much floating mana do you have?: ";

		cin >> f_m; //determines how much mana we have available in order to find what what cards are live hits

		cout << "\nHave you played a land this turn?(For yes enter 1, and for no enter 0): ";

		cin >> l_d; //determines if hitting a land with ad naus will add a mana or not

		cout << "\nHow many lands have been played? (Graveyard and on the field): ";

		cin >> l_p; //determines how many lands to remove from "deck"

		cout << "\nWhat is the storm count?: ";

		cin >> s_c; //sets the storm count 

		for (int w = 0; w < number_of_iterations; w++){
			floating_mana = f_m;
			opponent_life = o_l;
			storm_count = s_c;
			lands_played = l_p;
			land_drop = l_d;
			life_total = l_t;
			int repeat = 0;

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

			for (i = 0; i < lands_played; i++){//removing the lands played during the game from the deck since they are no longer available.
				deck[i].resetCard();
			}


			Card hand[59];
			
			long int s1;
			s1 = (long int)w*-1;
			
			cout << s1;
			double x = 0;
			int y = 0;
			int z = 0;

			while (life_total >= 5){

				x = 59 * ran(s1); //Get a random number from 0-58 to determine what card to draw from the deck.
				x = x + 0.5;
				y = (int)x;//Truncate the double to an int so it can be correctly used in deck[i]

				if (deck[y].getCardname() == "card"){

					continue;
				}

				hand[z] = deck[y];
				int cmc = deck[y].getCMC();
				life_total = life_total - cmc;

				//cout << "The card you drew was " << deck[y].getCardname() << endl;

				//cout << "Your life total is " << life_total << endl;

				deck[y].resetCard();

				z++;
			}
			//cout << "Your hand is :";

			for (i = 0; i < 59; i++){
				if (hand[i].getCardname() == "card"){

					break;
				}
				cout << hand[i].getCardname() << ",";

			}
			int potential_mana1 = 0;//A storage variable for mana that is available once floating mana is 1 or above
			int potential_mana2 = 0;//A storage variable for mana that is available once floating mana is 2 or above
			int potential_manaTutor = 0;//A storage variable for mana available if I have an infernal tutor in hand 
			int potential_stormcount1 = 0;//A storage variable for storm count that will be added once floating mana is 1 or above
			int potential_stormcount2 = 0;//A storage variable for storm count that will be added once floating mana is 2 or above
			int ritual_mana = 0;//Mana created solely by "ritual" effects and can be casted again with Past in Flames.
			int darkritual_binary = 0;//A binary variable that stores whether or not there is a dark ritual in hand.
			for (i = 0; i < 59; i++){
				if (hand[i].getCardname() == "card"){

					break;
				}

				if (hand[i].getCardname() == "Lotus Petal"){
					floating_mana = floating_mana + 1;
					storm_count++;
				}
				if (hand[i].getCardname() == "Land"){
					if (land_drop == 0){
						floating_mana = floating_mana + 1;
						land_drop = 1;//Set land_drop to 1 because we have played a land this turn and we can only play 1 a turn
					}
				}
				if (hand[i].getCardname() == "Dark Ritual"){
					ritual_mana = ritual_mana + 2;
					darkritual_binary = 1;
					if (floating_mana > 0){
						floating_mana = floating_mana + 2;
						storm_count++;
					}
					else{
						potential_mana1 = potential_mana1 + 2;
						potential_stormcount1++;
					}
				}
				if (hand[i].getCardname() == "Cabal Ritual"){
					ritual_mana = ritual_mana + 3;
					if (floating_mana > 1){
						floating_mana = floating_mana + 3;
						storm_count++;
					}
					else{
						potential_mana2 = potential_mana2 + 3;
						potential_stormcount2++;
					}
				}
				if (hand[i].getCardname() == "Lion's Eye Diamond"){
					potential_manaTutor = potential_manaTutor + 3;
					storm_count++;
				}
			}
			if (floating_mana > 0){
				floating_mana = floating_mana + potential_mana1;
				storm_count = storm_count + potential_stormcount1;
			}
			if (floating_mana > 1){
				floating_mana = floating_mana + potential_mana2;
				storm_count = storm_count + potential_stormcount2;
			}
			cout << "\nTotal floating mana is: " << floating_mana;

			int required_storm = ceil((opponent_life / 2) - 1);
			//The required storm is the storm needed to win the game. Tendrils of Agony 
			//deals 2 damage for every storm count so the required storm is half of the 
			//opponents life minus 1 because Tendrils counts itself.
			for (i = 0; i < 59; i++){
				if (hand[i].getCardname() == "card"){

					break;
				}
				if (hand[i].getCardname() == "Tendrils of Agony"){
					if (storm_count >= required_storm && floating_mana >= 4){
						storm_count++;
						cout << "\nYou win the game! You cast Tendrils of Agony with a storm count of " << storm_count;
						//return 0;
						wins++;
						
					}
				}
			}
			for (i = 0; i < 59; i++){
				if (hand[i].getCardname() == "card"){

					break;
				}
				if (hand[i].getCardname() == "Infernal Tutor" && potential_manaTutor>0){
					if (floating_mana + potential_manaTutor >= 6 && storm_count >= required_storm - 1 && repeat==0){
						storm_count++;//cast infernal tutor, searching for Tendrils of Agony
						storm_count++;//cast Tendrils of Agony
						cout << "\nYou win the game! You cast Tendrils of Agony with a storm count of " << storm_count;
						//return 0;
						wins++;
						repeat = 1;
					} else if (deck[55].getCardname() == "Past in Flames" || deck[56].getCardname() == "Past in Flames"){
						if (floating_mana + potential_manaTutor >= 8 && ritual_mana >= 5){//Past in flames would resolve with 2 floating mana which means Cabal ritual can be cast right away.
							storm_count++;//cast infernal tutor
							floating_mana = floating_mana + potential_manaTutor;//Sacrifice Lion's Eye Diamond to gain the mana while casting Infernal Tutor
							floating_mana = floating_mana - 2;//Substract the Infernal tutor CMC from floating mana
							storm_count++;//cast past in flames
							floating_mana = floating_mana - 4;//Subtract the Past in Flames mana
							for (i = 0; i < 59; i++){
								if (hand[i].getCardname() == "card"){

									break;
								}
								if (hand[i].getCardname() == "Dark Ritual") {
									storm_count++;
									floating_mana = floating_mana + 2;
								}
								if (hand[i].getCardname() == "Cabal Ritual"){
									storm_count++;
									floating_mana = floating_mana + 3;
								}
							}
							storm_count++;//cast infernal tutor from graveyard
							floating_mana = floating_mana - 2;
							if (floating_mana >= 4){

								if (storm_count >= required_storm){
									storm_count++;//cast Tendrils of Agony
									cout << "\nYou win the game! You cast Tendrils of Agony with a storm count of " << storm_count;
									//return 0;
									wins++;
									
								}
							}
						}
					}
				}
			}

			for (i = 0; i < 59; i++){
				if (hand[i].getCardname() == "card"){

					break;
				}
				if (hand[i].getCardname() == "Infernal Tutor" && potential_manaTutor>0){
					
					
					if (deck[55].getCardname() == "Past in Flames" || deck[56].getCardname() == "Past in Flames"){
						    if (floating_mana + potential_manaTutor >= 7 && ritual_mana >= 5 && darkritual_binary == 1){
								storm_count++;//cast infernal tutor
								floating_mana = floating_mana + potential_manaTutor;
								floating_mana = floating_mana - 2;
								storm_count++;//cast past in flames
								floating_mana = floating_mana - 4;
								for (i = 0; i < 59; i++){
									if (hand[i].getCardname() == "card"){
	
									break;
								}
									if (hand[i].getCardname() == "Dark Ritual"){
									storm_count++;
									floating_mana = floating_mana + 2;
								}
									if (hand[i].getCardname() == "Cabal Ritual")
								{
									storm_count++;
									floating_mana = floating_mana + 3;
								}
							}
							storm_count++;//cast infernal tutor from graveyard
							floating_mana = floating_mana - 2;
							if (floating_mana >= 4){
								storm_count++;//cast Tendrils of Agony
								cout << "\nYou win the game! You used Past in Flames to raise storm count and then you cast Tendrils of Agony with a storm count of " << storm_count;
								//return 0;
								wins++;
								
							}
						}
					}
				}

			}

			//cout << "\nOh no! You couldn't defeat your opponent this turn with the cards revealed off Ad Nauseam! You lose the game.";
			for (int i = 0; i < 59; i++){
				hand[i].resetCard();
			}
			
		}

		double win_percentage;
		loss = number_of_iterations - wins;
		win_percentage = (wins / (wins+loss))*100;
		
		cout << "\nThe number of wins was " << wins;
		cout << "\nThe number of losses was " << loss;
		cout << "\nWith the given initial conditions you had a win percentage of " << win_percentage << "%!";

		return 0;
	}
