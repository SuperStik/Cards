#include <ctime>
#include "dealer.hpp"

int main() {
	srand(time(NULL));
	rand();
	Dealer *dealer = new Dealer();
	dealer->Print();
	putchar('\n');
	PRINTINT(dealer->Size());
	Card** cards = dealer->Deals(24);
	Deck::PrintHand(cards, 24);
	putchar('\n');
	dealer->Print();
	putchar('\n');
	PRINTINT(dealer->Size());
	Deck::DestroyHand(cards, 24);
	delete dealer;
	return 0;
}
