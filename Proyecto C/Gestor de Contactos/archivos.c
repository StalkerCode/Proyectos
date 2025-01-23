#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contacto.c"

// funcion para crear un archivo
void crearArchivo(char *nombre)
{
    FILE *fp;
    fp = fopen(nombre, "w");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    fclose(fp);
}

// funcion para agregar un contacto al archivo con fwrite

void agregarContacto(char *nombre, Contacto *conta)
{
    FILE *fp;
    fp = fopen(nombre, "ab");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    fwrite(conta, sizeof(Contacto), 1, fp);
    fclose(fp);
}

// funcion para leer todos los contactos del archivo con fread

void leerTodosContactos(char *nombre)
{
    FILE *fp;
    Contacto contacto; 
    
    fp = fopen(nombre, "rb");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    printf("\n");

    // Leemos directamente en la estructura
    while (fread(&contacto, sizeof(Contacto), 1, fp) == 1)
    {
        printf("Nombre: %s\n", contacto.nombre);    
        printf("Email: %s\n", contacto.email);      
        printf("Telefono: %s\n", contacto.telefono);
        printf("---------------------------------\n");
    }
    
    fclose(fp);
}

// funcion para buscar un contacto por nombre

void buscarContacto(char *nombre)
{
    FILE *fp;
    Contacto *contacto;
    char nombreBuscado[100];
    int encontrado = 0;
    printf("Ingrese el nombre del contacto a buscar: ");
    scanf("%s", nombreBuscado);
    fp = fopen(nombre, "rb");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    while (fread(&contacto, sizeof(Contacto), 1, fp))
    {
        if (strcmp(contacto->nombre, nombreBuscado) == 0)
        {
            printf("Nombre: %s\n", contacto->nombre);
            printf("Email: %s\n", contacto->email);
            printf("Telefono: %s\n", contacto->telefono);
            printf("---------------------------------\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("No se encontro el contacto\n");
    }
    fclose(fp);
    free(contacto);
    contacto = NULL;

    // system("pause");
    // system("cls");
}

// funcion para reemplar un contacto por nombre

void reemplazarContacto(char *nombre)
{
    FILE *fp;
    Contacto *contacto;
    char nombreBuscado[100];
    char nombreNuevo[100];
    int encontrado = 0;
    printf("Ingrese el nombre del contacto a buscar: ");
    scanf("%s", nombreBuscado);
    printf("Ingrese el nombre nuevo para el contacto: ");
    scanf("%s", nombreNuevo);
    fp = fopen(nombre, "rb+");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    while (fread(&contacto, sizeof(Contacto), 1, fp))
    {
        if (strcmp(contacto->nombre, nombreBuscado) == 0)
        {
            strcpy(contacto->nombre, nombreNuevo);
            fwrite(contacto, sizeof(Contacto), 1, fp);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("No se encontro el contacto\n");
    }
    fclose(fp);
    free(contacto);
}

int main()
{
    char nombreArchivo[] = "contactos.dat";
    crearArchivo(nombreArchivo);
    Contacto *cont1 = crearContacto();
    Contacto *cont2 = crearContacto();
    //Contacto *cont3 = crearContacto();
    agregarContacto(nombreArchivo, cont1);
    agregarContacto(nombreArchivo, cont2);
    leerTodosContactos(nombreArchivo);
    eliminar_Contacto(cont1);
    eliminar_Contacto(cont2);
    //eliminar_Contacto(cont3);

    return 0;
}