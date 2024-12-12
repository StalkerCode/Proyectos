#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const int MAX_palabraS = 100;


char *invertirOracion(char *palabras);
int main()
{
    char palabras[MAX_palabraS];
    printf("Programa para invertir la oracion\n");
    printf("Ingrese una oracion (max 100 caracter): ");
    fgets(palabras, MAX_palabraS, stdin);
    invertirOracion(palabras);
    //limpiarBuffer();
    //printf("La oracion invertida es: %s\n", invertirOracion(palabras));
    return 0;
}

void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char *invertirOracion(char *palabras)
{
    /*
    variable para el tamaño de palabra
    veriable de inicio y fin para invertir
    */
    
}