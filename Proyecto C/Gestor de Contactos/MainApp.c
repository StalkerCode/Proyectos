#include <stdio.h>
#include "listaContactos.c"

void menu();
int ingresarEntero();
void opciones(int op, ListaContactos **cabeza);
void app();
void pausa();
int listaVacia(ListaContactos **cabeza);

int main()
{
    app();
    printf("\nFin del programa");
    return 0;
}
void menu()
{
    printf("\n1. Insertar contacto al principio");
    printf("\n2. Insertar contacto al final");
    printf("\n3. Buscar contacto por nombre");
    printf("\n4. Modificar contacto por nombre");
    printf("\n5. Eliminar contacto por nombre"); //! problema al ejecutar al primero
    printf("\n6. Imprimir lista de contactos");
    printf("\n7. eliminar lista de contactos");
    printf("\n8. Guardar lista de contactos");
    printf("\n9. Cargar lista de contactos (esta acion reemplaza la lista actual)");
    printf("\n0. Salir");
    printf("\n\nSeleccione una opcion ");
}

int ingresarEntero()
{
    char *numero = NULL;
    int num = 0;
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
    num = atoi(numero);
    free(numero);
    return num;
}
int listaVacia(ListaContactos **cabeza)
{
    if (*cabeza == NULL)
    {
        printf("la lista esta vacia");
        return 1;
    }
    return 0;
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
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        BuscarContactoPorNombre(*cabeza, nombre);
        break;
    case 4:
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        modificarContacto(*cabeza, nombre);
        break;
    case 5:
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        printf("\ningrese el nombre del contacto");
        nombre = crearCadena();
        eliminarContactoPorNombre(cabeza, nombre);
        break;
    case 6:
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        imprimirContactos(*cabeza);
        break;
    case 7:
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        eliminarLista(&(*cabeza));
        break;
    case 8:
        if (*cabeza == NULL)
        {
            printf("la lista esta vacia");
            break;
        }
        printf("\ningrese el nombre del archivo a guardar",
               "\ndebe tener maximo 50 caracteres y terminar con .txt o .dat");
        nombre = crearCadena();
        guardarContactosEnArchivo(*cabeza, nombre);
        break;
    case 9:
        eliminarLista(&(*cabeza));
        printf("\ningrese el nombre del archivo a cargar",
               "\ndebe tener maximo 50 caracteres y terminar con .txt o .dat");
        nombre = crearCadena();
        *cabeza = cargarContactosDeArchivo(nombre);
        break;
    case 0:
        printf("\nHasta luego");
        break;
    default:
        printf("\nOpcion invalida");
        break;
    }
    if (nombre != NULL)
    {
        free(nombre);
    }
}
void app()
{
    ListaContactos *cabeza = NULL;
    int op = -1;
    while (op != 0)
    {
        menu();
        op = ingresarEntero();
        opciones(op, &cabeza);
        pausa();
        limpiar_pantalla();
    }
    if (cabeza != NULL)
    {
        eliminarLista(&cabeza);
        cabeza = NULL;
    }
}

void pausa()
{
    printf("\nprecione enter para continuar\n");
    limpiarBuffer();
}
