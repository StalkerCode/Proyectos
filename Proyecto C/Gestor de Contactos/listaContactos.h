#include "contacto.h"
#include "listaContactos.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

ListaContactos *crearListaContactos();
void insertarAlPrincipio(ListaContactos **cabeza);
void insertarAlFinal(ListaContactos **cabeza);
void imprimirContactos(ListaContactos *cabeza);
void eliminarContactoPorNombre(ListaContactos **cabeza, char *nombre);
void eliminarLista(ListaContactos **cabeza);
ListaContactos *buscarContactoPorNombre(ListaContactos *cabeza, const char *nombre);
void modificarContacto(ListaContactos *cabeza, const char *nombre);
int guardarContactosEnArchivo(ListaContactos *cabeza, const char *nombreArchivo);
char *leerCadenaDelArchivo(FILE *archivo);
ListaContactos *cargarContactosDeArchivo(const char *nombreArchivo);
