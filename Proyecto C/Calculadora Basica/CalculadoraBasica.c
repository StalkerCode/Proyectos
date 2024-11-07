#include "stdio.h"

float sum(float a, float b);
float rest(float a, float b);
float mult(float a, float b);
float div(float a, float b);

float ingresarValor();
void limpiarBuffer();
void menu();
void pausa();
void limpiar_pantalla();
void limpiar();

int main()
{
    char op;
    float num1, num2;
    do
    {
        menu();
        printf("ingrese una opcion(numero entero): ");
        scanf("%c", &op);
        limpiarBuffer();
        switch (op)
        {
        case '1':
            num1 = ingresarValor();
            num2 = ingresarValor();
            printf("\nLa suma de %.2f + %.2f es: %.2f\n\n", num1, num2, sum(num1, num2));
            limpiar();
            break;
        case '2':
            num1 = ingresarValor();
            num2 = ingresarValor();
            printf("\nLa resta de %.2f + %.2f es: %.2f\n\n", num1, num2, rest(num1, num2));
            limpiar();
            break;
        case '3':
            num1 = ingresarValor();
            num2 = ingresarValor();
            printf("\nLa multiplicacion de %.2f + %.2f es: %.2f\n\n", num1, num2, mult(num1, num2));
            limpiar();
            break;
        case '4':
            num1 = ingresarValor();
            num2 = ingresarValor();
            printf("\nLa dicicion de %.2f + %.2f es: %.2f\n\n", num1, num2, div(num1, num2));
            limpiar();
            break;
        case '5':
            printf("\nHasta luego\n\n");
            break;

        default:
            printf("\nopcion incorrecta\n\n");
            pausa();
            limpiar_pantalla();
            break;
        }

    } while (op != '5');

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

void menu()
{
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Elije: ");
}

void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

float ingresarValor()
{
    float num;
    printf("ingresa un numero real: ");
    scanf("%f", &num);
    return num;
}
void pausa()
{
    printf("Presiona una tecla para continuar...");
    getchar();
}
void limpiar_pantalla()
{
    printf("\033[2J"); // Limpia la pantalla
    printf("\033[H");  // Mueve el cursor al inicio
}
void limpiar()
{
    limpiarBuffer();
    pausa();
    limpiar_pantalla();
}