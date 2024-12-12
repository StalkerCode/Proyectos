#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const int MAX_palabraS = 100;

char *invertirOracion(char *);
int main()
{
    char palabras[MAX_palabraS];
    printf("Programa para invertir la oracion\n");
    printf("Ingrese una oracion (max 100 caracter): ");
    fgets(palabras, MAX_palabraS, stdin);//? se guarda el caracter de salto de linea
    printf("\nLa oracion invertida es: %s\n", invertirOracion(palabras));
    printf("\nFin del programa");
    return 0;
}


char *invertirOracion(char *palabras)
{
    /*
    variable para el tamaño de palabra
    veriable de inicio y fin para invertir
    */
    //?se excluye el caracter de fin de linea \0
    int tamano = strlen(palabras)-1;
    int inicio = 0;
    int fin = tamano - 1;//?se excluye el caracter de salto de linea \n
    char *palabraInversa = (char *)malloc(tamano*sizeof(char));

    // mientras  fin mayor o igual a cero
    while (fin >= 0)
    {
        palabraInversa[inicio] = palabras[fin];
        inicio++;
        fin--;
    }
    // agregar el caracter de fin de linea al final de la palabra inversa
    palabraInversa[tamano] = '\0';
    return palabraInversa;
}