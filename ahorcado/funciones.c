#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void menu(char menu[][31],int filaMenu,char eMensaje[],char *opcion,char desde,char hasta){

    char validar[21];
    int i;

    for(i=0; i <filaMenu; i++){

        printf(menu[i]);
    }

    fflush(stdin);
    scanf("%s",validar);

    validarOpcion(eMensaje,validar,opcion,desde,hasta);

}

void validarOpcion(char eMensaje[],char validar[],char *opcion,char desde,char hasta){

    int i=0;
    int carracteres;

    carracteres = strlen(validar);

    while(validar[i] != '\0'){

        if((validar[i] < desde || validar[i] > hasta) || (carracteres!=1)){

            printf(eMensaje);
            fflush(stdin);
            scanf("%s",validar);
            carracteres = strlen(validar);
            i=0;
            continue;
        }
        i++;
    }

    *opcion = validar[0];
}

int ingresoPalabra(char *palabra){

    char validar[51];
    int i = 0;

    printf("\t\tAHORCADO\n\nIngrese la palabra para adivinar: ");
    fflush(stdin);
    scanf("%s",validar);
    strupr(validar);

    while(validar[i] != '\0'){

        if(validar[i] < 'A' || validar[i] > 'Z'){
            printf("ERROR!!! Reingrese la palabra: ");
            fflush(stdin);
            scanf("%s",validar);
            strupr(validar);
            i=0;
            continue;
        }
        i++;
    }
    strcpy(palabra,validar);
    system("cls");

    return 1;
}

void adivinarPalabra(char *palabra,char *opcionMenu){

    char letra[51];
    //char aux[20][3] = {' '};
    int posicion[51] = {0};
    int i;
    //int j;
    int vidas = 3;
    int largo;
    int contador;
    int salir = 0;

    char *ptrLetra;
    int *ptrPosicion;
    int *ptrVidas;

    ptrLetra = &letra[0];
    ptrPosicion = &posicion[0];
    ptrVidas = &vidas;

    largo = strlen(palabra);

    do{
        system("cls");
        printf("\t\tAHORCADO\n\n");
        printf("VIDAS = %d\n",*ptrVidas);
        printf("PALABRA DE %d LETRAS\n\n",largo);
        /*for(i=0; i<20; i++){
            for(j=0; j<3; j++){
                if(aux[i][j] != ' '){
                printf("LETRAS INGRESADAS: %s\n\n",aux[i][j]);
                }
            }
        }*/

        for(i=0; i<largo; i++){

            if(ptrPosicion[i] == 1){

                printf("%c",palabra[i]);

            }else{
                printf(" ");
            }
        }
        ingresoLetra(ptrLetra);
        /*for(i=0; i<20; i++){
                for(j=0; j<3; j++){
                    if(aux[i][j] == ' '){
                    aux[i][j] = *ptrLetra;
                    break;
                }
            }
        }*/
        concidencia(ptrLetra,palabra,ptrPosicion,ptrVidas);
        if(*ptrVidas == 0){
            system("cls");
            printf("\t\tAHORCADO\n\nGAME OVER\n\n");
            system("pause");
            *opcionMenu = '3';
            salir = 1;
        }else{
            contador = 0;
            for(i=0; i<largo; i++){
                if(ptrPosicion[i] == 1){
                    contador ++;
                }if(contador == largo){
                    system("cls");
                    printf("\t\tAHORCADO\n\nGANASTE!!!!!!!!\n\n");
                    system("pause");
                    *opcionMenu = '3';
                    salir = 1;
                }
            }
        }

    }while(salir != 1);


}

void ingresoLetra(char *letra){

    char validar[51];
    int carracteres;
    int i = 0;

    printf("\n\nIngrese una letra: ");
    fflush(stdin);
    scanf("%s",validar);
    carracteres = strlen(validar);
    strupr(validar);

    while(validar[i] != '\0'){

        if((validar[i] < 'A' || validar[i] > 'Z') || (carracteres != 1)){

            printf("ERROR!!! Ingrese una letra: ");
            fflush(stdin);
            scanf("%s",validar);
            carracteres = strlen(validar);
            strupr(validar);
            i=0;
            continue;
        }
        i++;
    }

    strcpy(letra,validar);

}

void concidencia(char *ptrLetra,char *palabra,int *posicion,int *vida){

    int largo;
    int flag = 0;
    int i;

    largo = strlen(palabra);

    for(i=0; i<largo; i++){

        if(palabra[i] == ptrLetra[0]){

            posicion[i] = 1;
            flag = 1;

        }
    }

    if(flag==0){
        *vida = *vida -1;
    }
}
