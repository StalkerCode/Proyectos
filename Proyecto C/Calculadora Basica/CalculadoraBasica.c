#include "stdio.h"
#include "ctype.h"

float sum(float a, float b);
float rest(float a, float b);
float mult(float a, float b);
float div(float a, float b);

int ingresar_entero();

void limpiarBuffer();
void menu();

int main()
{
    ingresar_entero();

    return 0;
}

float sum(float a, float b)
{
    return a + b;
}

float rest(float a, float b)
{
    return a - b;
}

float mult(float a, float b)
{
    return a * b;
}

float div(float a, float b)
{
    if (b == 0)
    {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return a / b;
}

void menu(){
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Elije: ");
}

int ingresar_entero(){
    char num;
    printf("ingrese una opcion(numero entero): ");
    scanf("%c", &num);
    limpiarBuffer();
    while (!isdigit(num))
    {
        printf("Error: Ingreso incorrecto, intente de nuevo.\n");
        printf("ingrese una opcion(numero entero): ");
        scanf("%c", &num);
        limpiarBuffer();
    }
    return num;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}