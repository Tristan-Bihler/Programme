#include <stdio.h>
#include <string.h>

int main(){
    char passwort[10] = "geheim";

    char eingabe[10] = "";
    
    int result;

    while (1){
        printf("Passwort : ");
        scanf("%s", eingabe);
        result = strcmp(passwort, eingabe);
        if (result == 0){
            break;
        }
        printf("Falsch, versuche es erneut: %i\n", result);
    }
    printf("Zugang gewährt");
} 