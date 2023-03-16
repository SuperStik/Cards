#ifndef _CARDGAME_DEALER
#define _CARDGAME_DEALER 1
#include "deck.hpp"

class Dealer {
	Deck *deck;
	
	public:
		Dealer();
		~Dealer() { delete deck; };

		Card **Deals(unsigned n);
		size_t Size() const { return deck->Size(); }
		void Print() const { deck->Print(); };
};

#endif