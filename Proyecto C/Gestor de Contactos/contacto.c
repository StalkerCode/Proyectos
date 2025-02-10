

const int MAX_Caracteres = 50;

typedef struct Contacto
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
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// eliminar datos de estructura
void liberarContacto(Contacto **c)
{
    if (c != NULL && *c != NULL)
    {
        free((*c)->nombre);
        free((*c)->email);
        free((*c)->telefono);
        free(*c);
        *c = NULL; // Evita uso después de liberar
    }
}

// crea una cadena de texto
char *crearCadena()
{
    char *Cadena = NULL;
    char buffer[MAX_Caracteres];

    while (1)
    {
        printf(":");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            continue;
        }
        int len;
        len = strlen(buffer);

        // Eliminar salto de línea si existe
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[--len] = '\0';

        // Verificar condiciones de validez
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

        Cadena = (char *)malloc(len * sizeof(char) + 1);
        if (Cadena == NULL)
        {
            perror("Error al asignar memoria");
            exit(EXIT_FAILURE); // Terminar el programa si no hay memoria
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
        int len;
        len = strlen(telefono);

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
    char *email = NULL;
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
    char *nombre = NULL;
    nombre = crearCadena();

    // se crea el email
    char *email = NULL;
    email = crearEmail();

    // se crea el telefono
    char *telefono = NULL;
    telefono = crearTelefono();

    Contacto *nuevo_Contacto = NULL;
    nuevo_Contacto = (Contacto *)malloc(sizeof(Contacto));
    if (nuevo_Contacto == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el Contacto\n");
        exit(EXIT_FAILURE);
    }
    nuevo_Contacto->nombre = NULL;
    nuevo_Contacto->email = NULL;
    nuevo_Contacto->telefono = NULL;
    // se inicializan los datos del contacto
    nuevo_Contacto->nombre = nombre;
    nuevo_Contacto->email = email;
    nuevo_Contacto->telefono = telefono;
    return nuevo_Contacto;
}

/*
int main()
{
    Contacto *mi_Contacto = NULL;
    mi_Contacto = crearContacto();
    printf("\nNombre: %s\n", mi_Contacto->nombre);
    printf("Email: %s\n", mi_Contacto->email);
    printf("Telefono: %s\n", mi_Contacto->telefono);
    liberarContacto(&mi_Contacto);

    return 0;
}
*/