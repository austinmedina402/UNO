#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "functionDefine.h"

card createActive(card* deck, int* topDeck) {
    card temp;
    strcpy(temp.color, deck[*topDeck].color); //creates the new card
    temp.value = deck[*topDeck].value;
    strcpy(temp.action, deck[*topDeck].action);
    temp.pt = NULL;
    *topDeck = *topDeck - 1;

    return temp;
}

void shuffleCards(card* deck) {
    srand(time(NULL));
    for (int j = 0; j < 108; j++) { //randomize cards
        for (int i = 0; i < 108; i++) {
            int r = rand() % 108;
            card temp;
            temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
    }
}

card* createHand(card* deck, int* topDeck) {
    card* newCard = NULL, * handFront = NULL, * nextCard = NULL;
    newCard = (card*)malloc(sizeof(card)); //allocates memory for new card
    strcpy(newCard->color, deck[*topDeck].color); //creates the new card
    newCard->value = deck[*topDeck].value;
    strcpy(newCard->action, deck[*topDeck].action);
    newCard->pt = NULL;
    handFront = newCard;
    nextCard = newCard;
    nextCard->pt = NULL;
    *topDeck = *topDeck - 1;

    return handFront;
}

void printHand(card* hand) {
    while (hand != NULL) {
        if (hand->value == 14) {
            char sp[8] = "wildFour";
            printf("\033[38m-------------\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|  \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m |\n", sp[0], sp[1], sp[2], sp[3], sp[4], sp[5], sp[6], sp[7]);
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m-------------\033[0m\n");
        }
        else if (hand->value == 13) {
            char sp[4] = "wild";
            printf("\033[38m-------------\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|   \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m    |\n", sp[0], sp[1], sp[2], sp[3]);
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m|           |\033[0m\n");
            printf("\033[38m-------------\033[0m\n");
        }
        else if (strcmp(hand->color, "red") == 0) {
            if (strcmp(hand->action, "reverse") == 0 || strcmp(hand->action, "skip") == 0 || strcmp(hand->action, "plusTwo") == 0) {
                if (strcmp(hand->action, "reverse") == 0) {
                    printf("\033[31m--------------\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|  %s   |\033[0m\n", hand->action);
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "skip") == 0) {
                    printf("\033[31m--------------\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|    %s    |\033[0m\n", hand->action);
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "plusTwo") == 0) {
                    printf("\033[31m--------------\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|  %s   |\033[0m\n", hand->action);
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m|            |\033[0m\n");
                    printf("\033[31m--------------\033[0m\n");
                }
            }
            else
            {
                printf("\033[31m-------------\033[0m\n");
                printf("\033[31m|%d          |\033[0m\n", hand->value);
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|     %d     |\033[0m\n", hand->value);
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|         %d |\033[0m\n", hand->value);
                printf("\033[31m-------------\033[0m\n");
            }
        }
        else if (strcmp(hand->color, "blue") == 0) {
            if (strcmp(hand->action, "reverse") == 0 || strcmp(hand->action, "skip") == 0 || strcmp(hand->action, "plusTwo") == 0) {
                if (strcmp(hand->action, "reverse") == 0) {
                    printf("\033[34m--------------\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|  %s   |\033[0m\n", hand->action);
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "skip") == 0) {
                    printf("\033[34m-------------\033[0m\n");
                    printf("\033[34m|           |\033[0m\n");
                    printf("\033[34m|           |\033[0m\n");
                    printf("\033[34m|    %s   |\033[0m\n", hand->action);
                    printf("\033[34m|           |\033[0m\n");
                    printf("\033[34m|           |\033[0m\n");
                    printf("\033[34m-------------\033[0m\n");
                }
                else if (strcmp(hand->action, "plusTwo") == 0) {
                    printf("\033[34m--------------\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|  %s   |\033[0m\n", hand->action);
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m|            |\033[0m\n");
                    printf("\033[34m--------------\033[0m\n");
                }
            }
            else
            {
                printf("\033[34m-------------\033[0m\n");
                printf("\033[34m|%d          |\033[0m\n", hand->value);
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|     %d     |\033[0m\n", hand->value);
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|         %d |\033[0m\n", hand->value);
                printf("\033[34m-------------\033[0m\n");
            }
        }
        else if (strcmp(hand->color, "yellow") == 0) {
            if (strcmp(hand->action, "reverse") == 0 || strcmp(hand->action, "skip") == 0 || strcmp(hand->action, "plusTwo") == 0) {
                if (strcmp(hand->action, "reverse") == 0) {
                    printf("\033[33m--------------\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|  %s   |\033[0m\n", hand->action);
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "skip") == 0) {
                    printf("\033[33m--------------\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|    %s    |\033[0m\n", hand->action);
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "plusTwo") == 0) {
                    printf("\033[33m--------------\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|  %s   |\033[0m\n", hand->action);
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m|            |\033[0m\n");
                    printf("\033[33m--------------\033[0m\n");
                }
            }
            else
            {
                printf("\033[33m-------------\033[0m\n");
                printf("\033[33m|%d          |\033[0m\n", hand->value);
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|     %d     |\033[0m\n", hand->value);
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|        %d  |\033[0m\n", hand->value);
                printf("\033[33m-------------\033[0m\n");
            }
        }
        if (strcmp(hand->color, "green") == 0) {
            if (strcmp(hand->action, "reverse") == 0 || strcmp(hand->action, "skip") == 0 || strcmp(hand->action, "plusTwo") == 0) {
                if (strcmp(hand->action, "reverse") == 0) {
                    printf("\033[32m--------------\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|  %s   |\033[0m\n", hand->action);
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "skip") == 0) {
                    printf("\033[32m--------------\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|    %s    |\033[0m\n", hand->action);
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m--------------\033[0m\n");
                }
                else if (strcmp(hand->action, "plusTwo") == 0) {
                    printf("\033[32m--------------\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|  %s   |\033[0m\n", hand->action);
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m|            |\033[0m\n");
                    printf("\033[32m--------------\033[0m\n");
                }
            }
            else
            {
                printf("\033[32m-------------\033[0m\n");
                printf("\033[32m|%d          |\033[0m\n", hand->value);
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|     %d     |\033[0m\n", hand->value);
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|         %d |\033[0m\n", hand->value);
                printf("\033[32m-------------\033[0m\n");
            }
        }
        hand = hand->pt;
    }
}

void printActive(card* active) {
    printf("\nCard in the middle:\n");
    if (active->value > 12) {
        if (strcmp(active->action, "wildFour") == 0) {
            char hand[8] = "wildFour";
            if (strcmp(active->color, "red") == 0) {
                printf("\033[31m-------------\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|  \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m |\033[0m\n", hand[0], hand[1], hand[2], hand[3], hand[4], hand[5], hand[6], hand[7]);
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "blue") == 0) {
                printf("\033[34m-------------\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|  \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[34m |\033[0m\n", hand[0], hand[1], hand[2], hand[3], hand[4], hand[5], hand[6], hand[7]);
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "yellow") == 0) {
                printf("\033[33m-------------\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|  \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[33m |\033[0m\n", hand[0], hand[1], hand[2], hand[3], hand[4], hand[5], hand[6], hand[7]);
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "green") == 0) {
                printf("\033[32m-------------\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|  \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[0m\033[32m |\033[0m\n", hand[0], hand[1], hand[2], hand[3], hand[4], hand[5], hand[6], hand[7]);
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m-------------\033[0m\n");
            }
        }
        else if (strcmp(active->action, "wild") == 0) {
            char hand[8] = "wild";
            if (strcmp(active->color, "red") == 0) {
                printf("\033[31m-------------\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|   \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[31m    |\033[0m    \n", hand[0], hand[1], hand[2], hand[3]);
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m|           |\033[0m\n");
                printf("\033[31m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "blue") == 0) {
                printf("\033[34m-------------\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|   \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[34m    |\033[0m    \n", hand[0], hand[1], hand[2], hand[3]);
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "yellow") == 0) {
                printf("\033[33m-------------\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|   \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[33m    |\033[0m    \n", hand[0], hand[1], hand[2], hand[3]);
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m|           |\033[0m\n");
                printf("\033[33m-------------\033[0m\n");
            }
            else if (strcmp(active->color, "green") == 0) {
                printf("\033[32m-------------\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|   \033[31m%c\033[0m\033[32m%c\033[0m\033[33m%c\033[0m\033[34m%c\033[32m    |\033[0m    \n", hand[0], hand[1], hand[2], hand[3]);
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m|           |\033[0m\n");
                printf("\033[32m-------------\033[0m\n");
            }
        }
     }
    else if (strcmp(active->color, "red") == 0) {
        if (strcmp(active->action, "reverse") == 0 || strcmp(active->action, "skip") == 0 || strcmp(active->action, "plusTwo") == 0) {
            if (strcmp(active->action, "reverse") == 0) {
                printf("\033[31m--------------\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|  %s   |\033[0m\n", active->action);
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "skip") == 0) {
                printf("\033[31m--------------\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|    %s    |\033[0m\n", active->action);
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "plusTwo") == 0) {
                printf("\033[31m--------------\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|  %s   |\033[0m\n", active->action);
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m|            |\033[0m\n");
                printf("\033[31m--------------\033[0m\n");
            }
        }
        else
        {
            printf("\033[31m-------------\033[0m\n");
            printf("\033[31m|%d          |\033[0m\n", active->value);
            printf("\033[31m|           |\033[0m\n");
            printf("\033[31m|     %d     |\033[0m\n", active->value);
            printf("\033[31m|           |\033[0m\n");
            printf("\033[31m|         %d |\033[0m\n", active->value);
            printf("\033[31m-------------\033[0m\n");
        }
    }
    else if (strcmp(active->color, "blue") == 0) {
        if (strcmp(active->action, "reverse") == 0 || strcmp(active->action, "skip") == 0 || strcmp(active->action, "plusTwo") == 0) {
            if (strcmp(active->action, "reverse") == 0) {
                printf("\033[34m-------------\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|  %s  |\033[0m\n", active->action);
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m|           |\033[0m\n");
                printf("\033[34m-------------\033[0m\n");
            }
            else if (strcmp(active->action, "skip") == 0) {
                printf("\033[34m--------------\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|    %s    |\033[0m\n", active->action);
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "plusTwo") == 0) {
                printf("\033[34m--------------\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|  %s   |\033[0m\n", active->action);
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m|            |\033[0m\n");
                printf("\033[34m--------------\033[0m\n");
            }
        }
        else
        {
            printf("\033[34m-------------\033[0m\n");
            printf("\033[34m|%d          |\033[0m\n", active->value);
            printf("\033[34m|           |\033[0m\n");
            printf("\033[34m|     %d     |\033[0m\n", active->value);
            printf("\033[34m|           |\033[0m\n");
            printf("\033[34m|          %d|\033[0m\n", active->value);
            printf("\033[34m-------------\033[0m\n");
        }
    }
    else if (strcmp(active->color, "yellow") == 0) {
        if (strcmp(active->action, "reverse") == 0 || strcmp(active->action, "skip") == 0 || strcmp(active->action, "plusTwo") == 0) {
            if (strcmp(active->action, "reverse") == 0) {
                printf("\033[33m--------------\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|  %s   |\033[0m\n", active->action);
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "skip") == 0) {
                printf("\033[33m--------------\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|    %s    |\033[0m\n", active->action);
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "plusTwo") == 0) {
                printf("\033[33m--------------\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|  %s   |\033[0m\n", active->action);
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m|            |\033[0m\n");
                printf("\033[33m--------------\033[0m\n");
            }
        }
        else
        {
            printf("\033[33m-------------\033[0m\n");
            printf("\033[33m|%d          |\033[0m\n", active->value);
            printf("\033[33m|           |\033[0m\n");
            printf("\033[33m|     %d     |\033[0m\n", active->value);
            printf("\033[33m|           |\033[0m\n");
            printf("\033[33m|          %d|\033[0m\n", active->value);
            printf("\033[33m-------------\033[0m\n");
        }
    }
    else if (strcmp(active->color, "green") == 0) {
        if (strcmp(active->action, "reverse") == 0 || strcmp(active->action, "skip") == 0 || strcmp(active->action, "plusTwo") == 0) {
            if (strcmp(active->action, "reverse") == 0) {
                printf("\033[32m--------------\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|  %s   |\033[0m\n", active->action);
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "skip") == 0) {
                printf("\033[32m--------------\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|    %s    |\033[0m\n", active->action);
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m|            |\033[0m\n");
                printf("\033[32m--------------\033[0m\n");
            }
            else if (strcmp(active->action, "plusTwo") == 0) {
            printf("\033[32m--------------\033[0m\n");
            printf("\033[32m|            |\033[0m\n");
            printf("\033[32m|            |\033[0m\n");
            printf("\033[32m|  %s   |\033[0m\n", active->action);
            printf("\033[32m|            |\033[0m\n");
            printf("\033[32m|            |\033[0m\n");
            printf("\033[32m--------------\033[0m\n");
            }
        }
        else {
        printf("\033[32m-------------\033[0m\n");
        printf("\033[32m|%d          |\033[0m\n", active->value);
        printf("\033[32m|           |\033[0m\n");
        printf("\033[32m|     %d     |\033[0m\n", active->value);
        printf("\033[32m|           |\033[0m\n");
        printf("\033[32m|         %d |\033[0m\n", active->value);
        printf("\033[32m-------------\033[0m\n");
        }
    }

}

void addCard(card* deck, card* hand, int* topDeck) {
    card* newCard = NULL, * nextCard = NULL;

    newCard = (card*)malloc(sizeof(card)); //allocates memory for new card
    strcpy(newCard->color, deck[*topDeck].color); //creates the new card
    newCard->value = deck[*topDeck].value;
    strcpy(newCard->action, deck[*topDeck].action);
    newCard->pt = NULL;


    if (hand == NULL) { //if no cards, adds newCard as the first card
        hand = newCard;
    }
    else {
        while (hand->pt != NULL) { //traverses the linked list to the end
            hand = hand->pt;
        }
        hand->pt = newCard; //links the end of the hand, to the new card
    }
    hand = newCard;
    *topDeck = *topDeck - 1;
}

void deleteCard(card** hand, int numCard) {
    card* temp = NULL;
    temp = (card*)malloc(sizeof(card));

    card* temp2 = NULL;
    temp2 = (card*)malloc(sizeof(card));
    temp2 = *hand;
    temp = *hand;

    if (numCard == 1) {
        (*hand) = (*hand)->pt;
    }
    else {
        for (int i = 0; i < (numCard - 1); i++) {  // looks for card in the hand
            temp = temp->pt;

        }

        for (int j = 0; j < (numCard - 2); j++) { //replaces the link of the previous card with the link to the next card
            temp2 = temp2->pt;
        }

        temp2->pt = temp->pt;
    }
    free(temp);
}

card playCard(card* hand, int numCard) {
    for (int i = 0; i < (numCard - 1); i++) {  // looks for card in the hand
        hand = hand->pt;
    }
    card temp;
    strcpy(temp.color, hand->color); //creates the new card
    temp.value = hand->value;
    strcpy(temp.action, hand->action);
    temp.pt = NULL;
    return temp;
}

bool validCard(card active, card* hand, int numCard) {
    for (int i = 1; i < numCard; i++) {  // looks for card in the hand
        hand = hand->pt;
    }
    //printHand(hand);
    if (hand->value == active.value) {
        return true;
    }
    else if (strcmp(hand->color, active.color) == 0) {
        return true;
    }
    else if ((strcmp(hand->action, active.action) == 0) && (hand->value > 9)) {
        return true;
    }
    else if ((strcmp(hand->color, "black") == 0) && (strcmp(hand->action, "wild") == 0)) {
        return true;
    }
    else if ((strcmp(hand->color, "black") == 0) && (strcmp(hand->action, "wildFour") == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int incriment(int rev, int k, int numPlayer) {
    if (rev == 1) {
        k = k + 1;
        if (k > (numPlayer - 1)) {
            k = 0;
        }
    }
    else {
        k = k - 1;
        if (k < 0) {
            k = (numPlayer - 1);
        }
    }

    return k;
}

int countCard(card* hand) {
    int c = 1;
    if (hand == NULL) { //winning condition
        c = 0;
    }
    else {
        while (hand->pt != NULL) { //traverses the linked list to the end
            hand = hand->pt;
            c++; //counts cards
        }
    }
    return c;
}