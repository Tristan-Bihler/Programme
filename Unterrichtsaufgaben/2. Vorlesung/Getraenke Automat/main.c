#include <stdio.h>

int main(){
    int auswahl = 0;
    int menge = 0;
    float Geld = 0;
    float eingeworfen = 0;

    printf("Bitte wählen sie ein Getränk aus:\n");
    printf("1) Wasser (0,50 Euro)\n");
    printf("2) Limonade (1,00 Euro)\n");
    printf("3) Bier (2,00 Euro)\n");
    scanf("%i", &auswahl);

    printf("Geben sie die Menge an\n");
    scanf("%i", &menge);

    switch(auswahl){
        case 1:
            do{
                printf("Bitte werfen sie %0.2f Geld ein:\n", menge * 0.5 - Geld);
                scanf("%f", &eingeworfen);
                Geld = Geld + eingeworfen;
                
            }
            while(Geld < (0.5 * menge));
            break;
        
        case 2:
            do{
                printf("Bitte werfen sie %0.2f Geld ein:\n", menge * 1 - Geld);
                scanf("%f", &eingeworfen);
                Geld = Geld + eingeworfen;
                
            }
            while(Geld < (1 * menge));
            break;
        case 3:
            do{
                printf("Bitte werfen sie %0.2f Geld ein:\n", menge * 2 - Geld);
                scanf("%f", &eingeworfen);
                Geld = Geld + eingeworfen;
                
            }
            while(Geld < (2 * menge));
            break;
    }
    for (int i = 1; i <= menge; i++){
        printf("Flasche %i wurde ausgegeben\n", i);
    }
}