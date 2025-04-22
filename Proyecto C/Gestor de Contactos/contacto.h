#ifndef CONTACTO_H
#define CONTACTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARACTERES 50

typedef struct Contacto
{
    char *nombre;
    char *email;
    char *telefono;
} Contacto;

void limpiar_pantalla();
void limpiarBuffer();
void liberarContacto(Contacto **c);
char *crearCadena();
char *crearTelefono();
char *crearEmail();
Contacto *crearContacto();
void mostrarContacto(Contacto *c);

#endif