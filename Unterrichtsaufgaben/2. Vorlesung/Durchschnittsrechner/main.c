#include <stdio.h>

int main(){
    int noten[23];
    int eingabe = 0;
    int durchschnit = 0;
    for(int i = 0; i <= 23; i++){
        scanf("%i", &eingabe);
        noten[i] = eingabe;
    }
    for(int i = 0; i <= 23; i++){
        durchschnit = durchschnit + noten[i];
    }

    printf("%i\n", durchschnit);
    printf("%i", durchschnit / 24);
    
}