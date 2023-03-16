#ifndef _SPOONS_PLAYER
#define _SPOONS_PLAYER 1
#include "dealer.hpp"

class Player {
	size_t id;
	Card **hand;
	Dealer *dealer;

	public:
		Player(size_t index, Dealer *dealer);
		~Player();

		Card *TakeTurn();
};

#endif
