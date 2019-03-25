#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematica.h"


/** \brief Calcula el promedio de numeros enteros
 *
 * \param numero[]: array que contiene los numeros ingresado
 * \param hasta: la cantidad de numeros promediados
 * \return promedio: retorna el promedio de los numeros
 *
 */
float calcularPromedio(int numero[],int hasta){

    int i;
    int acumulador = 0;
    float promedio;

    for(i=0; i<hasta; i++){
        scanf("%d",&numero[i]);
        acumulador = acumulador + numero[i];
    }

    promedio = (float)acumulador / hasta;

    return promedio;
}

int obtenerEntero(char mensaje[]){

    int num;

    printf(mensaje);
    scanf("%d",&num);

    num = distinoDeCero(num);

    return num;
}

int distinoDeCero(int num){

    char mensaje[51] = "Reingrese un numero distinto de Cero: ";

    while(num==0){

        num = obtenerEntero(mensaje);
    }

    return num;
}

int multiplicar(int numA, int numB){

    int total;

    total = numA * numB;

    return total;
}

int cuadradoDeUnNumero(int num){

    int total;

    total = num * num;

    return total;
}
