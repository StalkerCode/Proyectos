// tareas.h
#ifndef TAREAS_H
#define TAREAS_H

// Definición completa de las estructuras
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

// Declaraciones de funciones
void limpiarBuffer();
void crearDescripcion(char *);
int crearEntero();
Nodo *crearNodo(Tarea *);
void agregarTarea(Nodo **, Tarea *);
void listarTareas(Nodo *);
void completarTarea(Nodo *, int);
void eliminarTarea(Nodo **, int);

#endif
