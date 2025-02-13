#include "contacto.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void limpiar_pantalla();
void limpiarBuffer();
void liberarContacto(Contacto **c);
char *crearCadena();
char *crearTelefono();
char *crearEmail();
Contacto *crearContacto();
