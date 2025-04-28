#include <stdio.h>

int main() {

    int i = 0;
    while(i < 10){
        i = i + 1;
        printf("%i \n", i);
    }

    for(int i = 1; i < 11; i++){
        printf("%i\n", i);
    }

    i = 0;
    do{
        i++;
        printf("%i\n", i);
    }
    while(i < 10);

    if(1) printf("1 ist wahr\n");

    return 0;
}