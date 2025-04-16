// lista.c
#include "tareas.h"
#include "archivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int leerID();
char leerDigito();
void menu();


int main()
{
    printf("Bienvenido al Administrador de Tareas\n");

    char op;
    int isRunning = 1;
    int ID;
    Nodo *LISTA_DE_TAREAS = NULL;
    while (isRunning)
    {
        menu();
        op = leerDigito();
        switch (op)
        {
        case '0':
            printf("\nHasta luego\n");
            isRunning = 0;
            break;

        case '1':
            printf("\nAgregar tarea\n");
            agregarTarea(&LISTA_DE_TAREAS);
            printf("\n");
            break;

        case '2':
            printf("\nListar tareas\n");
            listarTareas(LISTA_DE_TAREAS);
            printf("\n");
            break;

        case '3':
            printf("\nCompletar tarea\n");
            ID = leerID();
            completarTarea(LISTA_DE_TAREAS, ID);
            printf("\n");
            break;

        case '4':
            printf("\nEliminar tarea\n");
            ID = leerID();
            eliminarTarea(&LISTA_DE_TAREAS, ID);
            printf("\n");
            break;

        case '5':
            printf("\nVaciar lista\n");
            vaciarLista(&LISTA_DE_TAREAS);
            printf("\n");
            break;

        case '6':
            printf("\nGuardar tareas\n");
            guardarTareas(LISTA_DE_TAREAS);
            printf("\n");
            break;

        case '7':

            printf("\nCargar tareas\n");
            vaciarLista(&LISTA_DE_TAREAS);
            LISTA_DE_TAREAS = cargarTareas();
            printf("\n");
            break;

        default:
            printf("\nElecion erronea\n");
            printf("\n");
        }
    }
    vaciarLista(&LISTA_DE_TAREAS);
    LISTA_DE_TAREAS = NULL;
    printf("\nFin del programa\n");
    return 0;
}

void menu()
{
    printf("Menu\n");
    printf("1. Agregar tarea\n");
    printf("2. Listar tareas\n");
    printf("3. Completar tarea\n");
    printf("4. Eliminar tarea\n");
    printf("5. Vaciar lista\n");
    printf("6. Guardar tareas\n");
    printf("7. Cargar tareas\n");
    printf("0. salir\n");
}

// Función para leer un dígito y descartar cualquier entrada adicional
char leerDigito()
{
    char c;
    while (1)
    {
        printf("Ingrese una opcion: ");
        scanf(" %c", &c);
        // Verificar si el carácter es un dígito
        if (isdigit(c))
        {
            limpiarBuffer();
            return c; // Convertir el carácter a su valor entero correspondiente
        }
        else
        {
            limpiarBuffer();
            continue; // Si no es un dígito, continuar leyendo
        }
    }
}

int leerID()
{
    char c[3]; // Arreglo para almacenar dos caracteres y el terminador nulo
    while (1)
    {
        printf("Ingrese un numero (1 a 99): ");
        // Leer hasta dos caracteres
        if (scanf("%2s", c) == 1)
        {
            // Verificar si todos los caracteres son dígitos
            short int isDigi = 1;
            for (size_t i = 0; c[i] != '\0'; i++)
            {
                if (!isdigit(c[i]))
                {
                    isDigi = 0;
                    break;
                }
            }

            if (isDigi)
            {
                return atoi(c);
            }
        }
        // Limpiar el buffer solo si la entrada no es válida
        limpiarBuffer();
    }
}
