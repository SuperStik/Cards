#include "card.hpp"

const char *LookupSuit[5] = {
	"Spades",
	"Clubs",
	"Diamonds",
	"Hearts",
	"Max"
};

const char *QuickLookupNames[5] = {
	"Jack",
	"Queen",
	"King",
	"Ace",
	"Max"
};

void Card::Print(void) const {
	if (Value > RANK_10)
		fputs(QuickLookupNames[Value - RANK_J], stdout);
	else
		printf("%i", Value);
	printf(" of %s", LookupSuit[Suit]);
}

bool Card::Equals(const Card &c) const {
	return (Suit == c.Suit) && (Value == c.Value);
}

bool Card::Equals(const Card *c) const {
	return Value == c->Value;
}
