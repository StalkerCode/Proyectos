#include "stdio.h"
#include "stdlib.h"

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);

void menu();
void limpiar_pantalla();
void opciones(int opcion);
float validarEntradaFloat();
int validarEntradaInt();
void pausa();

int main()
{
    int op;
    printf("Bienvenido a la Conversor de Temperatura\n");
    do
    {
        menu();
        op = validarEntradaInt();
        opciones(op);
        limpiar_pantalla();
    } while (op != 0);

    printf("\n\nGracias por usar la Conversor de Temperatura\n\n\n");

    return 0;
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}
float celsius_to_kelvin(float celsius)
{
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin)
{
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit)
{
    return (fahrenheit + 459.67) * (5 / 9);
}
float kelvin_to_fahrenheit(float kelvin)
{
    return (kelvin - 273.15) * (9 / 5) + 32;
}

void menu()
{
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Salir\n");
}

void limpiar_pantalla()
{
    printf("\033[2J"); // Limpia la pantalla
    printf("\033[H");  // Mueve el cursor al inicio
}

void opciones(int opcion)
{
    float celsius, fahrenheit, kelvin;
    switch (opcion)
    {
    case 0:
        printf("\n\nHasta luego\n\n");
        pausa();
        break;
    case 1:
        printf("Ingrese la temperatura en Celsius: ");
        celsius = validarEntradaFloat();
        printf("\nLa temperatura en Fahrenheit es: %.2f\n", celsius_to_fahrenheit(celsius));
        pausa();
        break;
    case 2:
        printf("Ingrese la temperatura en Fahrenheit: ");
        fahrenheit = validarEntradaFloat();
        printf("\nLa temperatura en Celsius es: %.2f\n", fahrenheit_to_celsius(fahrenheit));
        pausa();
        break;
    case 3:
        printf("Ingrese la temperatura en Celsius: ");
        celsius = validarEntradaFloat();
        printf("\nLa temperatura en Kelvin es: %.2f\n", celsius_to_kelvin(celsius));
        pausa();
        break;
    case 4:
        printf("Ingrese la temperatura en Kelvin: ");
        kelvin = validarEntradaFloat();
        printf("\nLa temperatura en Celsius es: %.2f\n", kelvin_to_celsius(kelvin));
        pausa();
        break;
    case 5:
        printf("\nIngrese la temperatura en Fahrenheit: ");
        fahrenheit = validarEntradaFloat();
        printf("La temperatura en Kelvin es: %.2f\n", fahrenheit_to_kelvin(fahrenheit));
        pausa();
        break;
    case 6:
        printf("\nIngrese la temperatura en Kelvin: ");
        kelvin = validarEntradaFloat();
        printf("La temperatura en Fahrenheit es: %.2f\n", kelvin_to_fahrenheit(kelvin));
        pausa();
        break;
    default:
        printf("\nOpcion incorrecta\n");
        pausa();
        break;
    }
}
float validarEntradaFloat()
{
    float numero;
    char entrada[100];

    while (1)
    {
        printf("Ingrese una temperatura: ");
        fgets(entrada, sizeof(entrada), stdin);

        // Verificar si la entrada es un número flotante válido
        if (sscanf(entrada, "%f", &numero) == 1)
        {
            return numero;
        }
        else
        {
            printf("Error: La entrada no es un numero flotante valido.\n");
        }
    }
}
int validarEntradaInt()
{
    int numero;
    char entrada[100];
    while (1)
    {
        printf("Ingrese una opcion: ");
        fgets(entrada, sizeof(entrada), stdin);
        // Verificar si la entrada es un número entero válido
        if (sscanf(entrada, "%d", &numero) == 1)
        {
            return numero;
        }
        else
        {
            printf("Error: La entrada no es un numero entero valido.\n");
        }
    }
}
void pausa()
{
    printf("Presiona una tecla para continuar...");
    getchar();
    1 == 0;
}