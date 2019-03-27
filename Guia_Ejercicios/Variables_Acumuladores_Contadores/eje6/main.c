#include <stdio.h>
#include <stdlib.h>

/*De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero*/

int obtenerEntero(char[]);

int main()
{
    int numero[10];
    int i;
    int contMayor=0;
    int contMenor=0;
    char mensaje[51] = "Ingrese un numero: ";

    for(i=0; i<10; i++){

        numero[i] = obtenerEntero(mensaje);

        if(numero[i]>0){
            contMayor++;
        }
        else if(numero[i]<0)
        {
            contMenor++;
        }
    }

    printf("\nHay %d mayores a cero\nHay %d menores a cero\n",contMayor,contMenor);

    return 0;
}

int obtenerEntero(char mensaje[]){

    int num;

    printf(mensaje);
    scanf("%d",&num);

    return num;
}
