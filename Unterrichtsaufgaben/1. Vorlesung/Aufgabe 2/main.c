#include <stdio.h>

int main(){
    int i, t = 0;
    while (1){
        printf("Gib eine Zahl ein (0 zum Beenden): ");
        scanf("%i", &i);
        if (i == 0){
            break;
        }
        t = t + i;
    }
    printf("Das Ergebnis ist: %i", t);
    return 0;  
}
