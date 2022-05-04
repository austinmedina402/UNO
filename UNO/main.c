//Welcome to UNO
//Game developed by Austin Medina and Jorge Del Rio


#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "functionDefine.h"
#include <conio.h>

int main(void) {
    FILE* inp;
    char file[50];
    char ans[5]; // answer if the user wants to play
    int ans2; // answer if the user wants to shuffle the deck
    int numPlayer; //number of players
    int topDeck = 107; // used for selecting the top card of the deck
    int numCard; //player defined card they pick. Answer if to choose a card or draw a card
    bool valid; // check if player played a valid card
    char color[10]; //for wild or plusfour card
    int k = 0; //controls player turn
    int rev = 1; // controls flow of players
    int w = 0; //checks the last players deck to see if  empty. If empty, they win

    printf("Enter the name of the deck file you would like to open:");
    scanf("%s", file);
    inp = fopen(file, "r"); //opens file of cards
    if (inp == NULL) {
        printf("ERROR: Deck could not be openned\n");
        return -1;
    }
    card* deck = NULL;
    deck = (card*)malloc(108 * sizeof(card)); //allocates memory for deck
    for (int i = 0; i < 108; i++) { //reads deck
        fscanf(inp, "%s", deck[i].color);
        fscanf(inp, "%d", &deck[i].value);
        fscanf(inp, "%s", deck[i].action);
        deck[i].pt = NULL;
    }
    system("cls");
    printf("Welcome to UNO. Would you like to play? Enter yes or no.\n");
    scanf("%s", ans);

    while (strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) { //Continues to run the game while the player responds yes to playing
        system("cls");
        printf("Press [1] if you would you like to shuffle the deck.\n");
        printf("Otherwise, press [2] if you would like to use a pre-loaded a deck\n"); 
        scanf("%d", &ans2);
        system("cls");

        while (ans2 != 1 && ans2 != 2) { //makes sure number is either 1 or 2
            printf("Invalid input\n");
            printf("Press [1] if you would you like to shuffle the deck.\n");
            printf("Otherwise, press [2] if you would like to use a pre-loaded a deck\n");
            scanf("%d", &ans2);
            system("cls");
        }

        if (ans2 == 1) { //shuffles deck
            shuffleCards(deck);
            printf("Cards have been shuffled\n\n");
        }

        printf("How many players are playing today?\n");
        scanf("%d", &numPlayer);
        system("cls");
        while (numPlayer > 10 || numPlayer <= 0) { //limits range from 1-8 players
            system("cls");
            printf("Invalid Input\nEnter a number between 1 and 10.\n");
            scanf("%d", &numPlayer);
            system("cls");
        }

        card active = createActive(deck, &topDeck); //creates the first card to be played on
        while (active.value == 14) { //chooses a new top card a reshuffles if the active card is a wild Four
            shuffleCards(deck); //reshuffles card
            topDeck++; //incriments topDeck count back to 107
            active = createActive(deck, &topDeck);
        }
        if (active.value == 10) {
            k++; //skips the first player if the top card is a skip
        }
        else if (active.value == 11) {
            rev = rev * (-1); //reverse the order if the top card is a reverse
        }
        else if (active.value == 13) { //if first card is a wild. Player 1 chooses color and then plays their turn
            system("cls");
            printf("Active card is a wild. What color would you like to change it to?\n");
            scanf("%s", color);
            while ((strcmp(color, "red") != 0) && (strcmp(color, "green") != 0) && (strcmp(color, "blue") != 0) && (strcmp(color, "yellow") != 0)) {
                printf("Invalid color. Enter: red, green, blue, or yellow. Case Sensitive\n");
                printf("What color would you like to change it to?\n");
                scanf("%s", color);
            }
            strcpy(active.color, color); //makes the wild card your color of choice
        }
        card* tempActive = &active; //creates a pointer to active to use in the print function

        card* playerDecks[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }; //creates empty hands

        for (int i = 0; i < numPlayer; i++) { //creates first card in the hand
            playerDecks[i] = createHand(deck, &topDeck);
        }
        for (int i = 0; i < 6; i++) { // creates rest of cards in the hand, by linking them to the header created in the last function
            for (int i = 0; i < numPlayer; i++) {
                addCard(deck, playerDecks[i], &topDeck);
            }
        }
        if (active.value == 12) {
            addCard(deck, playerDecks[k], &topDeck); //adds two card to player 1's deck if the top card is a plus two
            addCard(deck, playerDecks[k], &topDeck);
            k++; //skips player 1's turn
        }

        while (countCard(playerDecks[w]) != 0) { //while a player has cards. Stops running when someone plays their last card
            w = k; //keeps track of the last player to play a card for the count card function
            valid = false;
            while (valid != true) { //continues the loop until a player plays a valid card or draws
                printActive(tempActive);
                printf("Player %d press [0] to draw a card or pick a number from 1 to %d to choose a card from your hand?\n\n", (k + 1), countCard(playerDecks[w]));
                printHand(playerDecks[k]);
                printf("\n");
                scanf("%d", &numCard);
                while ((numCard > countCard(playerDecks[k])) || (numCard < 0)) {
                    system("cls");
                    printf("\nInvalid input. Enter a number between 0 and %d.\n", countCard(playerDecks[k]));
                    printActive(tempActive);
                    printf("Player %d press [0] to draw a card or pick a card from your hand?\n\n", (k + 1));
                    printHand(playerDecks[k]);
                    printf("\n");
                    scanf("%d", &numCard);
                }
                if (numCard != 0) {
                    if (validCard(active, playerDecks[k], numCard)) { //checks if the player can play that card
                        active = playCard(playerDecks[k], numCard); //sets their card to the card in the middle
                        deleteCard(&playerDecks[k], numCard); //deletes the card from their hand
                        if ((strcmp(active.action, "reverse") == 0)) {
                            rev = rev * (-1); //controls the rotation. Multiplying by negative one flips rotation, 
                        }
                        else if ((strcmp(active.action, "skip") == 0)) {
                            k = incriment(rev, k, numPlayer); //incriments by 1, and the end of the loop at line 157 incriments again, skipping a player. 
                            //incriment function works for plusTwo, and wildFour
                        }
                        else if ((strcmp(active.action, "plusTwo") == 0)) {
                            k = incriment(rev, k, numPlayer);
                            addCard(deck, playerDecks[k], &topDeck);
                            addCard(deck, playerDecks[k], &topDeck);
                        }
                        else if (strcmp(active.action, "wild") == 0) { //executes wild function
                            printf("What color would you like to change it to?\n");
                            scanf("%s", color);
                            while ((strcmp(color, "red") != 0) && (strcmp(color, "green") != 0) && (strcmp(color, "blue") != 0) && (strcmp(color, "yellow") != 0)) {
                                printf("\nInvalid color. Enter: red, green, blue, or yellow. Case Sensitive\n");
                                printf("What color would you like to change it to?\n");
                                scanf("%s", color);
                            }
                            strcpy(active.color, color); //makes the wild card your color of choice
                        }
                        else if (strcmp(active.action, "wildFour") == 0) { //executes the wild plus 4 card
                            printf("What color would you like to change it to?\n");
                            scanf("%s", color);
                            while ((strcmp(color, "red") != 0) && (strcmp(color, "green") != 0) && (strcmp(color, "blue") != 0) && (strcmp(color, "yellow") != 0)) {
                                printf("Invalid color. Enter: red, green, blue, or yellow. Case Sensitive\n");
                                printf("What color would you like to change it to?\n");
                                scanf("%s", color);
                            }
                            strcpy(active.color, color); //makes the wild card your color of choice
                            k = incriment(rev, k, numPlayer); //goes to the next player so 4 cards can be added to their deck.
                            addCard(deck, playerDecks[k], &topDeck); //The incriment function at the end of the code then goes to the next player, thereby skipping the player that had 4 cards added
                            addCard(deck, playerDecks[k], &topDeck);
                            addCard(deck, playerDecks[k], &topDeck);
                            addCard(deck, playerDecks[k], &topDeck);

                        }
                        valid = true; //the player played a valid card
                    }
                    else { //if they play an incorrect card
                        system("cls");
                        printf("Invalid Card\n");
                    }
                }
                else if (numCard == 0) { //if the user enters 0, they draw a card
                    addCard(deck, playerDecks[k], &topDeck);
                    valid = true;
                }
            }
            system("cls");
            k = incriment(rev, k, numPlayer);
        }
        printf("CONGRATULATIONS!!! You Win!!!\n\n");
        printf("Would you like to play again? Enter yes or no.\n");
        scanf("%s", ans);
        k = 0; //resets k to 0 in case they want to play again
    }
    printf("\nThank you for playing, have a great rest of your day\n");
    return 0;
}