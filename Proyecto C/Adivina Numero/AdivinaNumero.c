#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ctype.h"
#include "string.h"


void limpiarBuffer();
int esNumero(const char *);
int esNumeroValido(const char *);
int validarEntradaInt(char *);
int esValido(char *);
void cercania(int );
void limpiar_pantalla();

int main()
{
    char cadena[4]; // Espacio para 3 caracteres + terminador nulo

    // Generar un número aleatorio entre 1 y 100 y guardarlo en la variable 'numero'
    srand(time(NULL));
    int numero = (rand() % 100) + 1;
    printf("Adivine el numero entre 1 y 100\n");

    int n = esValido(cadena);
    int diferencia = abs(n - numero);
    while (diferencia != 0)
    {
        cercania(diferencia);
        printf("\n");
        n = esValido(cadena);
        diferencia = abs(n - numero);
    }
    limpiar_pantalla();
    printf("\n\nAdivinaste el numero: %d\n\n", numero);

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
        printf("Error: La cadena debe contener un numeros enteros(1-100).\n");
        return 0;
    }
    return 1;
}

int validarEntradaInt(char *cadena)
{
    // Solicitar al usuario ingresar una cadena
    printf("Ingrese un numero (1 al 100): ");
    scanf("%3s", cadena); // Limitar la entrada a 3 caracteres
    while (!esNumeroValido(cadena))
    {
        limpiarBuffer();
        printf("\nIngrese un numero (1 al 100): ");
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
    if (diferencia <= 5)
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

void limpiar_pantalla()
{
    printf("\033[2J"); // Limpia la pantalla
    printf("\033[H");  // Mueve el cursor al inicio
}
