#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

char *random_card_name(){
    enum c{heart = 0, spade = 1, club = 2, cross = 3};
    srand(time(NULL));
    int r = rand() % ( 3 + 1);
    char *s = "Error";
    switch(r){
        case heart:
            s = "heart";
            break;
        case spade:
            s = "spade";
            break;
        case club:
            s = "club";
            break;
        case cross:
            s = "cross";
            break;
        default:
            s = "Error";
            break;
    }
    return s;
    }

int random_card_number(){
    srand(time(NULL));
    int r = rand() % ( 10 + 1);
    return r;
    }

int main(){
    char *s;
    int n = 0;
    struct Card{
        char *string;
        int number;
    };

    struct Card card1;

    s = random_card_name();
    card1.string = s;
    n = random_card_number();
    card1.number = n;
    printf("%s ", card1.string);
    printf("%i", card1.number);
    scanf("");
}
