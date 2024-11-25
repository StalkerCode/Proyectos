#include "stdio.h"
#include "stdlib.h"
#include "time.h"


//! falta valides de rango
int main()
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


/*
! opcion 1
int esNumero(const char *cadena) {
    // Función para verificar si una cadena es numérica
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++) {
        if (!isdigit(cadena[i])) {
            return 0; // No es un número
        }
    }
    return 1; // Es un número
}

int main() {
    char cadena[4]; // Espacio para 3 caracteres + terminador nulo
    int numero;

    // Solicitar al usuario ingresar una cadena
    printf("Ingrese un número (1 a 3 dígitos): ");
    scanf("%3s", cadena);  // Limitar la entrada a 3 caracteres

    // Verificar que la longitud esté entre 1 y 3 caracteres
    int longitud = strlen(cadena);
    if (longitud < 1 || longitud > 3) {
        printf("Error: La cadena debe tener entre 1 y 3 caracteres.\n");
        return 1;
    }

    // Verificar que la cadena contenga solo números
    if (!esNumero(cadena)) {
        printf("Error: La cadena debe contener solo números.\n");
        return 1;
    }

    // Convertir la cadena a un número entero
    numero = atoi(cadena);

    // Imprimir el número entero resultante
    printf("El número entero es: %d\n", numero);

    return 0;
}
*/
/*
! opcion 2
int main() {
    char texto[4]; // Cadena de texto para almacenar máximo 3 caracteres + 1 para el caracter nulo
    int numero;

    printf("Ingrese una cadena de texto de 1 a 3 caracteres que represente un número entero: ");
    scanf("%3s", texto); // Leemos la cadena de texto con máximo 3 caracteres

    // Verificamos que la cadena de texto represente un número entero
    if (sscanf(texto, "%d", &numero) == 1) {
        printf("La cadena de texto '%s' representa el número entero %d.\n", texto, numero);
    } else {
        printf("Error: La cadena de texto '%s' no representa un número entero.\n", texto);
    }

    return 0;
}
*/
