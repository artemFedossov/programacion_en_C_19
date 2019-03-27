#include <stdio.h>
#include <stdlib.h>

/*Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado*/

int main()
{
    int numeroA;
    int numeroB;
    int resultado;

    printf("Ingrese el numero A: ");
    scanf("%d",&numeroA);

    printf("Ingrese el numero B. ");
    scanf("%d",&numeroB);

    resultado = numeroA + numeroB;
    printf("\nLa suma es: %d\n",resultado);

    return 0;
}
