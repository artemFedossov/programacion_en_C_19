#include <stdio.h>
#include <stdlib.h>

/*  Escribir un programa que realice las siguientes acciones:
     Limpie la pantalla
     Declare 2 variables y les asigne sendos valores
     Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de
      ser mayor que cero o "Resultado negativo" si es menor que cero*/

int obtenerEntero(char[]);

int main()
{
    int numA;
    int numB;
    int resultado;
    char mensaje[2][51] = {"Ingrese el primer numero: ","Ingrese el segundo numero: "};

    numA = obtenerEntero(mensaje[0]);
    numB = obtenerEntero(mensaje[1]);

    resultado = numA - numB;

    if(resultado<0){

        printf("El resultado es negativo: %d",resultado);
    }
    else if(resultado>0){

        printf("El resultado es positivo: %d",resultado);
    }
    else{

        printf("El resultado es nulo");
    }

    return 0;
}

int obtenerEntero(char mensaje[]){

    int num;

    printf(mensaje);
    scanf("%d",&num);

    return num;
}
