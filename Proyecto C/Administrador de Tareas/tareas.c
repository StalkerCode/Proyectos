// tareas.c
#include "tareas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    // Limpia el buffer de entrada
}

void crearDescripcion(char *descripcion)
{
    char buffer[100];
    while (1)
    {
        printf(":");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            continue;
        }
        int len = 0;
        len = strlen(buffer);
        // limpia el buffer si hay mas de 49 caarcteres
        if (len >= 100 - 1 && buffer[len - 1] != '\n')
            limpiarBuffer();

        // Eliminar salto de línea si existe
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[--len] = '\0';

        // Verificar condiciones de validez
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

        strcpy(descripcion, buffer);
        break;
    }
}

int crearEntero()
{

    int entero;
    // Verifica si la entrada es un número entero válido
    while (1)
    {
        if (scanf("%d", &entero) != 1)
        {
            fprintf(stderr, "Error: Ingrese un numero entero valido\n");
            limpiarBuffer();
            printf(":");
            continue;
        }
        if (entero <= 0)
        {
            fprintf(stderr, "Error: El ID debe ser un número positivo\n");
            continue;
        }
        break;
    }
    return entero;
}



Nodo *crearNodo(Tarea *tarea)
{
    Nodo *nuevaTarea = NULL;
    nuevaTarea = malloc(sizeof(Nodo));
    if (nuevaTarea == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(1);
    }
    nuevaTarea->tarea = *tarea;
    nuevaTarea->siguiente = NULL;
    return nuevaTarea;
}

void agregarTarea(Nodo **cabeza, Tarea *tarea)
{
    Nodo *nodo = NULL;
    nodo = crearNodo(tarea);
    if (*cabeza == NULL)
    {
        *cabeza = nodo;
        return;
    }
    Nodo *actual = *cabeza;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nodo;
}

void listarTareas(Nodo *cabeza)
{
    if (cabeza == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }
    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        printf("Id: %d\n", actual->tarea.id);
        printf("Descripcion: %s\n", actual->tarea.descripcion);
        printf("Completada: %d\n", actual->tarea.completada);
        actual = actual->siguiente;
    }
}

void completarTarea(Nodo *cabeza, int id)
{
    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        if (actual->tarea.id == id)
        {
            actual->tarea.completada = 1;
            return;
        }
        actual = actual->siguiente;
    }
    printf("No se encontro la tarea con id %d\n", id);
}

void eliminarTarea(Nodo **cabeza, int id)
{
    if (*cabeza == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;
    while (actual != NULL)
    {
        if (actual->tarea.id == id)
        {
            if (anterior == NULL)
            {
                *cabeza = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("No se encontro la tarea con id %d\n", id);
}