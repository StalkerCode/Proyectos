#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contacto.c"

// nodo
typedef struct Nodo
{
    Contacto *contacto;
    struct Nodo *siguiente;
} Nodo;

// funciones

// crear nodo
Nodo *crearNodo()
{
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevo_nodo->contacto = crearContacto();
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

// insertar al principio
void insertarAlPrincipio(Nodo **cabeza)
{
    Nodo *nuevo_nodo = crearNodo();
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

// insertar al final
void insertarAlFinal(Nodo **cabeza)
{
    Nodo *nuevo_nodo = crearNodo();
    Nodo *actual = *cabeza;

    if (*cabeza == NULL)
    {
        *cabeza = nuevo_nodo;
        return;
    }

    while (actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo_nodo;
}

// imprimir lista
void imprimirContactos(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    while (actual != NULL)
    {
        printf("Nombre: %s\n", actual->contacto->nombre);
        printf("Email: %s\n", actual->contacto->email);
        printf("Telefono: %s\n", actual->contacto->telefono);
        printf("---------------------------------\n");

        actual = actual->siguiente;
    }
}

// eliminar nodo por nombre
void eliminarContactoPorNombre(Nodo **cabeza, char *nombre)
{
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;

    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    anterior->siguiente = actual->siguiente;
    liberarContacto(&actual->contacto);
    free(actual);
}

// eliminar lista
void eliminarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    Nodo *siguiente;
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        liberarContacto(&actual->contacto); // Liberar memoria del contacto
        free(actual);                       // Liberar memoria del nodo
        actual = siguiente;
    }
    *cabeza = NULL; // Actualizar la cabeza de la lista a NULL
}

// buscar nodo por nombre
Nodo *buscarContactoPorNombre(Nodo *cabeza, const char *nombre)
{
    Nodo *actual = cabeza;

    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        actual = actual->siguiente;
    }

    return actual;
}

// modificar contacto de la lista
void modificarContacto(Nodo *cabeza, const char *nombre)
{
    Nodo *nodoBuscado = buscarContactoPorNombre(cabeza, nombre);
    if (nodoBuscado == NULL)
    {
        printf("Contacto no existe.\n");
        return;
    }
    printf("ingrese los nuevos campos\n");
    free(nodoBuscado->contacto->telefono);
    nodoBuscado->contacto->telefono = crearTelefono();
    free(nodoBuscado->contacto->email);
    nodoBuscado->contacto->email = crearEmail();
}

int guardarContactosEnArchivo(Nodo *cabeza, const char *nombreArchivo)
{
    if (cabeza == NULL || nombreArchivo == NULL)
    {
        fprintf(stderr, "Parámetros inválidos: cabeza o nombreArchivo es NULL\n");
        return 0;
    }

    FILE *archivo = fopen(nombreArchivo, "ab"); // Modo append binario
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo para escritura");
        return 0;
    }

    int contactosGuardados = 0;
    Nodo *actual = cabeza;

    while (actual != NULL)
    {

        // Escribe las cadenas con terminador '\0'
        fwrite(actual->contacto->nombre, sizeof(char), strlen(actual->contacto->nombre) + 1, archivo);
        fwrite(actual->contacto->email, sizeof(char), strlen(actual->contacto->email) + 1, archivo);
        fwrite(actual->contacto->telefono, sizeof(char), strlen(actual->contacto->telefono) + 1, archivo);

        contactosGuardados++;

        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Se guardaron %d nuevos contactos en el archivo\n", contactosGuardados);
    return contactosGuardados;
}
char *leerCadenaDelArchivo(FILE *archivo)
{
    if (archivo == NULL)
    {
        return NULL;
    }

    char buffer[51]; // Espacio para 50 caracteres + '\0'
    size_t longitud = 0;
    char caracter;

    while (longitud < 50 && fread(&caracter, sizeof(char), 1, archivo) == 1)
    {
        buffer[longitud++] = caracter;

        // Terminar si encontramos el terminador '\0'
        if (caracter == '\0')
        {
            break;
        }
    }

    // Si no se leyó ningún carácter, devolver NULL
    if (longitud == 0)
    {
        return NULL;
    }

    // Crear cadena exacta en memoria dinámica
    char *cadena = (char *)malloc(longitud * sizeof(char));
    if (cadena == NULL)
    {
        perror("Error al asignar memoria para la cadena");
        return NULL;
    }

    memcpy(cadena, buffer, longitud); // Copiar los datos del buffer
    return cadena;
}

Nodo *cargarContactosDeArchivo(const char *nombreArchivo)
{
    if (nombreArchivo == NULL)
    {
        fprintf(stderr, "Parámetro inválido: nombreArchivo es NULL\n");
        return NULL;
    }
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo para lectura\n");
        return NULL;
    }

    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;

    while (!feof(archivo))
    {
        // Crear un nuevo contacto
        Contacto *nuevoContacto = (Contacto *)malloc(sizeof(Contacto));
        if (nuevoContacto == NULL)
        {
            perror("Error al asignar memoria para el contacto");
            break;
        }

        // Leer nombre
        nuevoContacto->nombre = leerCadenaDelArchivo(archivo);
        if (nuevoContacto->nombre == NULL)
        {
            free(nuevoContacto);
            break;
        }

        // Leer email
        nuevoContacto->email = leerCadenaDelArchivo(archivo);
        if (nuevoContacto->email == NULL)
        {
            free(nuevoContacto->nombre);
            free(nuevoContacto);
            break;
        }

        // Leer teléfono
        nuevoContacto->telefono = leerCadenaDelArchivo(archivo);
        if (nuevoContacto->telefono == NULL)
        {
            free(nuevoContacto->nombre);
            free(nuevoContacto->email);
            free(nuevoContacto);
            break;
        }

        // Crear un nuevo nodo
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevoNodo == NULL)
        {
            perror("Error al asignar memoria para el nodo");
            liberarContacto(&nuevoContacto);
            break;
        }
        nuevoNodo->contacto = nuevoContacto;
        nuevoNodo->siguiente = NULL;
        // Agregar el nodo a la lista
        if (cabeza == NULL)
        {
            cabeza = nuevoNodo;
            ultimo = nuevoNodo;
        }
        else
        {
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }

    fclose(archivo);
    return cabeza;
}

// prueba
int main()
{
    Nodo *cabeza = NULL;
    insertarAlFinal(&cabeza);
    imprimirContactos(cabeza);
    modificarContacto(cabeza, "marlon");
    imprimirContactos(cabeza);
    eliminarLista(&cabeza);

    return 0;
}