#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* capasidad maxima para la lectura*/
const int MAX_BUFFER = 100;
const int MAX_BUFFER_AUX = 100;
const int MAX_ANALISIS = 3;

char *crearCadena();
char *compresorCadena(char *);
void comprecion(char *);

int main()
{
    char *nombreArchivo = NULL;
    nombreArchivo = crearCadena();
    comprecion(nombreArchivo);
    free(nombreArchivo);
    return 0;
}
/*
el bufer de un maximo de 100 caracteres
*/

char *crearCadena()
{
    char *Cadena = NULL;
    const int tm = 50;
    char buffer[tm];

    while (1)
    {
        printf("ingrese el nombre del archivo( max 50 caracteres) que:");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            continue;
        }
        int len = 0;
        len = strlen(buffer);

        if (len > 0 && buffer[len - 1] == '\n')
            buffer[--len] = '\0';

        if (len == 0)
        {
            fprintf(stderr, "No se ingresaron caracteres\n");
            continue;
        }

        if (buffer[0] == ' ')
        {
            fprintf(stderr, "La cadena no debe comenzar con un espacio\n");
            continue;
        }

        Cadena = (char *)malloc((len + 1) * sizeof(char));
        if (Cadena == NULL)
        {
            perror("Error al asignar memoria");
            exit(EXIT_FAILURE); // Terminar el programa si no hay memoria
        }
        strcpy(Cadena, buffer);
        break;
    }

    return Cadena;
}
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

void comprecion(char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    char *nombreComprimido = NULL;
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    printf("Ingrese el nombre del archivo comprimido\n");
    printf("Ejemplo: archivo.txt\n");
    nombreComprimido = crearCadena();
    if (nombreComprimido == NULL)
    {
        printf("Error al crear el nombre del archivo comprimido\n");
        return;
    }
    FILE *archivo2 = fopen(nombreComprimido, "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    char linea[MAX_BUFFER_AUX];
    while (fgets(linea, sizeof(linea), archivo))
    {
        char *comprimida = compresorCadena(linea);
        fputs(comprimida, archivo2);
        free(comprimida);
    }
    free(nombreComprimido);
    fclose(archivo);
    fclose(archivo2);
}