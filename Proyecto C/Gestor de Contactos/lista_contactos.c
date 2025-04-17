#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"
#include "lista_contactos.h"

// crear ListaContactos
ListaContactos *crearListaContactos()
{
    ListaContactos *nuevo = (ListaContactos *)malloc(sizeof(ListaContactos));
    if (nuevo == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para ListaContactos\n");
        exit(EXIT_FAILURE);
    }
    nuevo->contacto = crearContacto();
    nuevo->siguiente = NULL;
    return nuevo;
}

// insertar al principio
void insertarAlPrincipio(ListaContactos **cabeza)
{
    ListaContactos *nuevo = crearListaContactos();
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// insertar al final
void insertarAlFinal(ListaContactos **cabeza)
{
    ListaContactos *nuevo = crearListaContactos();
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
        return;
    }
    ListaContactos *actual = *cabeza;
    while (actual->siguiente != NULL)
        actual = actual->siguiente;
    actual->siguiente = nuevo;
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

// eliminar contacto por nombre
void eliminarContactoPorNombre(ListaContactos **cabeza, char *nombre)
{
    ListaContactos *actual = *cabeza, *anterior = NULL;
    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL)
    {
        printf("Contacto no encontrado.\n");
        return;
    }
    if (anterior == NULL)
        *cabeza = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;
    liberarContacto(&actual->contacto);
    free(actual);
}

// eliminar lista completa
void eliminarLista(ListaContactos **cabeza)
{
    ListaContactos *actual = *cabeza, *sig;
    while (actual != NULL)
    {
        sig = actual->siguiente;
        liberarContacto(&actual->contacto);
        free(actual);
        actual = sig;
    }
    *cabeza = NULL;
}

// buscar contacto por nombre
ListaContactos *buscarContactoPorNombreenLista(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *actual = cabeza;
    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
        actual = actual->siguiente;
    return actual;
}

// modificar contacto
void modificarContacto(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *encontrado = buscarContactoPorNombreenLista(cabeza, nombre);
    if (encontrado == NULL)
    {
        printf("Contacto no existe.\n");
        return;
    }
    printf("Ingrese los nuevos campos:\n");
    free(encontrado->contacto->telefono);
    encontrado->contacto->telefono = crearTelefono();
    free(encontrado->contacto->email);
    encontrado->contacto->email = crearEmail();
}

// buscar y mostrar contacto
void BuscarContactoPorNombre(ListaContactos *cabeza, const char *nombre)
{
    ListaContactos *encontrado = buscarContactoPorNombreenLista(cabeza, nombre);
    if (encontrado == NULL)
    {
        printf("Contacto no existe.\n");
        return;
    }
    mostrarContacto(encontrado->contacto);
}

// guardar contactos en archivo binario
int guardarContactosEnArchivo(ListaContactos *cabeza, const char *nombreArchivo)
{
    if (!cabeza || !nombreArchivo)
    {
        fprintf(stderr, "Parametros invalidos.\n");
        return 0;
    }
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (!archivo)
    {
        perror("Error al abrir archivo");
        return 0;
    }
    int guardados = 0;
    ListaContactos *actual = cabeza;
    while (actual)
    {
        int tam;
        // Nombre
        tam = strlen(actual->contacto->nombre);
        fwrite(&tam, sizeof(int), 1, archivo);
        fwrite(actual->contacto->nombre, sizeof(char), tam, archivo);
        // Email
        tam = strlen(actual->contacto->email);
        fwrite(&tam, sizeof(int), 1, archivo);
        fwrite(actual->contacto->email, sizeof(char), tam, archivo);
        // Teléfono
        tam = strlen(actual->contacto->telefono);
        fwrite(&tam, sizeof(int), 1, archivo);
        fwrite(actual->contacto->telefono, sizeof(char), tam, archivo);

        guardados++;
        actual = actual->siguiente;
    }
    fclose(archivo);
    printf("Se guardaron %d contactos.\n", guardados);
    return guardados;
}

// cargar contactos desde archivo binario
ListaContactos *cargarContactosDeArchivo(const char *nombreArchivo)
{
    if (!nombreArchivo)
    {
        fprintf(stderr, "Parámetro invalido.\n");
        return NULL;
    }
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (!archivo)
    {
        perror("Error al abrir archivo");
        return NULL;
    }
    ListaContactos *cabeza = NULL, *ultimo = NULL;
    while (1)
    {
        Contacto *nuevo = (Contacto *)malloc(sizeof(Contacto));
        if (!nuevo)
            break;

        int tam;

        if (fread(&tam, sizeof(int), 1, archivo) != 1)
        {
            free(nuevo);
            break;
        }
        nuevo->nombre = (char *)malloc(tam + 1);
        fread(nuevo->nombre, sizeof(char), tam, archivo);
        nuevo->nombre[tam] = '\0';

        fread(&tam, sizeof(int), 1, archivo);
        nuevo->email = (char *)malloc(tam + 1);
        fread(nuevo->email, sizeof(char), tam, archivo);
        nuevo->email[tam] = '\0';

        fread(&tam, sizeof(int), 1, archivo);
        nuevo->telefono = (char *)malloc(tam + 1);
        fread(nuevo->telefono, sizeof(char), tam, archivo);
        nuevo->telefono[tam] = '\0';

        ListaContactos *nuevoNodo = (ListaContactos *)malloc(sizeof(ListaContactos));
        nuevoNodo->contacto = nuevo;
        nuevoNodo->siguiente = NULL;

        if (!cabeza)
            cabeza = ultimo = nuevoNodo;
        else
        {
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }
    fclose(archivo);
    return cabeza;
}