#ifndef _SPOONS_GAME
#define _SPOONS_GAME 1
#include "player.hpp"

class Game {
	Player **players;
	Dealer *dealer;
	size_t playercount;
	public:
		Game(size_t playerCount);
		~Game();
};

#endif
