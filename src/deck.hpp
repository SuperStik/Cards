#ifndef _CARDGAME_DECK
#define _CARDGAME_DECK 1
#define DECK_SIZE 52u
#include "card.hpp"
#include "utils.h"
#include <cstdlib>

class Deck {
	Card **cards;
	unsigned size;

	public:
		Deck();
		Deck(const Deck &deck);
		Deck(const Deck *deck);
		~Deck();

		void Print() const;
		unsigned Size() const { return size; }
		Card *Deal();
		static void PrintHand(Card **c, size_t size);
		static void DestroyHand(Card **c, size_t size);
};

#endif
