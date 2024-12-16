#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *nombre;
    char *email;
    char *telefono;
} contacto;

// eliminar estructura

void eliminar_contacto(contacto *contacto)
{
    free(contacto->nombre);
    free(contacto->email);
    free(contacto->telefono);
    free(contacto);
}

void esExitoso(contacto *contacto, char *str)
{
    if (str == NULL)
    {
        fprintf(stderr, "Error: no se pudo duplicar el nombre\n");
        eliminar_contacto(contacto);
        exit(EXIT_FAILURE);
    }
}

// crear estructura

contacto crear_contacto(char *nombre, char *email, char *telefono)
{
    contacto nuevo_contacto;
    nuevo_contacto.nombre = strdup(nombre);
    esExitoso(&nuevo_contacto, nuevo_contacto.nombre);

    nuevo_contacto.email = strdup(email);
    esExitoso(&nuevo_contacto, nuevo_contacto.email);

    nuevo_contacto.telefono = strdup(telefono);
    esExitoso(&nuevo_contacto, nuevo_contacto.telefono);
    
    return nuevo_contacto;
}

int main()
{
    contacto mi_contacto = crear_contacto("Juan", "juan@example.com", "1234567890");
    // imprimir contacto
    printf("Nombre: %s\nEmail: %s\nTelefono: %s\n", mi_contacto.nombre, mi_contacto.email, mi_contacto.telefono);
    eliminar_contacto(&mi_contacto);
    return 0;
}