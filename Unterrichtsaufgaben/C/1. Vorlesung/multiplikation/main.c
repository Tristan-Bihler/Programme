#include <stdio.h>

int main(){
    int j = 0;
    int i = 0;
    while (1){
        i ++;
        j = 0;
        while (1){
            j ++;
            
            printf("%i x %i = %i \n", i, j, i*j);
            if ( j >= 5){
                break;
            }
        }
        printf("\n");
        if ( i >= 5){
            break;
        }
    }
}