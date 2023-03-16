#include "deck.hpp"

Deck::Deck() {
	size = DECK_SIZE;
	if (!(cards = (Card**)malloc(sizeof(Card*) * DECK_SIZE))) {
		errs("Failed to allocate card array!");
		exit(EXIT_FAILURE);
	}
	unsigned c = 0;

	for (unsigned i = SUIT_SPADES; i < SUIT_MAX; ++i) {
		for (unsigned j = RANK_2; j < RANK_MAX; ++c, ++j) {
			if (!(cards[c] = new Card((SuitVal)i, (RankVal)j))) {
				errs("Failed to allocate card!");
				exit(EXIT_FAILURE);
			}
		}
	}

	// card scrambler
	for (unsigned i = 0; i < (DECK_SIZE); ++i) {
		unsigned j = randomrange(i, DECK_SIZE);
		Card *c = cards[j];
		cards[j] = cards[i];
		cards[i] = c;
	}
}

Deck::Deck(const Deck &deck) {
	size = deck.size;
	if (!(cards = (Card**)malloc(sizeof(Card*) * DECK_SIZE))) {
		errs("Failed to allocate card array!");
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < size; ++i)
		cards[i] = new Card(deck.cards[i]);
}

Deck::Deck(const Deck *deck) {
	size = deck->size;
	if (!(cards = (Card**)malloc(sizeof(Card*) * DECK_SIZE))) {
		errs("Failed to allocate card array!");
		exit(EXIT_FAILURE);
	}

	for (unsigned i = 0u; i < size; ++i)
		cards[i] = new Card(deck->cards[i]);
}

Deck::~Deck() {
	for (unsigned i = 0u; i < size; ++i)
		delete cards[i];
	free(cards);
}

void Deck::Print() const {
	PUTSN("Deck(\n");

	for (unsigned i = 0; i < size; ++i) {
		if (i != 0)
			PUTSN(",\n");
		PUTSN("\t[");
		cards[i]->Print();
		putchar(']');
	}
	PUTSN("\n)");
}

Card *Deck::Deal() {
	if (size == 0)
		return NULL;
	else {
		Card *c = cards[--size];
		cards[size] = NULL;
		return c;
	};
}

void Deck::PrintHand(Card **c, size_t size) {
	PUTSN("Hand(\n");
	for (unsigned i = 0; i < size; ++i) {
		#ifndef _CARDGAME_DEV
		if (!c[i])
			break;
		#endif
		if (i != 0)
			PUTSN(",\n");
		PUTSN("\t[");
		if (c[i])
			c[i]->Print();
		#ifdef _CARDGAME_DEV
		else	
			PUTSN("0 of Pointer");
		#endif
		putchar(']');
	}
	PUTSN("\n)");
}

void Deck::DestroyHand(Card **c, size_t size) {
	for (unsigned i = 0u; i < size; ++i)
		delete c[i];
	free(c);
}
