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
} Contacto;

// limpia la pantalla
void limpiar_pantalla()
{
    printf("\033[2J"); // Limpia la pantalla
    printf("\033[H");  // Mueve el cursor al inicio
}

// libera el buffer
void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// eliminar datos de estructura
void eliminar_Datos(Contacto *contacto)
{
    free(contacto->nombre);
    free(contacto->email);
    free(contacto->telefono);
}

// eliminar estructura
void eliminar_Contacto(Contacto *contacto)
{
    eliminar_Datos(contacto);
    free(contacto);
}

// crea una cadena de texto
char *crearCadena()
{
    char *Cadena;
    int len;

    while (1)
    {
        Cadena = (char *)malloc(MAX_palabraS * sizeof(char));
        if (Cadena == NULL)
        {
            perror("Error al asignar memoria");
            exit(EXIT_FAILURE); // Terminar el programa si no hay memoria
        }

        printf(":");
        if (fgets(Cadena, MAX_palabraS, stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            free(Cadena); // Liberar la memoria original antes de continuar
            continue;
        }

        len = strlen(Cadena);

        // Eliminar salto de línea si existe
        if (len > 0 && Cadena[len - 1] == '\n')
            Cadena[--len] = '\0';

        // Verificar condiciones de validez
        if (len == 0)
        {
            fprintf(stderr, "No se ingresaron caracteres\n");
            free(Cadena); // Liberar la memoria original antes de continuar
            continue;
        }

        if (Cadena[0] == ' ')
        {
            fprintf(stderr, "La cadena no debe comenzar con un espacio\n");
            free(Cadena); // Liberar la memoria original antes de continuar
            continue;
        }

        // Redimensionar la cadena al tamaño exacto
        char *temp = realloc(Cadena, (len + 1) * sizeof(char));
        if (temp == NULL)
        {
            perror("Error al redimensionar la memoria");
            free(Cadena); // Liberar la memoria original si `realloc` falla
            continue;
        }

        Cadena = temp;
        break;
    }

    return Cadena;
}

char *crearTelefono()
{

    char *telefono;
    int i = 0, isValido = 0;
    int len;
    while (!isValido)
    {
        isValido = 1;
        printf("Ingrese un telefono(10 digitos)");
        telefono = crearCadena();
        len = strlen(telefono);

        if (len != 10)
        {
            printf("\nTamano invalido\n");
            free(telefono);
            isValido = 0;
            continue;
        }

        for (i = 0; i < len; i++)
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

char *crearEmail()
{
    char *email;
    while (1)
    {
        printf("Ingrese el email");
        email = crearCadena();
        if (strchr(email, '@') == NULL || strchr(email, '.') == NULL)
        {
            fprintf(stderr, "Error: email inválido\n");
            free(email);
            continue;
        }
        break;
    }
    return email;
}

Contacto *crearContacto()
{
    // se crea el nombre
    printf("Ingrese el nombre");
    char *nombre = crearCadena();

    // se crea el email
    char *email = crearEmail();

    // se crea el telefono
    char *telefono = crearTelefono();

    Contacto *nuevo_Contacto = malloc(sizeof(Contacto));
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
/*
int main()
{
    Contacto *mi_Contacto = crearContacto();
    printf("\nNombre: %s\n", mi_Contacto->nombre);
    printf("Email: %s\n", mi_Contacto->email);
    printf("Telefono: %s\n", mi_Contacto->telefono);
    eliminar_Contacto(mi_Contacto); // Asegura la liberación correcta de memoria
    return 0;
}
*/