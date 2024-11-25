#include "stdio.h"
#include "stdlib.h"
#include "time.h"


//! falta valides de rango
int main()
{
    srand(time(NULL));
    int numero = (rand() % 100) + 1;
    int n = -1;
    printf("Adivine el numero entre 1 y 100\n");
    while (!(n == numero))
    {
        printf("ingrese el numero:");
        scanf("%d", &n);
        int diferencia = abs(n - numero);
        if (diferencia <= 4)
        {
            printf("Muy Muy Caliente\n");
        }
        else if (diferencia <= 8)
        {
            printf("Muy Caliente\n");
        }
        else if (diferencia <= 12)
        {
            printf("Caliente\n");
        }
        else if (diferencia <= 16)
        {
            printf("Tibio\n");
        }
        else if (diferencia <= 20)
        {
            printf("Frio\n");
        }
        else if (diferencia <= 24)
        {
            printf("Muy Frio\n");
        }
        else
        {
            printf("Extremo Muy Frio\n");
        }
    }

    return 0;
}
