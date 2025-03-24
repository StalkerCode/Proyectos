// lista.c
#include "tareas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
hay que crear revisar id
mejorar crearTarea
integrarlo a crear nodo
integralo a agregarTarea
*/

void vaciarLista(Nodo **cabeza){
    Nodo *actual = *cabeza;
    Nodo *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
}

Tarea crearTarea()
{
    Tarea t1;
    printf("Ingrese el Id de la tarea: ");
    t1.id = crearEntero();
    limpiarBuffer();
    printf("Ingrese la descripcion de la tarea");
    crearDescripcion(t1.descripcion);
    t1.completada = 0;
    return t1;
}

int main()
{
    Nodo *listaCabeza = NULL;
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    listarTareas(listaCabeza);
    printf("\n");
    completarTarea(listaCabeza, 1);
    listarTareas(listaCabeza);
    printf("\n");
    eliminarTarea(&listaCabeza, 1);
    listarTareas(listaCabeza);
    printf("\n");
    eliminarTarea(&listaCabeza, 3);
    listarTareas(listaCabeza);
    return 0;
}