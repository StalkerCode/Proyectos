// lista.c
#include "tareas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcion para guardar el archivo en texto
void guardarTareas(Nodo *cabeza)
{
    if (cabeza == NULL)
    {
        fprintf(stderr, "Error: No hay tareas para guardar\n");
        return;
    }

    FILE *archivo = fopen("tareas.txt", "w");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", archivo);
        return;
    }

    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        fprintf(archivo, "%s %d\n", actual->tarea.descripcion, actual->tarea.completada);
        actual = actual->siguiente;
    }
    fclose(archivo);
}

// funcion para cargar las tares
//! arreglar las lista la esta regresando al reves las tareas
Nodo *cargarTareas()
{
    Nodo *cabeza = NULL;
    FILE *archivo = fopen("tareas.txt", "r");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo para leer\n");
        return NULL;
    }

    char descripcion[100];
    int completada;
    while (fscanf(archivo, "%s %d", descripcion, &completada) != EOF)
    {
        Nodo *nuevoNodo = malloc(sizeof(Nodo));
        if (nuevoNodo == NULL)
        {
            fprintf(stderr, "Error: No se pudo asignar memoria\n");
            fclose(archivo);
            exit(1);
        }

        Tarea nuevaTarea;
        nuevaTarea.id = crearId();
        strcpy(nuevaTarea.descripcion, descripcion);
        nuevaTarea.completada = completada;

        nuevoNodo->tarea = nuevaTarea;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }
    fclose(archivo);
    return cabeza;
}

int main()
{
    Nodo *listaCabeza = NULL;
    /*
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    listarTareas(listaCabeza);
    guardarTareas(listaCabeza);
    */
    listaCabeza = cargarTareas();
    listarTareas(listaCabeza);
    return 0;
}
