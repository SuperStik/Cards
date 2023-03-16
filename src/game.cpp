#include "game.hpp"

Game::Game(size_t playerCount) {
	playercount = ((playerCount < 3) ? 3 : playerCount);

	if (!(players = (Player**)malloc(sizeof(Player*) * playercount))) {
		errs("Failed to allocate Player array!");
		exit(EXIT_FAILURE);
	}

	if(!(dealer = new Dealer())) {
		errs("Failed to create new Dealer!");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < playercount; ++i) {
		if (!(players[i] = new Player(i, dealer))) {
			errs("Failed to create new Player!");
			exit(EXIT_FAILURE);
		}
	}
};

Game::~Game() {
	delete dealer;
	for (size_t i = 0; i < playercount; ++i)
		delete players[i];
	free(players);
};
