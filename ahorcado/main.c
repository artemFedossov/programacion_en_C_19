#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char opcionPrincipal[21];
    char opcionSecundaria[21];
    char palabra[51];
    char menuPrincipal[4][31] = {"\t\tAHORCADO\n\n","1) A JUGAR\n","2) Salir\n","\nOpcion: "};
    char menuJugar[5][31] = {"\t\tAHORCADO\n\n","1) Ingresar palabra\n","2) Adivinar palabra\n","3) Regresar\n""\nOpcion: "};
    char eMensaje[3][51] = {"ERROR!!! opcion incorrecta: "," "};
    int ok; //una bandera para que no se pueda ingresar al adivinar la palabras antes de ser ingresada

    char *ptrOpcionPrincipal;
    char *ptrOpcionSecundaria;
    char *ptrPalabra;

    ptrOpcionPrincipal = &opcionPrincipal[0];
    ptrOpcionSecundaria = &opcionSecundaria[0];
    ptrPalabra = &palabra[0];

    do{

        menu(menuPrincipal,4,eMensaje[0],ptrOpcionPrincipal,'1','2');
        system("cls");

        switch(*ptrOpcionPrincipal){
            case '1':
                    ok=0; //inizialisamos en o la bandera
                    do{
                        menu(menuJugar,4,eMensaje[0],ptrOpcionSecundaria,'1','3');
                        switch(*ptrOpcionSecundaria){
                            case '1':   system("cls");
                                        ok = ingresoPalabra(ptrPalabra);
                                break;
                            case '2':   system("cls");
                                        if(ok){
                                            adivinarPalabra(ptrPalabra,ptrOpcionSecundaria);
                                        }else{
                                            printf("\t\tAHORCADO\n\nPrimero ingrese la palabra!!!!\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                break;
                        }

                    }while(*ptrOpcionSecundaria != '3');
                system("cls");
                break;
        }

    }while(*ptrOpcionPrincipal != '2');


    return 0;
}

