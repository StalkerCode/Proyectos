// lista.c
#include "tareas.h"
#include "archivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{
    printf("1. Agregar tarea\n");
    printf("2. Listar tareas\n");
    printf("3. Completar tarea\n");
    printf("4. Eliminar tarea\n");
    printf("5. Vaciar lista\n");
    printf("6. Guardar tareas\n");
    printf("7. Cargar tareas\n");
}

int leerEntero()
{
    int numero;
    while (1)
    {
        printf("Ingrese un numero entero: ");

        // Intentar leer un número entero
        if (scanf("%d", &numero) != 1)
        {
            // Si scanf falla, imprimir un mensaje de error
            fprintf(stderr, "Error: La entrada no es un numero entero valido\n");
            // Limpiar el búfer de entrada
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    return numero;
}

int main()
{
    Nodo *listaCabeza = NULL;
    Nodo *listaCabeza2 = NULL;

    for (int i = 0; i < 10; i++)
    {
        int a = leerEntero();
        printf("el numero es %d\n", a);
    }
    

    return 0;
}
