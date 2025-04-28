#include <stdio.h>


int Eingabe(char Berechnungsart);
int Volumen_berechnen();


int main () {

    char Berechnungsart;

    printf("\n Spat-Produkt \n\n Bitte geben Sie an, ob Sie das Volumen mithilfe von Seitenvektoren oder 6 Punkten berechnen wollen. \n Die Eingabe erfolgt über die Tastertur \n für Vektoren mit [V], \n für Punkte mit [P] \n ");
    scanf("%c",&Berechnungsart);

    Eingabe (Berechnungsart);




    // weitere Rechnung durchführen?



} // Ende main

int Eingabe (char Berechnungsart) {

    int Vektor_1 [3] = {0}; //Stimmt das, dass ich das Array 4 groß gemacht hab? obwohl ich nur 3 Stellen habe?
    int Vektor_2 [3] = {0};
    int Vektor_3 [3] = {0};

    int *Vektoren [] = {Vektor_1, Vektor_2, Vektor_3};

    int Punkt_1 [3] = {0};
    int Punkt_2 [3] = {0};
    int Punkt_3 [3] = {0};
    int Punkt_4 [3] = {0};
    int Punkt_5 [3] = {0};
    int Punkt_6 [3] = {0};

    int *Punkte [6] = {Punkt_1, Punkt_2, Punkt_3, Punkt_4, Punkt_5, Punkt_6};


    // Berechnungsart muss immer in Großbuchstaben umgewandelt werden

    switch (Berechnungsart) {
        case 'V': printf("\n Bitte geben Sie der Reihe nach Ihre 3 Vektoren ein und trennen Sie Ihre Zahlen durch ein Semikolon, die Eingabe wird mit Enter bestätigt: \n");
                  for (int i = 0; i < 3; i++) {
                    printf(" %d. Vektor:", i+1);
                    scanf("%d;%d;%d", &Vektoren[i][0], &Vektoren[i][1], &Vektoren[i][2]);
                    //printf("1: %d %d %d", Vektor_1[0], Vektor_1 [1], Vektor_1[2]);
                    //printf("2: %d %d %d", Vektor_2[0], Vektor_2 [1], Vektor_2[2]);
                    //printf("3: %d %d %d", Vektor_3[0], Vektor_3 [1], Vektor_3[2]);
                    //scanf ("1. Vektor: %d;%d;%d", &Vektor_1 [0], &Vektor_1 [1], &Vektor_1 [2]);
                    //printf("test: %d %d %d", Vektor_1[0], Vektor_1 [1], Vektor_1[2]);
                  }
                  break;
        case 'P': printf("\n Bitte geben Sie der Reihe nach Ihre 6 Punkte ein und trennen Sie Ihre Zahlen durch ein Semikolon, die Eingabe wird mit Enter bestätigt: \n");
                  for (int i = 0; i < 6; i ++) {
                    printf (" %d. Punkt:", i+1);
                    scanf("%d;%d;%d", &Punkte[i][0], &Punkte[i][1], &Punkte[i][2]);
                  }
                  for (int i = 0; i < 3; i++) {
                    Vektor_1[i] = Punkt_1[i] - Punkt_2[i];
                    Vektor_2[i] = Punkt_3[i] - Punkt_4[i];
                    Vektor_3[i] = Punkt_5[i] - Punkt_6[i];
                  }
                  break;
        default: printf("Keine gültige Eingabe");
                 // Programm von vorne Starten!
    }

    for (int i = 0; i < 3; i++) {
      printf("1.Vektor: (%d; %d; %d) \n", Vektoren[i][0], Vektoren[i][1], Vektoren[i][2]);
    //printf("1.Vektor: (%d; %d; %d) \n", Vektor_1[0], Vektor_1[1], Vektor_1[2]);
    }
   

} // Ende Eingabe




int Volumen_berechnen() {



} // Ende Volumen_berechnen