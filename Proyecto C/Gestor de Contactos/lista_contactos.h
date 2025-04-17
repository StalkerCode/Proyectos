#ifndef LISTA_CONTACTOS_H
#define LISTA_CONTACTOS_H

#include "contacto.h"

// Definición de la estructura de nodo de lista
typedef struct ListaContactos
{
    Contacto *contacto;
    struct ListaContactos *siguiente;
} ListaContactos;

// Prototipos de funciones
ListaContactos *crearListaContactos();
void insertarAlPrincipio(ListaContactos **cabeza);
void insertarAlFinal(ListaContactos **cabeza);
void imprimirContactos(ListaContactos *cabeza);
void eliminarContactoPorNombre(ListaContactos **cabeza, char *nombre);
void eliminarLista(ListaContactos **cabeza);
ListaContactos *buscarContactoPorNombreenLista(ListaContactos *cabeza, const char *nombre);
void modificarContacto(ListaContactos *cabeza, const char *nombre);
void BuscarContactoPorNombre(ListaContactos *cabeza, const char *nombre);
int guardarContactosEnArchivo(ListaContactos *cabeza, const char *nombreArchivo);
ListaContactos *cargarContactosDeArchivo(const char *nombreArchivo);

#endif