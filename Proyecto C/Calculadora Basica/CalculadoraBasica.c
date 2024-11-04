#include "stdio.h"

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

int main()
{

    return 0;
}