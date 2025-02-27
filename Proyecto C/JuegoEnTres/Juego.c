#include <stdio.h>
#include <ctype.h>

void limpiarBuffer();
char crearCaracter();
int crearDigito();
void rellenarTablero(char tablero[3][3]);
void imprimirTablero(char tablero[3][3]);
void marcarCasilla(char tablero[3][3], char jugador, int fila, int columna);
int verificarTablero(char tablero[3][3], char jugador);
int tableroLleno(char tablero[3][3]);
int cacillaOcupada(char tablero[3][3], int fila, int columna);

int main()
{
    char tablero[3][3];
    char Juagor1 = 'X';
    char Juagor2 = 'O';
    char jugadorActual = Juagor1;

    rellenarTablero(tablero);
    imprimirTablero(tablero);

    while (1)
    {
        printf("Jugador %c\n", jugadorActual);
        printf("Ingrese la fila (1-3):");
        int fila = crearDigito();
        printf("Ingrese la columna (1-3):");
        int columna = crearDigito();
        if (cacillaOcupada(tablero, fila, columna))
        {
            printf("Casilla ocupada\n");
            continue;
        }
        marcarCasilla(tablero, jugadorActual, fila, columna);
        imprimirTablero(tablero);
        if (verificarTablero(tablero, jugadorActual))
        {
            printf("El ganador es: %c", jugadorActual);
            break;
        }
        if (tableroLleno(tablero))
        {
            printf("Es un Empate");
            break;
        }

        if (jugadorActual == Juagor1)
        {
            jugadorActual = Juagor2;
        }
        else
        {
            jugadorActual = Juagor1;
        }
    }

    return 0;
}

void rellenarTablero(char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

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

int verificarTablero(char tablero[3][3], char jugador)
{
    char ganador;
    // verifica filas y columnas
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
        {
            return 1;
        }
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
        {
            return 1;
        }
    }
    // verifica diagonal
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
    {
        return 1;
    }
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
    {
        return 1;
    }
    return 0;
}

int tableroLleno(char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
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

        if (c == '0' || c > '3')
        {
            printf("ingrese un numero entre 1 y 3\n");
            continue;
        }
        numero = c - '0';
        break;
    }
    return numero;
}

void marcarCasilla(char tablero[3][3], char jugador, int fila, int columna)
{
    tablero[fila - 1][columna - 1] = jugador;
}

int cacillaOcupada(char tablero[3][3], int fila, int columna)
{
    if (tablero[fila - 1][columna - 1] != ' ')
    {
        return 1;
    }
    return 0;
}