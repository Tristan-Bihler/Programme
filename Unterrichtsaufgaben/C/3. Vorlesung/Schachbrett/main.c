#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*Das Feld hat eine Größe von 8 x 8
Die Startposition der Figur ist oben links ([0][0])
In einer Schleife werden die Bewegungsbefehle entgegengenommen
Mit den Tasten w, a ,s , d kann man die Figur auf dem Feld bewegen
w hoch, a links, s runter, d rechts
Wird die Spielfeldgrenze überschritten, landet die Figur auf der gegenüberliegenden Seite
Das Programm lässt sich mit x beenden */

int main(){
    int Feld[10][10] = {0};
    int *spieler;
    spieler = &Feld[2][2];
    *spieler = 1;
    char eingabe[1];
    eingabe[0] = 1;
    int indexrow = 2;
    int indexcolumn = 2;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            printf("%i ", Feld[i][j]);
        }
        printf("\n");
    }


    while(strcmp(eingabe, "0") != 0){
        scanf("%s", &eingabe);

        *spieler = 0;

        if(strcmp(eingabe,"w") == 0){
            spieler = spieler + (1 * 10);
        }
        if(strcmp(eingabe,"s") == 0){
            spieler = spieler - (1 * 10);
        }
        if(strcmp(eingabe,"a") == 0){
            spieler --;
        }
        if(strcmp(eingabe,"d") == 0){
            spieler ++;
        }
        *spieler = 1;

        for(int t = 0; t < 10; t++){
            for(int k = 0; k < 10; k++){
                if (Feld[t][k] == 1){
                    indexrow = t;
                    indexcolumn = k;
                }
            }
        }
        printf("%i\n", indexrow);
        printf("%i\n", indexcolumn);

        *spieler = 0;

        if(indexrow == 9){
            spieler = &Feld[1][indexcolumn];
        }
        if(indexrow == 0){
            spieler = &Feld[8][indexcolumn];
        }

        if(indexcolumn == 9){
            spieler = &Feld[indexrow][1];
        }
        if(indexcolumn == 0){
            spieler = &Feld[indexrow][8];
        }

        *spieler = 1;

        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                printf("%i ", Feld[i][j]);
            }
            printf("\n");
        }
        
    }
    return 0;
}