#include <stdio.h>
#include "listaContactos.c"

void menu();
int ingresarEntero();

int main()
{
    
    ingresarEntero();

    return 0;
}
void menu()
{
    printf("\n1. Insertar contacto al principio");
    printf("\n2. Insertar contacto al final");
    printf("\n3. Buscar contacto por nombre");
    printf("\n4. Modificar contacto por nombre");
    printf("\n5. Eliminar contacto por nombre");
    printf("\n6. Imprimir lista de contactos");
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

void opciones(int op,ListaContactos **cabeza)
{
    
}