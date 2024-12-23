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

void limpiar_pantalla()
{
    printf("\033[2J"); // Limpia la pantalla
    printf("\033[H");  // Mueve el cursor al inicio
}

void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
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
        {
            fprintf(stderr, "Error: no se pudo asignar memoria %i\n",paso);
            free(contacto->nombre);
            return;
        }

        if (paso >= 2)
        {
            fprintf(stderr, "Error: no se pudo asignar memoria %i\n",paso);
            free(contacto->email);
            esExitoso(contacto, contacto->nombre, 1);
        }
        if (paso >= 3)
        {
            fprintf(stderr, "Error: no se pudo asignar memoria %i\n",paso);
            free(contacto->telefono);
            esExitoso(contacto, contacto->email, 2);
        }
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
    if (palabras == NULL)
    {
        perror("Error al asignar memoria");
        return NULL;
    }

    if (fgets(palabras, MAX_palabraS, stdin) == NULL)
    {
        free(palabras);
        return NULL;
    }

    // Eliminar el salto de línea si existe
    int len = strlen(palabras);
    if (len > 0 && palabras[len - 1] == '\n')
    {
        palabras[len - 1] = '\0';
        len--; // Ajustar la longitud real
    }

    // Reservar memoria para la nueva cadena
    char *Cadena = (char *)malloc((len + 1) * sizeof(char)); // +1 para '\0'
    if (Cadena == NULL)
    {
        perror("Error al asignar memoria");
        free(palabras);
        return NULL;
    }

    // Copiar la cadena, incluyendo el carácter nulo
    strncpy(Cadena, palabras, len);
    Cadena[len] = '\0'; // Asegurar el carácter nulo

    free(palabras);
    return Cadena;
}

char *telefonoValido()
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

contacto *contactoConDatos()
{
    printf("Ingrese el nombre: ");
    char *nombre = crearCadena();
    if (nombre == NULL)
    {
        fprintf(stderr, "Error al crear el nombre.\n");
        return NULL;
    }

    printf("Ingrese el email: ");
    char *email = crearCadena();
    if (email == NULL)
    {
        fprintf(stderr, "Error al crear el email.\n");
        free(nombre);
        return NULL;
    }

    char *telefono = telefonoValido();
    if (telefono == NULL)
    {
        fprintf(stderr, "Error al crear el telefono.\n");
        free(nombre);
        free(email);
        return NULL;
    }

    return crear_contacto(nombre, email, telefono);
}
