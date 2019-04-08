#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcion[10];
    char eMensaje[2][51] = {"La opcion ingresada es incorrecta: "}

    char ptrOpcion;

    ptrOpcion = &opcion[0];

    do{

        printf("\n-----------------AHORCADO------------------\n\n");
        printf("1) A Jugar\n");
        printf("2) Salir\n");
        printf("\nOpcion: ");
        gets(ptrOpcion);

        validarMenu


    }while(opcion != '2');


    return 0;
}

void validarMenu(char *validar, int desde, int hasta, char eMensaje[]){


}
