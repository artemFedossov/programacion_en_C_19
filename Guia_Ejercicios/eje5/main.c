#include <stdio.h>
#include <stdlib.h>

/* Escribir el programa necesario para calcular y mostrar el cuadrado de un número. El número debe ser
   mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"
*/

int obtenerEntero(char mensaje[]);
int distinoDeCero(int num);
int cuadradoDeUnNumero(int num);

int main()
{
    int num;
    int cuadrado;
    char mensaje[51] = "Ingrese un numero: ";

    num = obtenerEntero(num)

    cuadrado = cuadradoDeUnNumero(num);


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

    char mensaje[51] = "ERROR, el número debe ser mayor que cero: ";

    while(num==0){

        num = obtenerEntero(mensaje);
    }

    return num;
}

int cuadradoDeUnNumero(int num){

    int total;

    total = num * num;

    return total;
}
