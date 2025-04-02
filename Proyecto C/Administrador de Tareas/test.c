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
        fprintf(stderr, "Error al abrir el archivo para escribir\n");
        return;
    }

    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        fprintf(archivo, "%s\n%d\n", actual->tarea.descripcion, actual->tarea.completada);
        actual = actual->siguiente;
    }
    fclose(archivo);
}

// funcion para cargar las tares
Nodo *cargarTareas()
{
    Nodo *cabeza = NULL;
    Nodo *actual = NULL;
    FILE *archivo = fopen("tareas.txt", "r");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo para leer\n");
        return NULL;
    }
    reiniciarId();
    char descripcion[100];
    int completada;
    while (fgets(descripcion, sizeof(descripcion), archivo))
    {
        // Eliminar el salto de línea al final de la descripción
        descripcion[strcspn(descripcion, "\n")] = 0;

        if (fscanf(archivo, "%d", &completada) == 1)
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
            nuevoNodo->siguiente = NULL;

            if (cabeza == NULL)
            {
                cabeza = nuevoNodo;
                actual = nuevoNodo;
            }
            else
            {
                actual->siguiente = nuevoNodo;
                actual = nuevoNodo;
            }

            // Leer el salto de línea restante después del estado
            fgetc(archivo);
        }
    }
    fclose(archivo);
    return cabeza;
}

int main()
{
    Nodo *listaCabeza = NULL;
    Nodo *listaCabeza2 = NULL;

    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);

    printf("\nLista a guardar\n");
    listarTareas(listaCabeza);
    guardarTareas(listaCabeza);

    printf("\nLista cargada\n");
    listaCabeza2 = cargarTareas();
    listarTareas(listaCabeza2);
    return 0;
}
