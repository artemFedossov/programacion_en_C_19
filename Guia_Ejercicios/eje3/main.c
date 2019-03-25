#include <stdio.h>
#include <stdlib.h>

/*  Escribir un programa que realice las siguientes acciones
     Limpie la pantalla
     Asigne a 2 variables numero1 y numero2 valores distintos de cero
     Efectúe el producto de dichas variables
     Muestre el resultado pos pantalla
     Obtenga el cuadrado de numero1 y lo muestre par pantalla*/

int obtenerEntero(char[]);
int distinoDeCero(int);
int multiplicar(int, int);
int cuadradoDeUnNumero(int);

int main()
{
    int numA;
    int numB;
    int producto;
    int cuadrado;
    char mensaje[2][51] = {"Ingrese el primer numero: ","Ingrese el segundo numero: "};

    system("clr");

    numA = obtenerEntero(mensaje[0]);
    numB = obtenerEntero(mensaje[1]);

    producto = multiplicar(numA,numB);
    cuadrado = cuadradoDeUnNumero(numA);

    printf("\nEl multiplo de %d * %d es %d\n",numA,numB,producto);
    printf("El cuadrado de %d es %d\n",numA,cuadrado);

    return 0;
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
