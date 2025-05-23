#include <stdio.h>

/*
    Ersteller:      Tristan Bihler
    Erstellt am:    19.03.2025
    Version:        1.0.0

    Die Aufgabe ist es, eine eingegebene 4x4 Matrix mit einem eingegebenen Vektor zu multiplizieren und den Ergebenisvektor am ende des Programms auszugeben.
*/

//Funktionenprototypen deklarieren.
int matritzeneingabe(int maxzeile, int maxspalte, int *m1);
int matritzenausgabe(int maxzeile, int maxspalte, int *m1);

//main Funktion einleiten.
int main(){
    //Matritze und Vektoren deklarieren und alle Elemente Null setzen. Die Nullen dienen dem Debugging/Fehlererkennung.
    int eingabematrix[4][4] = {0};
    int ergebnisvektor[4] = {0};
    int vektor[4] = {0};

    //Zeiger deklarieren.
    int *e1;
    int *m1;
    int *v1;

    //Zeiger auf Matritzen/Vektoren zeigen lassen.
    v1 = &vektor[0];
    m1 = &eingabematrix[0][0];
    e1 = &ergebnisvektor[0];

    printf("\nMatritzen und Vektor Multiplikations Rechner:\n");

    //Matrixeingabe Funktion, max Reihe, max Spalte und Zeiger für Matrix weitergeben.
    printf("\nGeben Sie Ihre 4x4 Matrix, Element fuer Element, ein:\n");
    matritzeneingabe(4, 4, m1);
    
    //Matrixausgabe Funktion, max Reige, max Spalte und Zeiger für Matrix weitergeben.
    printf("\nIhre Matrix ist:\n");
    matritzenausgabe(4, 4, m1);

    //Matrixeingabe Funktion, max Reihe, max Spalte und Zeiger für Vektor weitergeben.
    printf("\nGeben Sie Ihren 4x1 Vektor, Element fuer Element, ein:\n");
    matritzeneingabe(4, 1, v1);

    //Matrixausgabe Funktion, max Reihige, max Spalte und Zeiger für Vektor weitergeben.
    printf("\nIhr Vektor ist:\n");
    matritzenausgabe(4, 1, v1);

    //Matrix Vektor Multiplikation. i ergibt die Zeilen und j die Spalten.
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ergebnisvektor[i] = ergebnisvektor[i] + eingabematrix[i][j] * vektor[j];
        }
    }

    //Matrixausgabe Funktion, max Reige, max Spalte und Zeiger für Ergebnisvektor weitergeben.
    printf("\nDer Ergebnisvektor ist:\n");
    matritzenausgabe(4, 1, e1);
}

//Matritzeneingabe Funktion, for schleife geht jede Position der Matrix/Vektor ab und schreibt die durch scanf gefragte Zahl, an dieser Stelle, in die Matrix/Vektor ein.
int matritzeneingabe(int maxzeile, int maxspalte, int *m1){
    for(int i = 0; i < (maxzeile * maxspalte); i++){
        printf("An der Stelle a%i a%i ", (i / 4 + 1), (i % 4 + 1));
        scanf("%i", &*m1);
        m1++;
    }
}

//Matritzenausgabe Funktion, for Schleife geht jede Position der Matrix/Vektor durch und liest jede Zahl aus und schreibt diese durch prinf aus.
int matritzenausgabe(int maxzeile, int maxspalte, int *m1){
    for(int i = 0; i < (maxzeile * maxspalte); i++){
           printf("%i ", *m1);

           if((i + 1) % maxspalte  == 0){     // Wenn i durch maxspalte einen rest von null hat, dann in die nächste Zeile gehen.
                printf("\n");
           }
           m1++;
    }
}

