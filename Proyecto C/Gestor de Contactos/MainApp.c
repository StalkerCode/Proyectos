#include <stdio.h>
#include "listaContactos.c"

void menu();
int ingresarEntero();
void opciones(int op, ListaContactos **cabeza);

int main()
{
    ListaContactos *cabeza = NULL;
    opciones(1, &cabeza);
    opciones(2, &cabeza);
    opciones(2, &cabeza);
    printf("\nse imrpime la lista de contactos\n");
    opciones(6, &cabeza);
    printf("\nse elimina el contacto sapo\n");
    opciones(5, &cabeza);
    printf("\nse imrpime la lista de contactos\n");
    opciones(6, &cabeza);
    printf("\nse modifica el contacto\n");
    opciones(4, &cabeza);
    printf("\nse imrpime la lista de contactos\n");
    opciones(6, &cabeza);
    printf("\nse busca en la lista de contactos\n");
    opciones(3, &cabeza);
    eliminarLista(&cabeza);
    return 0;
}
void menu()
{
    printf("\n1. Insertar contacto al principio"); //?
    printf("\n2. Insertar contacto al final");     //?
    printf("\n3. Buscar contacto por nombre");     //?
    printf("\n4. Modificar contacto por nombre");  //?
    printf("\n5. Eliminar contacto por nombre");   //?
    printf("\n6. Imprimir lista de contactos");    //?
    printf("\n7. eliminar lista de contactos");
    printf("\n8. Guardar lista de contactos");
    printf("\n9. Cargar lista de contactos");
    printf("\n0. Salir");
    printf("\n\nSeleccione una opción ");
}

int ingresarEntero()
{
    char *numero = NULL;
    int isValido = 0;

    while (!isValido)
    {
        isValido = 1;
        numero = crearCadena();
        int len;
        len = strlen(numero);
        if (len > 1)
        {
            printf("\nopcion invalida, debe ser un digito");
            isValido = 0;
            free(numero);
            continue;
        }
        if (!isdigit(numero[0]))
        {
            printf("\ndebe ser un numero\n");
            free(numero);
            isValido = 0;
            continue;
        }
    }
    return atoi(numero);
}

void opciones(int op, ListaContactos **cabeza)
{
    char *nombre = NULL;
    switch (op)
    {
    case 1:
        insertarAlPrincipio(cabeza);
        break;
    case 2:
        insertarAlFinal(cabeza);
        break;
    case 3:
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        BuscarContactoPorNombre(*cabeza, nombre); 
        break;
    case 4:
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        modificarContacto(*cabeza, nombre);
        break;
    case 5:
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        eliminarContactoPorNombre(cabeza, nombre);
        break;
    case 6:
        imprimirContactos(*cabeza);
        break;
    case 7:
        eliminarLista(&(*cabeza));
        break;
    case 8:
        printf("\ningrese el nombre del archivo a guardar",
               "\ndebe tener maximo 50 caracteres y terminar con .txt o .dat");
        nombre = crearCadena();
        guardarContactosEnArchivo(*cabeza, nombre);
        break;
    case 9:
        printf("\ningrese el nombre del archivo a cargar",
               "\ndebe tener maximo 50 caracteres y terminar con .txt o .dat");
        *cabeza = cargarContactosDeArchivo(nombre);
        break;
    case 0:
    }
    free(nombre);
}
