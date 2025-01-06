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

int guardarContactosEnArchivo(Nodo *cabeza, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "ab");  // Abrir archivo en modo append binario
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura\n");
        return 0;
    }

    int contactosGuardados = 0;
    Nodo *actual = cabeza;
    
    while (actual != NULL) {
        // Solo guardamos si el contacto no ha sido guardado previamente
        if (actual->guardado == 0) {
            // Guardamos las longitudes de las cadenas
            size_t longNombre = strlen(actual->contacto->nombre) + 1;
            size_t longEmail = strlen(actual->contacto->email) + 1;
            size_t longTelefono = strlen(actual->contacto->telefono) + 1;

            // Escribimos las longitudes
            fwrite(&longNombre, sizeof(size_t), 1, archivo);
            fwrite(&longEmail, sizeof(size_t), 1, archivo);
            fwrite(&longTelefono, sizeof(size_t), 1, archivo);

            // Escribimos los datos del contacto
            fwrite(actual->contacto->nombre, sizeof(char), longNombre, archivo);
            fwrite(actual->contacto->email, sizeof(char), longEmail, archivo);
            fwrite(actual->contacto->telefono, sizeof(char), longTelefono, archivo);

            // Marcamos el contacto como guardado
            actual->guardado = 1;
            contactosGuardados++;
        }
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Se guardaron %d nuevos contactos en el archivo\n", contactosGuardados);
    return contactosGuardados;
}

Nodo* cargarContactosDeArchivo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura\n");
        return NULL;
    }

    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;

    while (!feof(archivo)) {
        size_t longNombre, longEmail, longTelefono;

        // Leemos las longitudes
        if (fread(&longNombre, sizeof(size_t), 1, archivo) != 1) break;
        if (fread(&longEmail, sizeof(size_t), 1, archivo) != 1) break;
        if (fread(&longTelefono, sizeof(size_t), 1, archivo) != 1) break;

        // Creamos un nuevo contacto
        Contacto *nuevoContacto = (Contacto*)malloc(sizeof(Contacto));
        
        // Asignamos memoria para las cadenas
        nuevoContacto->nombre = (char*)malloc(longNombre);
        nuevoContacto->email = (char*)malloc(longEmail);
        nuevoContacto->telefono = (char*)malloc(longTelefono);

        // Leemos los datos del contacto
        fread(nuevoContacto->nombre, sizeof(char), longNombre, archivo);
        fread(nuevoContacto->email, sizeof(char), longEmail, archivo);
        fread(nuevoContacto->telefono, sizeof(char), longTelefono, archivo);

        // Creamos un nuevo nodo
        Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
        nuevoNodo->contacto = nuevoContacto;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->guardado = 1;  // Lo marcamos como guardado

        // Agregamos el nodo a la lista
        if (cabeza == NULL) {
            cabeza = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }

    fclose(archivo);
    return cabeza;
}

//prueba
int main() {
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