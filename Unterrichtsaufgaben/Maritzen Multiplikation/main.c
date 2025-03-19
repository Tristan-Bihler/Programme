#include <stdio.h>

/*
    Tristan Bihler
    19.03.2025
    Die Aufgabe ist es, eine eingegebene Matrix mit einem eingegebenen Vektor zu multiplizieren und die Ergebnismatrix am ende des Programms auszugeben.
*/

//Funktionen deklarieren
int matritzeneingabe(int maxzeile, int maxreihe, int *m1);
int matritzenausgabe(int maxzeile, int maxreihe, int *m1);

//main Funktion einleiten
int main(){
    //matritzen und vektor deklarieren
    int eingabematrix[4][4] = {0};
    int ergebnismatrix[4][4] = {0};
    int vektor[4] = {0};

    //Zeiger deklarieren
    int *e1;
    int *m1;
    int *v1;

    //Zeiger auf Matritzen Vektoren zeigen lassen
    v1 = &vektor[0];
    m1 = &eingabematrix[0][0];
    e1 = &ergebnismatrix[0][0];

    //Matrixeingabe Funktion, max Reihe, max Spalte und Zeiger für Matrix weitergebn
    printf("Geben ihre Matrix ein\n");
    matritzeneingabe(4, 4, m1);
    
    //Matrixausgabe Funktion, max Reige, max Spalte und Zeiger für Matrix weitergeben
    printf("Ihre Matrix ist\n");
    matritzenausgabe(4, 4, m1);

    //Matrixeingabe Funktion, max Reihe, max Spalte und Zeiger für Vektor weitergebn
    printf("Geben sie ihren Vektor ein\n");
    matritzeneingabe(4, 1, v1);

    //Matrixausgabe Funktion, max Reige, max Spalte und Zeiger für Vektor weitergeben
    printf("Ihr Vektor ist\n");
    matritzenausgabe(4, 1, v1);

    //Matrix Vektor Multiplikation
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ergebnismatrix[i][j] = eingabematrix[i][j] * vektor[j];
        }
    }

    //Matrixausgabe Funktion, max Reige, max Spalte und Zeiger für Matrix weitergeben
    printf("Die endgueltige Matrix ist\n");
    
    matritzenausgabe(4, 4, e1);
}

//Matritzeneingabe Funktion, for schleife geht jede Position der Matrix/Vektor ab und schreibt die durch scanf gefragte Zahl an dieser Stelle in die Matrix/Vektor rein.
int matritzeneingabe(int maxzeile, int maxreihe, int *m1){
    for(int i = 0; i < maxzeile * maxreihe; i++){
        printf("An der Stelle %i %i ", 1 + i / 4, 1 + i % 4);
        scanf("%i ", &*m1);
        m1++;
    }
}

//Matritzenausgabe Funktion, for Schleife geht jede Position der Matrix/Vektor durch und liest jede Zahl aus und schreibt diese durch prinf aus.
int matritzenausgabe(int maxzeile, int maxreihe, int *m1){
    for(int i = 0; i < maxzeile * maxreihe; i++){
           printf("%i ", *m1);

           if((i + 1) % maxreihe  == 0){     // Wenn i durch maxreihe einen rest von null hat, dann in die nächste Zeile gehen
                printf("\n");
           }
           m1++;
    }
}

