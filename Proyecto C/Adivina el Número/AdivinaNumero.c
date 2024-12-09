#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ctype.h"
#include "string.h"

//! falta valides de rango y de cercania
//! modificar el while validarEntradaInt para velodas de rango
/*int main()
{
    srand(time(NULL));
    int numero = (rand() % 100) + 1;
    int n = -1;
    printf("Adivine el numero entre 1 y 100\n");
    while (!(n == numero))
    {
        printf("ingrese el numero:");
        scanf("%d", &n);
        int diferencia = abs(n - numero);
        if (diferencia <= 4)
        {
            printf("Muy Muy Caliente\n");
        }
        else if (diferencia <= 8)
        {
            printf("Muy Caliente\n");
        }
        else if (diferencia <= 12)
        {
            printf("Caliente\n");
        }
        else if (diferencia <= 16)
        {
            printf("Tibio\n");
        }
        else if (diferencia <= 20)
        {
            printf("Frio\n");
        }
        else if (diferencia <= 24)
        {
            printf("Muy Frio\n");
        }
        else
        {
            printf("Extremo Muy Frio\n");
        }
    }

    return 0;
}
*/
void limpiarBuffer();
int esNumero(const char *);
int esNumeroValido(const char *);
int validarEntradaInt(char *);
int esValido(char *);
void cercania(int );

int main()
{
    char cadena[4]; // Espacio para 3 caracteres + terminador nulo

    // Generar un número aleatorio entre 1 y 100 y guardarlo en la variable 'numero'
    srand(time(NULL));
    int numero = (rand() % 100) + 1;
    printf("Adivine el numero entre 1 y 100\n");

    int n = esValido(cadena);
    int diferencia = abs(n - 100);
    while (diferencia != 0)
    {
        cercania(diferencia);
        n = esValido(cadena);
        diferencia = abs(n - 100);
    }
    printf("Adivinaste el numero: %d\n", numero);

    return 0;
}

void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int esNumero(const char *cadena)
{
    // Función para verificar si una cadena es numérica
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++)
    {
        if (!isdigit(cadena[i]))
        {
            return 0; // No es un número
        }
    }
    return 1; // Es un número
}

int esNumeroValido(const char *cadena)
{
    // Verificar que la cadena contenga solo números
    if (!esNumero(cadena))
    {
        printf("Error: La cadena debe contener solo numeros enteros.\n");
        return 0;
    }
    return 1;
}

int validarEntradaInt(char *cadena)
{
    // Solicitar al usuario ingresar una cadena
    printf("Ingrese un numero (1 a 3 digitos): ");
    scanf("%3s", cadena); // Limitar la entrada a 3 caracteres
    while (!esNumeroValido(cadena))
    {
        limpiarBuffer();
        printf("\nIngrese un numero (1 a 3 digitos): ");
        scanf("%3s", cadena);
    }
    // Convertir la cadena a un número entero
    return atoi(cadena);
}

int esValido(char *cadena)
{
    while (1)
    {
        int numero = validarEntradaInt(cadena);
        if (numero >= 1 && numero <= 100)
        {
            return numero;
        }
        else
        {
            printf("Error: El numero debe estar entre 1 y 100.\n");
            limpiarBuffer();
        }
    }
}

void cercania(int diferencia)
{
    // int diferencia = abs(numero - 100);
    if (diferencia <= 4)
        printf("Muy Muy Caliente.\n");
    else if (diferencia <= 8)
        printf("Caliente\n");
    else if (diferencia <= 12)
        printf("Tibio.\n");
    else if (diferencia <= 16)
        printf("normal.\n");
    else if (diferencia <= 20)
        printf("Frio\n");
    else if (diferencia <= 24)
        printf("Muy Frio\n");
    else
        printf("Extremo Muy Frio.\n");
}
