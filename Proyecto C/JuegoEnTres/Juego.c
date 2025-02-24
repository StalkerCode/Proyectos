#include <stdio.h>
#include <ctype.h>

void imprimirTablero(char tablero[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", tablero[i][0], tablero[i][1], tablero[i][2]);
        if (i < 2)
        {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}
void verificarTablero(char tablero[3][3])
{
    char ganador;
    // verifica filas
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
        {
            ganador = tablero[i][0];
            break;
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
        {
            ganador = tablero[0][i];
            break;
        }
    }
    // verifica diagonal
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
    {
        ganador = tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
    {
        ganador = tablero[0][0];
    }
    printf("el ganador es: %c", ganador);
}
void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

char crearCaracter()
{
    char buffer;

    while (1)
    {
        printf(":");
        if ((buffer = getchar()) == '\n')
        {
            continue;
        }
        limpiarBuffer();
        break;
    }

    return buffer;
}
int crearDigito()
{
    int numero = 0;
    while (1)
    {
        char c = crearCaracter();
        if (!isdigit(c))
        {
            printf("ingrese un numero\n");
            continue;
        }

        if (c > '3')
        {
            printf("ingrese un numero entre 1 y 3\n");
            continue;
        }
        numero = c - '0';
        break;
    }
    return numero;
}

int main()
{
    printf("%d", crearDigito());
    return 0;
}