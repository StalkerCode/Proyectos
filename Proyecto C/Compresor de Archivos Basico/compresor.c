#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_BUFFER = 100;
const int MAX_BUFFER_AUX = 100;
const int MAX_ANALISIS = 3;

/*
el compresor de cadena tiene que funcionar con memoria dinamica
el bufer de un maximo de 100 caracteres
*/

char *compresorCadena(char *cadena)
{
    int contador = 1;
    char *comprimida = NULL;
    char buffer[MAX_BUFFER_AUX];
    char aux[MAX_ANALISIS];
    int i = 0;
    buffer[0] = '\0';

    while (cadena[i] != '\0')
    {
        if (cadena[i] == cadena[i + 1])
        {
            contador++;
            i++;
            continue;
        }
        else if (contador > 1)
        {
            sprintf(aux, "%d%c", contador, cadena[i]);
            strcat(buffer, aux);
            contador = 1;
        }
        else
        {
            sprintf(aux, "%c", cadena[i]);
            strcat(buffer, aux);
        }
        i++;
    }
    printf("\nCadena buffer: %s\n", buffer);
    int longitudTotal = strlen(buffer) + 1;
    comprimida = (char *)malloc(longitudTotal * sizeof(char));
    if (comprimida == NULL)
    {
        printf("Error al asignar memoria\n");
        return NULL;
    }

    strcpy(comprimida, buffer);
    return comprimida;
}

void leerArchivo(char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    char linea[MAX_BUFFER_AUX];
    while (fgets(linea, sizeof(linea), archivo))
    {
        char *comprimida = compresorCadena(linea);
        printf("Cadena comprimida: %s\n", comprimida);
        free(comprimida);
    }
    fclose(archivo);
}

int main()
{
    leerArchivo("sapo.txt");

    return 0;
}