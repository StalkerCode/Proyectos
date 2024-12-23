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
void eliminar_Datos(contacto *contacto)
{
    free(contacto->nombre);
    free(contacto->email);
    free(contacto->telefono);
}

// eliminar estructura
void eliminar_contacto(contacto *contacto)
{
    eliminar_Datos(contacto);
    free(contacto);
}

// crea una cadena de texto
char *crearCadena()
{
    char *palabras;
    char *Cadena;
    int len;

    while (1)
    {
        printf(":");
        palabras = (char *)malloc(MAX_palabraS * sizeof(char));
        if (palabras == NULL)
        {
            perror("Error al asignar memoria");
            free(palabras);
            continue;
        }

        if (fgets(palabras, MAX_palabraS, stdin) == NULL)
        {
            fprintf(stderr, "Error alingresar lso caracteres\n");
            free(palabras);
            continue;
        }

        len = strlen(palabras);
        // Eliminar el salto de línea
        palabras[--len] = '\0';

        // verifica que haya caracteres
        if (len == 0)
        {
            fprintf(stderr, "No ingreso caracter\n");
            free(palabras);
            continue;
        }
        // verifica que no comieze o haiga solo un espacio
        if (palabras[0] == ' ')
        {
            fprintf(stderr, "Ingrese una que no comiense con espacio\n");
            free(palabras);
            continue;
        }

        // Reservar memoria para la nueva cadena
        Cadena = (char *)malloc((len) * sizeof(char));
        if (Cadena == NULL)
        {
            perror("Error al asignar memoria");
            free(Cadena);
            continue;
        }

        // Copiar la cadena, incluyendo el carácter nulo
        strncpy(Cadena, palabras, len);

        // verifica que si se copio la cadena
        if (Cadena == NULL)
        {
            fprintf(stderr, "Error al copia la cadeda\n");
            free(Cadena);
            free(palabras);
            continue;
        }

        Cadena[len] = '\0'; // Asegurar el carácter nulo
        free(palabras);
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

contacto *crearContacto()
{
    // se crea el nombre
    printf("Ingrese el nombre");
    char *nombre = crearCadena();

    // se crea el email
    printf("Ingrese el email");
    char *email = crearCadena();
    
    // se crea el telefono
    char *telefono = crearTelefono();
    
    contacto *nuevo_contacto = malloc(sizeof(contacto));
    if (nuevo_contacto == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el contacto\n");
        exit(EXIT_FAILURE);
    }
    nuevo_contacto->nombre=nombre;
    nuevo_contacto->email=email;
    nuevo_contacto->telefono=telefono;
    return nuevo_contacto;
}


int main()
{
    contacto *contacto=crearContacto();
    printf("\nnombre:%s\n",contacto->nombre);
    printf("Email:%s\n",contacto->email);
    printf("Telefono:%s\n",contacto->telefono);
    free(contacto);
    return 0;
}