#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char opcionPrincipal[21];
    char opcionSecundaria[21];
    char menuPrincipal[4][31] = {"\t\tAHORCADO\n\n","1) A JUGAR\n","2) Salir\n","\nOpcion: "};
    char menuJugar[5][31] = {"\t\tAHORCADO\n\n","1) Ingresar palabra\n","2) Adivinar palabra\n","3) Regresar\n""\nOpcion: "};
    char eMensaje[3][51] = {"ERROR, opcion incorrecta: "," "};

    char *ptrOpcionPrincipal;
    char *ptrOpcionSecundaria;

    ptrOpcionPrincipal = &opcionPrincipal[0];
    ptrOpcionSecundaria = &opcionSecundaria[0];

    do{

        menu(menuPrincipal,4,eMensaje[0],ptrOpcionPrincipal,'1','2');
        system("cls");

        switch(*ptrOpcionPrincipal){
            case '1':   menu(menuJugar,4,eMensaje[0],ptrOpcionSecundaria,'1','3');
                        switch(*ptrOpcionSecundaria){
                            case '1':   printf("hola");
                                        system("pause");
                                break;
                        }
                break;
        }

    }while(*ptrOpcionPrincipal != '2');


    return 0;
}

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
