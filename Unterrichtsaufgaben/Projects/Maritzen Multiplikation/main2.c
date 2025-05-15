#include <stdio.h>

// Definieren der Dimensionen für bessere Lesbarkeit
#define ANZAHL_ZEILEN 4
#define ANZAHL_SPALTEN 4

/*
 * Funktion zum Einlesen der Matrixwerte vom Benutzer.
 */
void matrix_eingabe(int zeilen, int spalten, int matrix_daten[zeilen][spalten]) {
    printf("Matrix eingeben (%d x %d):\n", zeilen, spalten);
    for (int z = 0; z < zeilen; ++z) { // z für Zeile
        for (int s = 0; s < spalten; ++s) { // s für Spalte
            printf("Zelle [%d][%d]: ", z + 1, s + 1);
            // Direkte Eingabe mit scanf
            scanf("%d", &matrix_daten[z][s]);
        }
    }
}

/*
 * Funktion zum Einlesen der Vektorwerte vom Benutzer.
 */
void vektor_eingabe(int laenge, int vektor_daten[laenge]) {
    printf("\nVektor eingeben (%d Zellen):\n", laenge);
    for (int idx = 0; idx < laenge; ++idx) { // idx für Index
        printf("Zelle %d: ", idx + 1);
        // Direkte Eingabe mit scanf
        scanf("%d", &vektor_daten[idx]);
    }
}

/*
 * Funktion zur Ausgabe einer Matrix unter Verwendung eines Zeigers.
 */
void matrix_ausgabe(int zeilen, int spalten, int matrix_daten[zeilen][spalten]) {
    printf("\nEingegebene Matrix:\n");
    // Zeiger 1: Zeigt auf das erste Element der Matrix
    int *zellen_zeiger = &matrix_daten[0][0];
    int anzahl_zellen = zeilen * spalten;

    for (int i = 0; i < anzahl_zellen; ++i) {
        // Wert über den Zeiger ausgeben
        printf("%d\t", *zellen_zeiger);
        // Zeiger zum nächsten Element bewegen
        zellen_zeiger++;

        // Zeilenumbruch nach jeder vollen Zeile
        if ((i + 1) % spalten == 0) {
            printf("\n");
        }
    }
}

/*
 * Funktion zur Ausgabe eines Vektors (als Spaltenvektor) unter Verwendung eines Zeigers.
 */
void vektor_ausgabe(int laenge, int vektor_daten[laenge]) {
    printf("Vektor:\n");
    // Zeiger 2: Zeigt auf das erste Element des Vektors
    int *zellen_zeiger = vektor_daten; // Array-Name zerfällt hier zu einem Zeiger

    for (int i = 0; i < laenge; ++i) {
        // Wert über den Zeiger ausgeben
        printf("%d\n", *zellen_zeiger);
        // Zeiger zum nächsten Element bewegen
        zellen_zeiger++;
    }
}

// Hauptfunktion des Programms
int main() {
    // Arrays deklarieren
    int eingabe_matrix[ANZAHL_ZEILEN][ANZAHL_SPALTEN];
    int eingabe_vektor[ANZAHL_SPALTEN];   // Vektorlänge entspricht Spaltenzahl der Matrix
    int ergebnis_vektor[ANZAHL_ZEILEN]; // Ergebnisvektorlänge entspricht Zeilenzahl

    printf("Matrix-Vektor-Multiplikation\n");

    // Matrix und Vektor einlesen
    matrix_eingabe(ANZAHL_ZEILEN, ANZAHL_SPALTEN, eingabe_matrix);
    vektor_eingabe(ANZAHL_SPALTEN, eingabe_vektor);

    // Eingaben anzeigen (optional, zur Kontrolle)
    // Verwendet jetzt die Funktionen mit Zeigern
    matrix_ausgabe(ANZAHL_ZEILEN, ANZAHL_SPALTEN, eingabe_matrix);
    printf("\nEingegebener Vektor:\n");
    vektor_ausgabe(ANZAHL_SPALTEN, eingabe_vektor);

    // --- Berechnung: ergebnis_vektor = eingabe_matrix * eingabe_vektor ---
    // Ergebnisvektor initialisieren (wichtig!)
    for (int z = 0; z < ANZAHL_ZEILEN; ++z) {
        ergebnis_vektor[z] = 0;
    }

    // Multiplikation durchführen
    for (int z = 0; z < ANZAHL_ZEILEN; ++z) {
        for (int s = 0; s < ANZAHL_SPALTEN; ++s) {
            ergebnis_vektor[z] += eingabe_matrix[z][s] * eingabe_vektor[s];
        }
    }
    // --- Ende der Berechnung ---

    // Ergebnis anzeigen
    printf("\nErgebnisvektor:\n");
    // Verwendet jetzt die Funktion mit Zeiger
    vektor_ausgabe(ANZAHL_ZEILEN, ergebnis_vektor);

    return 0; // Programm erfolgreich beendet
}
