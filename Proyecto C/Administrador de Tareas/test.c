// lista.c
#include "tareas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
falta las funciones desde el archivo
funcion nombre de archivo y se agrega .dat
guardar listas en texto
caragar lista desde el archvio


*/

int main()
{
    Nodo *listaCabeza = NULL;
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    listarTareas(listaCabeza);
    vaciarLista(&listaCabeza);
    listarTareas(listaCabeza);
    return 0;
}