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

void eliminar_Datos(contacto *contacto)
{
    free(contacto->nombre);
    free(contacto->email);
    free(contacto->telefono);
}


void esExitoso(contacto *contacto, char *str, int paso)
{
    if (str == NULL)
    {
        fprintf(stderr, "Error: no se pudo duplicar la cadena\n");
        
        // Liberar los campos ya asignados hasta el momento
        if (paso >= 1) free(contacto->nombre);
        if (paso >= 2) free(contacto->email);
        
        exit(EXIT_FAILURE);
    }
}

// crear estructura

contacto *crear_contacto(char *nombre, char *email, char *telefono)
{
    contacto *nuevo_contacto = malloc(sizeof(contacto));
    if (nuevo_contacto == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el contacto\n");
        exit(EXIT_FAILURE);
    }

    nuevo_contacto->nombre = strdup(nombre);
    esExitoso(nuevo_contacto, nuevo_contacto->nombre, 1);

    nuevo_contacto->email = strdup(email);
    esExitoso(nuevo_contacto, nuevo_contacto->email, 2);

    nuevo_contacto->telefono = strdup(telefono);
    esExitoso(nuevo_contacto, nuevo_contacto->telefono, 3);

    return nuevo_contacto;
}

int main()
{
    contacto *mi_contacto = crear_contacto("Juan", "juan@example.com", "1234567890");
    
    // Imprimir contacto
    printf("Nombre: %s\nEmail: %s\nTelefono: %s\n", mi_contacto->nombre, mi_contacto->email, mi_contacto->telefono);
    
    // Liberar contacto
    eliminar_Datos(mi_contacto);
    free(mi_contacto);

    return 0;
}