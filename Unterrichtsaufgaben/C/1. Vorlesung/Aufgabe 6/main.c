#include <stdio.h>

int main(){
    float i, j = 0;
    printf("Gib die erste Zahl an: ");
    scanf("%f", &i);
    printf("Gib die zweite Zahl an: ");
    scanf("%f", &j);

    printf("Das Ergebnis ist: %.2f", i + j);
}