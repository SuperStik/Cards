#include "dealer.hpp"

Dealer::Dealer() {
	if (!(deck = new Deck())) {
		errs("Failed to allocate card array!");
		exit(EXIT_FAILURE);
	}
}

Card **Dealer::Deals(unsigned n) {
	Card** newDeck = (Card**)malloc(sizeof(Card*) * n);
	//n = (n <= deck->Size()) ? n : (deck->Size());
	if (!newDeck) {
		errs("Failed to allocate card array!");
		exit(EXIT_FAILURE);
	}

	for (unsigned i = 0; i < n; ++i)
		newDeck[i] = deck->Deal();
	return newDeck;
}
