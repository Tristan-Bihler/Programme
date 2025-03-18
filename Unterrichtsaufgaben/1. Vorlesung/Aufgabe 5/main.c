#include <stdio.h>

int main(){
    int i, j, h, k = 0;
    printf("Gib die Breite ein: ");
    scanf("%i", &i);
    printf("Gib die Breite ein: ");
    scanf("%i", &j);

    while(1){
        h ++;
        k = 0;
        while(1){
            k ++;
            printf("*");
            if(k == j){
                break;
            }
        }
        printf("\n");
        if(h == i){
            break;
        }
    }
}