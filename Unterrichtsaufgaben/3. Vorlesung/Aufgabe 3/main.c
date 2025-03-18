#include <stdio.h>



int main(){
    int Position;
    int Farbe;
    int Feld[3][3] = {0};
    int *spieler;
    spieler = &Feld[0][0];

    for(int i = 0; i < 3; i++){
        for(int j = 1; j < 3; j++){
            printf("%i ", Feld[i][j]);
        }
        printf("\n");
    }

    while (1){
        scanf("%i", &Position);
        spieler = Position;
        scanf("%i", &Farbe);
        *spieler = Farbe;
        for(int i = 0; i < 3; i++){
            for(int j = 1; j < 3; j++){
                printf("%i ", Feld[i][j]);
            }
            printf("\n");
        }
    }
}
    