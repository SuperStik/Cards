#ifndef _CARDGAME_CARD
#define _CARDGAME_CARD 1
#include <cstdio>

enum RankVal {
	RANK_2 = 2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_J,
	RANK_Q,
	RANK_K,
	RANK_A,
	RANK_MAX
};

enum SuitVal {
	SUIT_SPADES,
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_MAX
};

struct Card {
	SuitVal Suit;
	RankVal Value;

	Card() : Suit(SUIT_SPADES), Value(RANK_A) {}
	Card(SuitVal s, RankVal r) : Suit(s), Value(r) {}
	Card(const Card &card) : Suit(card.Suit), Value(card.Value) {}
	Card(const Card *card) : Suit(card->Suit), Value(card->Value) {}

	void Print() const;
	bool Equals(const Card &card) const;
	bool Equals(const Card *card) const;
};

#endif
