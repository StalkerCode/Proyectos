#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea
{
    int id;
    char descripcion[100];
    int completada; // 0 = No, 1 = Sí
} Tarea;

typedef struct ListaTareas
{
    Tarea tarea;
    struct ListaTareas *siguiente;
} ListaTareas;

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    // Limpia el buffer de entrada
}

void crearDescripcion(char *descripcion)
{
    char buffer[100];
    while (1)
    {
        printf(":");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Error al ingresar caracteres\n");
            continue;
        }
        int len = 0;
        len = strlen(buffer);
        // limpia el buffer si hay mas de 49 caarcteres
        if (len >= 100 - 1 && buffer[len - 1] != '\n')
            limpiarBuffer();

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

        strcpy(descripcion, buffer);
        break;
    }
}

int crearEntero()
{

    int entero;
    // Verifica si la entrada es un número entero válido
    while (1)
    {
        if (scanf("%d", &entero) != 1)
        {
            fprintf(stderr, "Error: Ingrese un número entero válido\n");
            limpiarBuffer();
            printf(":");
            continue;
        }
        break;
    }
    return entero;
}

Tarea creraTarea()
{
    Tarea t1;
    printf("Ingrese el Id de la tarea: ");
    t1.id = crearEntero();
    limpiarBuffer();
    printf("Ingrese la descripcion de la tarea");
    crearDescripcion(t1.descripcion);
    t1.completada = 0;
    return t1;
}

ListaTareas *crearNodo()
{
    ListaTareas *nuevaTarea = NULL;
    nuevaTarea = malloc(sizeof(ListaTareas));
    nuevaTarea->tarea = creraTarea();
    nuevaTarea->siguiente = NULL;
    return nuevaTarea;
}

void agregarTarea(ListaTareas **cabeza)
{
    ListaTareas *nodo = NULL;
    nodo = crearNodo();
    if (*cabeza == NULL)
    {
        *cabeza = nodo;
        return;
    }
    ListaTareas *actual = *cabeza;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nodo;
}

void listarTareas(ListaTareas *cabeza)
{
    if (cabeza == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }
    ListaTareas *actual = cabeza;
    while (actual != NULL)
    {
        printf("Id: %d\n", actual->tarea.id);
        printf("Descripcion: %s\n", actual->tarea.descripcion);
        printf("Completada: %d\n", actual->tarea.completada);
        actual = actual->siguiente;
    }
}

void completarTarea(ListaTareas *cabeza, int id)
{
    ListaTareas *actual = cabeza;
    while (actual != NULL)
    {
        if (actual->tarea.id == id)
        {
            actual->tarea.completada = 1;
            return;
        }
        actual = actual->siguiente;
    }
    printf("No se encontro la tarea con id %d\n", id);
}

void eliminarTarea(ListaTareas **cabeza, int id)
{
    if (*cabeza == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }
    ListaTareas *actual = *cabeza;
    ListaTareas *anterior = NULL;
    while (actual != NULL)
    {
        if (actual->tarea.id == id)
        {
            if (anterior == NULL)
            {
                *cabeza = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("No se encontro la tarea con id %d\n", id);
}

int main()
{
    ListaTareas *listaCabeza = NULL;
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    agregarTarea(&listaCabeza);
    listarTareas(listaCabeza);
    printf("\n");
    completarTarea(listaCabeza, 1);
    listarTareas(listaCabeza);
    printf("\n");
    eliminarTarea(&listaCabeza, 1);
    listarTareas(listaCabeza);
    printf("\n");
    eliminarTarea(&listaCabeza, 3);
    listarTareas(listaCabeza);

    return 0;
}