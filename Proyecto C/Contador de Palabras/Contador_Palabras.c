#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_WORDS 100

void espaciosIzquierdo(char *);
void espaciosDerecho(char *);

int main()
{
    char *palabra = (char *)malloc(MAX_WORDS * sizeof(char));
    if (palabra == NULL)
    {
        printf("Error en la asignación de memoria\n");
        return 1;
    }
    printf("Ingrese una oracion: ");
    fgets(palabra, MAX_WORDS, stdin);
    printf("La oracion es: %s", palabra);
    espaciosIzquierdo(palabra);
    espaciosDerecho(palabra);
    free(palabra);

    return 0;
}

void espaciosIzquierdo(char *word) {
    int i, j = 0;
    
    for (j; word[j] == ' '; j++);
    
    if (j > 0) {
        
        for (i = 0; word[i + j] != '\0'; i++) {
            word[i] = word[i + j];
        }
        word[i] = '\0';  
    }
    
    printf("La palabra es: %s\n", word);
}

void espaciosDerecho(char *word){
    int i= strlen(word);
    
    for (i; word[i] == ' '; i--);

    word[i + 1] = '\0';
    printf("La palabra es: %s\n", word);
    
}