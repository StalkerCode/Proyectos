#include <stdio.h>
#include <string.h>

void compresorCadena(char *cadena, char *comprimida)
{
    int contador = 1;
    long tamano = strlen(cadena);
    char buffer[tamano];
    int j = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (cadena[i] == cadena[i + 1])
        {
            contador++;
            continue;
        }
        else if (contador > 1)
        {
            sprintf(buffer, "%d%c", contador, cadena[i]);
            strcat(comprimida, buffer);
            contador = 1;
            j++;
        }
        else
        {
            sprintf(buffer, "%c", cadena[i]);
            strcat(comprimida, buffer);
            j++;
        }
    }
}
/*
el compresor de cadena tiene que funcionar con memoria dinamica
el bufer de un maximo de 100 caracteres
*/

int main()
{
    char cadena[]= "AAAABBBCC";
    char comprimida[100] = "";
    compresorCadena(cadena, comprimida);
    printf("Cadena original: %s\n", cadena);
    printf("Cadena comprimida: %s\n", comprimida);

    return 0;
}