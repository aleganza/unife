// verifica se una frase è palindroma

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxStr 30

int checkPal(char str[maxStr]) {
    int len = strlen(str);

    for(int i=0; i<len/2-1; i++){
        if(str[i] != str[len-1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[maxStr];

    printf("Inserisci una parola: ");
    scanf("%s", str);
    
    if(checkPal(str))
        printf("La parola %s e' palindroma", str);
    else
        printf("La parola %s NON e' palindroma", str);

    return 0;
}