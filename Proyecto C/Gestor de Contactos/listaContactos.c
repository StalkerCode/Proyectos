#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contacto.c"

// nodo
typedef struct Nodo
{
    Contacto *contacto;
    int guardado;
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
    nuevo_nodo->guardado = 0;
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

    if (strcmp(actual->contacto->nombre, nombre) == 0)
    {
        *cabeza = actual->siguiente;
        eliminar_Contacto(actual->contacto);
        free(actual);
        return;
    }

    while (actual != NULL && strcmp(actual->contacto->nombre, nombre) != 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    anterior->siguiente = actual->siguiente;
    eliminar_Contacto(actual->contacto);
    free(actual);
}

int guardarContactosEnArchivo(Nodo *cabeza, const char *nombreArchivo)
{
    if (cabeza == NULL || nombreArchivo == NULL)
    {
        fprintf(stderr, "Parámetros inválidos: cabeza o nombreArchivo es NULL\n");
        return 0;
    }

    FILE *archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo para escritura");
        return 0;
    }

    int contactosGuardados = 0;
    Nodo *actual = cabeza;

    while (actual != NULL)
    {
        if (actual->guardado == 0)
        { // Solo guardar contactos no guardados
            size_t longNombre = strlen(actual->contacto->nombre) + 1;
            size_t longEmail = strlen(actual->contacto->email) + 1;
            size_t longTelefono = strlen(actual->contacto->telefono) + 1;

            // Escribir las longitudes
            if (
                fwrite(&longNombre, sizeof(size_t), 1, archivo) != 1 ||
                fwrite(&longEmail, sizeof(size_t), 1, archivo) != 1 ||
                fwrite(&longTelefono, sizeof(size_t), 1, archivo) != 1)
            {
                perror("Error al escribir las longitudes en el archivo");
                fclose(archivo);
                return contactosGuardados;
            }

            // Escribir los datos del contacto
            if (
                fwrite(actual->contacto->nombre, sizeof(char), longNombre, archivo) != longNombre ||
                fwrite(actual->contacto->email, sizeof(char), longEmail, archivo) != longEmail ||
                fwrite(actual->contacto->telefono, sizeof(char), longTelefono, archivo) != longTelefono)
            {
                perror("Error al escribir los datos del contacto en el archivo");
                fclose(archivo);
                return contactosGuardados;
            }

            actual->guardado = 1; // Marcar contacto como guardado
            contactosGuardados++;
        }
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Se guardaron %d nuevos contactos en el archivo\n", contactosGuardados);
    return contactosGuardados;
}

Nodo *cargarContactosDeArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo para lectura\n");
        return NULL;
    }

    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;

    size_t longNombre, longEmail, longTelefono;
    while (fread(&longNombre, sizeof(size_t), 1, archivo) == 1 &&
           fread(&longEmail, sizeof(size_t), 1, archivo) == 1 &&
           fread(&longTelefono, sizeof(size_t), 1, archivo) == 1)
    {

        // Crear y validar el nuevo contacto
        Contacto *nuevoContacto = (Contacto *)malloc(sizeof(Contacto));
        if (nuevoContacto == NULL)
        {
            fprintf(stderr, "Error al asignar memoria para el contacto\n");
            fclose(archivo);
            return NULL;
        }

        nuevoContacto->nombre = (char *)malloc(longNombre);
        nuevoContacto->email = (char *)malloc(longEmail);
        nuevoContacto->telefono = (char *)malloc(longTelefono);

        if (nuevoContacto->nombre == NULL || nuevoContacto->email == NULL || nuevoContacto->telefono == NULL)
        {
            fprintf(stderr, "Error al asignar memoria para las cadenas del contacto\n");
            eliminar_Contacto(nuevoContacto);
            fclose(archivo);
            return NULL;
        }

        // Leer los datos del contacto
        if (fread(nuevoContacto->nombre, sizeof(char), longNombre, archivo) != longNombre ||
            fread(nuevoContacto->email, sizeof(char), longEmail, archivo) != longEmail ||
            fread(nuevoContacto->telefono, sizeof(char), longTelefono, archivo) != longTelefono)
        {
            fprintf(stderr, "Error al leer los datos del contacto\n");
            eliminar_Contacto(nuevoContacto);
            break;
        }

        // Crear el nodo y agregarlo a la lista
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevoNodo == NULL)
        {
            fprintf(stderr, "Error al asignar memoria para el nodo\n");
            eliminar_Contacto(nuevoContacto);

            fclose(archivo);
            return NULL;
        }

        nuevoNodo->contacto = nuevoContacto;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->guardado = 1;

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
    /*insertarAlFinal(&cabeza);
    insertarAlFinal(&cabeza);
    insertarAlFinal(&cabeza);
    imprimirContactos(cabeza);
    guardarContactosEnArchivo(cabeza, "contactos.dat");*/
    cabeza = cargarContactosDeArchivo("contactos.dat");
    imprimirContactos(cabeza);
    return 0;
}