typedef struct card_s {
    char color[7];
    int value;
    char action[15];
    struct card_s* pt;
} card;

void shuffleCards(card* deck); //shuffles the cards in the deck

card* createHand(card* deck, int* topDeck); //creates the first card for every player. Creating an array of headers

card createActive(card* deck, int* topDeck); //creates the top card that is played on

void printHand(card* hand); //prints a players hand

void printActive(card* active); //prints the top card to be played on

void addCard(card* deck, card* hand, int* topDeck); //adds a card to a players hand

void deleteCard(card** hand, int numCard); //deletes a card from a players hand

card playCard(card* hand, int numCard); //plays a card to the middle. Returns a variable of type card which represents the card played

bool validCard(card active, card* hand, int numCard); //checks if a card can be played

int incriment(int rev, int k, int numPlayer); //moves to the next player, and checks what direction to move. ie player 1 to 2, or player 1 back to player 4 if reversed

int countCard(card* hand); //counts cards in a players hand