#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_palabraS = 50;

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
        if (paso >= 1)
            free(contacto->nombre);
        if (paso >= 2)
            free(contacto->email);

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

// eliminar estructura

void eliminar_contacto(contacto *contacto)
{
    eliminar_Datos(contacto);
    free(contacto);
}

char *crearCadena()
{
    char *palabras = (char *)malloc(MAX_palabraS * sizeof(char));
    fgets(palabras, MAX_palabraS, stdin); //? se guarda el caracter de salto de linea
    palabras[strlen(palabras) - 1] = '\0';
    return palabras;
}

char *validarTelefono()
{

    char *telefono;
    int i = 0, isValido = 0;
    while (!isValido)
    {
        isValido = 1;
        printf("Ingrese un telefono(10 digitos): ");
        telefono = crearCadena();

        if (strlen(telefono) != 10)
        {
            printf("\nTamano invalido\n");
            free(telefono);
            isValido = 0;
            continue;
        }

        for (i = 0; i < strlen(telefono); i++)
        {
            if (!isdigit(telefono[i]))
            {
                printf("\ndebe ser un numero de telefono(10 digitos)\n");
                free(telefono);
                isValido = 0;
                break;
            }
        }
    }

    return telefono;
}

int main()
{
    free(validarTelefono());

    return 0;
}