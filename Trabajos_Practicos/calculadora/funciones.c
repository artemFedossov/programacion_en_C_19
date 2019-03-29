#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validarMenu(char validar[], char eMensaje[], char desde, char hasta, int cantidad);
float obtenerNumero(char eMensaje[],float numero);
float validarFlotante(char validar[],char eMensaje[], float numero);

void menu(){

    int cantidad;
    int flag;
    int opcion;
    float numeroA = 0;
    float numeroB = 0;
    char opcionMenu[10];
    char eMensaje[2][51] = {"\nERROR: la opcion ingresada es incorrecta\n",
                            "\nERROR: el numero ingresado no es valido\n"};

    do{
            system("cls");
            printf("----------CALCULADORA----------\n\n");
            printf("1) Ingrese el 1er operador (A=%.2f)\n",numeroA);
            printf("2) Ingrese el 2do operador (B=%.2f)\n",numeroB);
            printf("3) Calcular todas las operaciones\n");
            printf("4) Informar resultados\n");
            printf("5) Salir\n");
            printf("Opcion: ");
            scanf("%s",opcionMenu);
            cantidad = strlen(opcionMenu);
            opcion = validarMenu(opcionMenu,eMensaje[0],'1','5',cantidad);

            switch(opcion){
                case 1: numeroA = obtenerNumero(eMensaje[1],numeroA);
                    break;
                case 2: numeroB = obtenerNumero(eMensaje[1],numeroB);
                    break;
            }



    }while(opcion!=5);



}

int validarMenu(char validar[], char eMensaje[], char desde, char hasta, int cantidad){

    int i = 0;
    int num;

    while(validar[i] != '\0'){

        if((validar[i] < desde || validar[i] > hasta) || cantidad!=1){
            printf(eMensaje);
            system("pause");
        }

        i++;
        break;
    }

    return num = atoi(validar);

}

float obtenerNumero(char eMensaje[],float numero){

    char validar[51];

    printf("\nIngrese el primer numero: ");
    scanf("%s",validar);

    return numero = validarFlotante(validar,eMensaje,numero);

}

float validarFlotante(char validar[],char eMensaje[],float numero){

    int i=0;
    int flag = 0;

    while(validar[i] != '\0' && flag == 0){

        if((validar[i] != '-') && (validar[i] < '0' || validar[i] > '9') && (validar[i] != '.')){
            printf(eMensaje);
            flag = 1;
            system("pause");
        }
        i++;
    }
    if(flag == 0){
        numero = atof(validar);
    }

    return numero;
}
