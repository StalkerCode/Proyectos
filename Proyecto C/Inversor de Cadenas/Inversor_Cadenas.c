#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const int MAX_CARACTERES = 100;

void invertirOracion(char *);
int main()
{
    char palabras[MAX_CARACTERES];
    printf("Programa para invertir la oracion\n");
    printf("Ingrese una oracion (max 100 caracter): ");
    fgets(palabras, MAX_CARACTERES, stdin); //? se guarda el caracter de salto de linea
    invertirOracion(palabras);
    printf("\nLa oracion invertida es: %s\n",palabras);
    printf("\nFin del programa");
    return 0;
}

void invertirOracion(char *palabras)
{
    /*
    variable para el tamaño de palabra
    veriable de inicio y fin para invertir
    */
    palabras[strlen(palabras) - 1] = '\0';
    //?se excluye el caracter de fin de linea \0
    int tamano = strlen(palabras) - 1;
    int inicio = 0;
    int fin = tamano; //?se excluye el caracter de salto de linea \n
    char aux;
    int au=fin/2;
    // mientras  fin mayor o igual a cero
    while (fin > au)
    {
        // intercambiar caracteres de inicio y fin
        aux = palabras[inicio];
        palabras[inicio] = palabras[fin];
        palabras[fin] = aux;
        // avanzar en la palabra
        inicio++;
        fin--;
    }
    // agregar el caracter de fin de linea al final de la palabra inversa
    palabras[tamano+1] = '\0';
}