#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematica.h"

/*Ingresar 5 números y calcular su media*/

int main()
{
    int numero[5];
    float promedio;

    printf("Ingrese 5 numeros:\n");

    promedio = calcularPromedio(numero,5);

    printf("El promedio es: %.2f",promedio);

    return 0;
}
