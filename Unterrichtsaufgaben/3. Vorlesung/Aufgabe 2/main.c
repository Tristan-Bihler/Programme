#include <stdio.h>
#include <string.h>

int stringToLower(char *string){
    char comparator[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char einsetzen[28] =  "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i <= strlen(string); i++){
        for(int j = 0; j <= strlen(comparator); j++){
            if (strncmp(&(string[i]), &(comparator[j]), 1) == 0){
                string[i] = einsetzen[j];
            }
        }
    }
}

char ctringcomparediffrences(char *giveback, char *string, char *string2){
    printf("%i ", strlen(string));
    for(int i = 0; i <= strlen(string); i++){
        printf("%c ", string[i]);
        printf("%c\n", string2[i]);
        if (string[i] != string2[i]){
            strncat(giveback, &(string2[i]), 1);
        }
    }
}

int main(){
    char string[100];
    char string2[100];
    char giveback[100] = {""};
    scanf("%s", string);
    
    scanf("%s", string2);
    ctringcomparediffrences(giveback, string, string2);
    printf("%s\n", giveback);
    return 0;
}


