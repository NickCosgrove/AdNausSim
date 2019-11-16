#include <iostream>
#include <string>



class Card{
	private:
		int CMC;
		std::string cardname;


	public:
		
		
		void init(int x, std::string y);
		

		int getCMC();


		std::string getCardname();
};