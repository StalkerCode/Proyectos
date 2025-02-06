#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_palabraS 100

void espaciosIzquierdo(char *);
void espaciosDerecho(char *);
void eliminarEspacion(char *);

int contadorPalabra(char *);

int main()
{
    char *palabras = NULL;
    palabras = (char *)malloc(MAX_palabraS * sizeof(char));
    if (palabras == NULL)
    {
        printf("Error en la asignación de memoria\n");
        return 1;
    }
    printf("Ingrese una oracion: ");
    fgets(palabras, MAX_palabraS, stdin);
    printf("La oracion es: %s", palabras);
    eliminarEspacion(palabras);
    printf("El texto  es: %s\n", palabras);
    printf("La cantidad de palabra es: %i\n", contadorPalabra(palabras));
    free(palabras);
    palabras = NULL;

    return 0;
}
// función para eliminar los espacios en blanco al principio de la cadena de texto
void espaciosIzquierdo(char *palabras)
{
    int i, j;

    for (j=0; palabras[j] == ' '; j++)
        ;

    if (j > 0)
    {

        for (i = 0; palabras[i + j] != '\0'; i++)
        {
            palabras[i] = palabras[i + j];
        }
        palabras[i] = '\0';
    }
}

// función para eliminar los espacios en blanco  al final de la cadena de texto
void espaciosDerecho(char *palabras)
{
    int i;
    for (i = strlen(palabras); palabras[i - 1] == ' '; i--)
        ;

    palabras[i] = '\0';
}

// función para eliminar los espacios en blanco al principio y al final de la cadena de texto
void eliminarEspacion(char *palabras)
{
    palabras[strlen(palabras) - 1] = '\0';
    espaciosIzquierdo(palabras);
    espaciosDerecho(palabras);
}

// fincion para contar las palabra de la cadena de texto
int contadorPalabra(char *palabras)
{
    int contador = 0;
    int i = 0;

    if (palabras[i] == '\0')
    {
        return 0;
    }

    while (palabras[i] != '\0')
    {
        if (palabras[i + 1] != '\0' && palabras[i] != ' ' && palabras[i + 1] == ' ')
        {
            contador++;
        }
        i++;
    }
  
    return ++contador;
}
