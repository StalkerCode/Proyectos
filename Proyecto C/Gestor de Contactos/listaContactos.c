#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contacto.h"

// ListaContactos
typedef struct ListaContactos
{
    Contacto *contacto;
    struct ListaContactos *siguiente;
} ListaContactos;

// funciones

// crear ListaContactos
ListaContactos *crearListaContactos()
{
    ListaContactos *nuevo_ListaContactos = (ListaContactos *)malloc(sizeof(ListaContactos));
    if (nuevo_ListaContactos == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el ListaContactos\n");
        exit(EXIT_FAILURE);
    }
    nuevo_ListaContactos->contacto = crearContacto();
    nuevo_ListaContactos->siguiente = NULL;
    return nuevo_ListaContactos;
}

// insertar al principio
void insertarAlPrincipio(ListaContactos **cabeza)
{
    ListaContactos *nuevo_ListaContactos = crearListaContactos();
    nuevo_ListaContactos->siguiente = *cabeza;
    *cabeza = nuevo_ListaContactos;
}

// insertar al final
void insertarAlFinal(ListaContactos **cabeza)
{
    ListaContactos *nuevo_ListaContactos = crearListaContactos();
    ListaContactos *actual = *cabeza;

    if (*cabeza == NULL)
    {
        *cabeza = nuevo_ListaContactos;
        return;
    }

    while (actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo_ListaContactos;
}

// imprimir lista
void imprimirContactos(ListaContactos *cabeza)
{
    ListaContactos *actual = cabeza;

    while (actual != NULL)
    {
        printf("Nombre: %s\n", actual->contacto->nombre);
        printf("Email: %s\n", actual->contacto->email);
        printf("Telefono: %s\n", actual->contacto->telefono);
        printf("---------------------------------\n");

        actual = actual->siguiente;
    }
}

// eliminar ListaContactos por nombre
void eliminarContactoPorNombre(ListaContactos **cabeza, char *nombre)
{
    ListaContactos *actual = *cabeza;
    ListaContactos *anterior = NULL;

    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;
    if (anterior!=NULL)
    {
        anterior->siguiente = actual->siguiente;
    }
    liberarContacto(&actual->contacto);
    free(actual);
}

// eliminar lista
void eliminarLista(ListaContactos **cabeza)
{
    ListaContactos *actual = *cabeza;
    ListaContactos *siguiente;
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        liberarContacto(&actual->contacto); // Liberar memoria del contacto
        free(actual);                       // Liberar memoria del ListaContactos
        actual = siguiente;
    }
    *cabeza = NULL; // Actualizar la cabeza de la lista a NULL
}

// buscar ListaContactos por nombre
ListaContactos *buscarContactoPorNombreenLista(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *actual = cabeza;

    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        actual = actual->siguiente;
    }

    return actual;
}

// modificar contacto de la lista
void modificarContacto(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *ListaContactosBuscado = buscarContactoPorNombreenLista(cabeza, nombre);
    if (ListaContactosBuscado == NULL)
    {
        printf("Contacto no existe.\n");
        return;
    }
    printf("ingrese los nuevos campos\n");
    free(ListaContactosBuscado->contacto->telefono);
    ListaContactosBuscado->contacto->telefono = crearTelefono();
    free(ListaContactosBuscado->contacto->email);
    ListaContactosBuscado->contacto->email = crearEmail();
}

void BuscarContactoPorNombre(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *ListaContactosBuscado = buscarContactoPorNombreenLista(cabeza, nombre);
    if (ListaContactosBuscado == NULL)
    {
        printf("Contacto no existe.\n");
        return;
    }
    mostrarContacto(ListaContactosBuscado->contacto);
}

int guardarContactosEnArchivo(ListaContactos *cabeza, const char *nombreArchivo)
{
    if (cabeza == NULL || nombreArchivo == NULL)
    {
        fprintf(stderr, "Parámetros inválidos: cabeza o nombreArchivo es NULL\n");
        return 0;
    }

    FILE *archivo = fopen(nombreArchivo, "wb"); // Modo writte binario
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo para escritura");
        return 0;
    }

    int contactosGuardados = 0;
    ListaContactos *actual = cabeza;

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

ListaContactos *cargarContactosDeArchivo(const char *nombreArchivo)
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

    ListaContactos *cabeza = NULL;
    ListaContactos *ultimo = NULL;

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

        // Crear un nuevo ListaContactos
        ListaContactos *nuevoListaContactos = (ListaContactos *)malloc(sizeof(ListaContactos));
        if (nuevoListaContactos == NULL)
        {
            perror("Error al asignar memoria para el ListaContactos");
            liberarContacto(&nuevoContacto);
            break;
        }
        nuevoListaContactos->contacto = nuevoContacto;
        nuevoListaContactos->siguiente = NULL;
        // Agregar el ListaContactos a la lista
        if (cabeza == NULL)
        {
            cabeza = nuevoListaContactos;
            ultimo = nuevoListaContactos;
        }
        else
        {
            ultimo->siguiente = nuevoListaContactos;
            ultimo = nuevoListaContactos;
        }
    }

    fclose(archivo);
    return cabeza;
}

// prueba
/*
int main()
{
    ListaContactos *cabeza = NULL;
    insertarAlFinal(&cabeza);
    insertarAlFinal(&cabeza);
    insertarAlPrincipio(&cabeza);
    printf("\nse imrpime la lista de contactos\n");
    imprimirContactos(cabeza);
    printf("\nse elimina el contacto sapo\n");
    eliminarContactoPorNombre(&cabeza, "sapo");
    printf("\nse imrpime la lista de contactos\n");
    imprimirContactos(cabeza);
    printf("\nse modifica el contacto marlon\n");
    modificarContacto(cabeza, "marlon");
    printf("\nse imrpime la lista de contactos\n");
    imprimirContactos(cabeza);
    printf("\nse guardan los contactos en el archivo contactos.txt\n");
    guardarContactosEnArchivo(cabeza, "contactos.txt");
    printf("\nse cargan los contactos del archivo contactos.txt\n");
    ListaContactos *cabezaCargada = cargarContactosDeArchivo("contactos.txt");
    printf("\nse imrpime la lista de contactos cargados\n");
    imprimirContactos(cabezaCargada);
    eliminarLista(&cabeza);

    return 0;
}

*/
