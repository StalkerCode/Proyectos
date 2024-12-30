#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contacto.c"

// nodo
typedef struct Nodo
{
    Contacto *contacto;
    int guardado;
    struct Nodo *siguiente;
} Nodo;

// funciones

// crear nodo
Nodo *crearNodo()
{
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevo_nodo->contacto = crearContacto();
    nuevo_nodo->guardado = 0;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

// insertar al principio
void insertarAlPrincipio(Nodo **cabeza)
{
    Nodo *nuevo_nodo = crearNodo();
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

// insertar al final

void insertarAlFinal(Nodo **cabeza)
{
    Nodo *nuevo_nodo = crearNodo();
    Nodo *actual = *cabeza;

    if (*cabeza == NULL)
    {
        *cabeza = nuevo_nodo;
        return;
    }

    while (actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo_nodo;
}

// imprimir lista

void imprimirContactos(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    while (actual != NULL)
    {

        printf("Nombre: %s\n", actual->contacto->nombre);
        printf("Email: %s\n", actual->contacto->email);
        printf("Telefono: %s\n", actual->contacto->telefono);
        printf("---------------------------------\n");

        actual = actual->siguiente;
    }
}
//eliminar nodo por nombre

void eliminarContactoPorNombre(Nodo **cabeza, char *nombre)
{
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;

    if (strcmp(actual->contacto->nombre, nombre) == 0)
    {
        *cabeza = actual->siguiente;
        eliminar_Contacto(actual->contacto);
        free(actual);
        return;
    }

    while (actual!= NULL && strcmp(actual->contacto->nombre, nombre)!= 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    anterior->siguiente = actual->siguiente;
    eliminar_Contacto(actual->contacto);
    free(actual);
}



int main()
{
    Nodo *cabeza = NULL;
    insertarAlPrincipio(&cabeza);  // Agregamos & para pasar la dirección
    insertarAlPrincipio(&cabeza);
    insertarAlFinal(&cabeza);
    eliminarContactoPorNombre(&cabeza,"1");
    imprimirContactos(cabeza);     // Esto está bien así
    return 0;
}