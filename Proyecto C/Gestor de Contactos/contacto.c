#include "contacto.h"

void limpiar_pantalla()
{
    printf("\033[2J");
    printf("\033[H");
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void liberarContacto(Contacto **c)
{
    if (c != NULL && *c != NULL)
    {
        free((*c)->nombre);
        free((*c)->email);
        free((*c)->telefono);
        free(*c);
        *c = NULL;
    }
}

char *crearCadena()
{
    char *Cadena = NULL;
    char buffer[MAX_CARACTERES];

    while (1)
    {
        printf(":");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            continue;
        }
        int len = strlen(buffer);
        if (len >= MAX_CARACTERES - 1 && buffer[len - 1] != '\n')
            limpiarBuffer();
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[--len] = '\0';

        if (len == 0)
        {
            fprintf(stderr, "No se ingresaron caracteres\n");
            continue;
        }

        if (buffer[0] == ' ')
        {
            fprintf(stderr, "La cadena no debe comenzar con un espacio\n");
            continue;
        }

        Cadena = (char *)malloc((len + 1) * sizeof(char));
        if (Cadena == NULL)
        {
            perror("Error al asignar memoria");
            exit(EXIT_FAILURE);
        }
        strcpy(Cadena, buffer);
        break;
    }

    return Cadena;
}

char *crearTelefono()
{
    char *telefono = NULL;
    int isValido = 0;

    while (!isValido)
    {
        isValido = 1;
        printf("Ingrese un telefono(10 digitos)");
        telefono = crearCadena();
        int len = strlen(telefono);

        if (len != 10)
        {
            printf("\nTamano invalido\n");
            free(telefono);
            isValido = 0;
            continue;
        }

        for (int i = 0; i < len; i++)
        {
            if (!isdigit(telefono[i]))
            {
                printf("\nDebe ser un numero de telefono (10 digitos)\n");
                free(telefono);
                isValido = 0;
                break;
            }
        }
    }

    return telefono;
}

char *crearEmail()
{
    char *email = NULL;
    while (1)
    {
        printf("Ingrese el email");
        email = crearCadena();
        if (strchr(email, '@') == NULL || strchr(email, '.') == NULL)
        {
            fprintf(stderr, "Error: email invalido\n");
            free(email);
            continue;
        }
        break;
    }
    return email;
}

Contacto *crearContacto()
{
    printf("Ingrese el nombre");
    char *nombre = crearCadena();

    char *email = crearEmail();

    char *telefono = crearTelefono();

    Contacto *nuevo_Contacto = (Contacto *)malloc(sizeof(Contacto));
    if (nuevo_Contacto == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el Contacto\n");
        exit(EXIT_FAILURE);
    }

    nuevo_Contacto->nombre = nombre;
    nuevo_Contacto->email = email;
    nuevo_Contacto->telefono = telefono;

    return nuevo_Contacto;
}

void mostrarContacto(Contacto *c)
{
    printf("Nombre: %s\n", c->nombre);
    printf("Email: %s\n", c->email);
    printf("Telefono: %s\n", c->telefono);
}