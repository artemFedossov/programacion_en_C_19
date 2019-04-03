#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menuSecundario(char mensaje[][51]);


void menu(){

    float numeroA = 0;
    float numeroB = 0;
    char opcion[10];
    char mensajeMenu[6][51] =  {"\n1) Ingresar el 1er operador (A = %.2f) ","\n2) Ingresar el 2do operador (B = %.2f) ","\n3) Calcular operaciones\n","4) Informar resultado\n","5) Salir\n\n","Opcion: "};
    char mensajeOpcion3[9][51] = {"1) Calcular la suma\n","2) Calcular la resta\n","3) Calcular la division\n","4) Calcular la multiplicacion\n","5) Calcular el factorial\n","6) Calcular todas las operaciones\n","7) Regresar\n\n","Opcion: "};
    char mensajeOpcion4[9][51] = {"1) Informar el resultado de a A+B\n","2) Informar el resultado de A-B\n","3) Informar la division de A/B\n","4) Informar la multiplicacion de A*B\n","5) Informar el factorial\n","6) Informar todas las operaciones\n","7) Regresar\n\n","Opcion: "};
    char eMensaje[2][51] = {"ERROR. Ingreso una opcion incorrecta, REINGRESE: ","ERROR. Ingrese un numero, REINGRESE: "};
    char titulo[] = ("--------------------------------------------------------\n\t\t\tCALCULADORA\n--------------------------------------------------------\n");;

    float *ptrNumeroA;
    float *ptrNumeroB;
    char *ptrOpcion;

    ptrNumeroA = &numeroA;
    ptrNumeroB = &numeroB;
    ptrOpcion = &opcion;

    do{
            system("cls");
            printf(titulo);
            printf(mensajeMenu[0], *ptrNumeroA);
            printf(mensajeMenu[1], *ptrNumeroB);
            printf(mensajeMenu[2]);
            printf(mensajeMenu[3]);
            printf(mensajeMenu[4]);
            printf(mensajeMenu[5]);
            scanf("%s",opcion);
            validarOpcionMenu(ptrOpcion,1,5,1,eMensaje[0]);

            switch(*ptrOpcion){
                case '1':
                    system("cls");
                    printf(titulo);
                    obtenerFlotante(ptrNumeroA,mensajeMenu[0],eMensaje[1]);
                    break;
                case '2':
                    system("cls");
                    printf(titulo);
                    obtenerFlotante(ptrNumeroB,mensajeMenu[1],eMensaje[1]);
                    break;
                case '3':
                    menuSecundario(mensajeOpcion3);
                    break;
                case '4':
                    menuSecundario(mensajeOpcion4);
                    break;
            }

    }while(*ptrOpcion != '5');

}

void menuSecundario(char mensaje[][51]){

    int opcion;
    int i;

    do{
            system("cls");
            printf("--------------------------------------------------------\n\t\t\tCALCULADORA\n--------------------------------------------------------\n");
            for(i=0; i<9; i++){
                printf(mensaje[i]);
            }
            scanf("%d",&opcion);

    }while(opcion !=7);
}

void validarOpcionMenu(char *opcion,int desde,int hasta,int cantidad,char eMensaje[]){
    int i=0;
    char limite1[3];
    char limite2[3];

    itoa(desde,limite1,10);
    itoa(hasta,limite2,10);

    while(opcion[i] != '\0')
    {
        if((opcion[i] < limite1[0] || opcion[i] > limite2[0]) || (cantidad != 1))
        {
            printf(eMensaje);
            fflush(stdin);
            scanf("%s",opcion);
            cantidad = strlen(opcion);
            continue;
        }
        i++;
    }
}

void obtenerFlotante(float *num,char mensaje[],char eMensaje[]){

    int i=0;
    char validar[51];

    printf(mensaje,*num);
    fflush(stdin);
    scanf("%s",validar);

    while(validar[i] != '\0'){

        if((validar[i] != '-') && (validar[i] < '0' || validar[i] > '9') && (validar[i] != '.')){

            printf(eMensaje);
            fflush(stdin);
            scanf("%s",validar);
            i = 0;
            continue;
        }

        i++;
    }

    *num = atof(validar);

}
