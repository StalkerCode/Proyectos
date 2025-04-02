// tareas.h
#ifndef TAREAS_H
#define TAREAS_H

// Definición de las estructuras
typedef struct Tarea
{
    int id;
    char descripcion[100];
    int completada; // 0 = No, 1 = Sí
} Tarea;

typedef struct Nodo
{
    Tarea tarea;
    struct Nodo *siguiente;
} Nodo;

// Declaración de funciones
int crearId();
void reiniciarId();
int idMayor(Nodo *cabeza);
void limpiarBuffer();
void crearDescripcion(char *descripcion);
Tarea crearTarea();
Nodo *crearNodo();
void agregarTarea(Nodo **cabeza);
void listarTareas(Nodo *cabeza);
void completarTarea(Nodo *cabeza, int id);
void eliminarTarea(Nodo **cabeza, int id);
void vaciarLista(Nodo **cabeza);

#endif
