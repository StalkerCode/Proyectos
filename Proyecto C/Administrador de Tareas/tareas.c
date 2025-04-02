// tareas.c
#include "tareas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idGlobal = 0;

int crearId()
{
    return ++idGlobal;
}

void reiniciarId()
{
    idGlobal = 0;
}

int idMayor(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    int mayor = 0;
    while (actual != NULL)
    {
        if (actual->tarea.id > mayor)
        {
            mayor = actual->tarea.id;
        }
        actual = actual->siguiente;
    }
    return mayor;
}

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

Tarea crearTarea()
{
    Tarea t1;
    t1.id = crearId();
    printf("Ingrese la descripcion de la tarea");
    crearDescripcion(t1.descripcion);
    t1.completada = 0;
    return t1;
}

Nodo *crearNodo()
{
    Tarea t1 = crearTarea();
    Nodo *nuevaTarea = NULL;
    nuevaTarea = malloc(sizeof(Nodo));
    if (nuevaTarea == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(1);
    }
    nuevaTarea->tarea = t1;
    nuevaTarea->siguiente = NULL;
    return nuevaTarea;
}

void agregarTarea(Nodo **cabeza)
{
    Nodo *nodo = NULL;
    nodo = crearNodo();
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

void vaciarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    Nodo *siguiente;
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
}