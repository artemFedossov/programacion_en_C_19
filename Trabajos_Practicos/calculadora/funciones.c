#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void menu(){

    int ingresoNumA = 0;
    int ingresoNumB = 0;
    int resultadoFactorialA;
    int resultadoFactorialB;
    float numeroA = 0;
    float numeroB = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    char opcion[10];
    char mensajeMenu[6][51] =  {"\n1) Ingresar el 1er operador (A = %.2f) ","\n2) Ingresar el 2do operador (B = %.2f) ","\n3) Calcular operaciones\n","4) Informar resultado\n","5) Salir\n\n","Opcion: "};
    char mensajeOpcion3[8][51] = {"1) Calcular la suma\n","2) Calcular la resta\n","3) Calcular la division\n","4) Calcular la multiplicacion\n","5) Calcular el factorial\n","6) Calcular todas las operaciones\n","7) Regresar\n\n","Opcion: "};
    char mensajeOpcion4[8][51] = {"1) Informar el resultado de A+B\n","2) Informar el resultado de A-B\n","3) Informar la division de A/B\n","4) Informar la multiplicacion de A*B\n","5) Informar el factorial\n","6) Informar todas las operaciones\n","7) Regresar\n\n","Opcion: "};
    char eMensaje[3][51] = {"ERROR. Ingreso una opcion incorrecta, REINGRESE: ","ERROR. Ingrese un numero, REINGRESE: ","No ingreso todos los numeros\n"};
    char titulo[] = ("--------------------------------------------------------\n\t\t\tCALCULADORA\n--------------------------------------------------------\n");;

    int *ptrResultadoFactorialA;
    int *ptrResultadoFactorialB;
    float *ptrNumeroA;
    float *ptrNumeroB;
    float *ptrResultadoSuma;
    float *ptrResultadoResta;
    float *ptrResultadoDivision;
    float *ptrResultadoMultipliacion;
    char *ptrOpcion;

    ptrNumeroA = &numeroA;
    ptrNumeroB = &numeroB;
    ptrOpcion = &opcion[0];
    ptrResultadoSuma = &resultadoSuma;
    ptrResultadoResta = &resultadoResta;
    ptrResultadoDivision = &resultadoDivision;
    ptrResultadoMultipliacion = &resultadoMultiplicacion;
    ptrResultadoFactorialA = &resultadoFactorialA;
    ptrResultadoFactorialB = &resultadoFactorialB;

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
                    ingresoNumA = obtenerFlotante(ptrNumeroA,mensajeMenu[0],eMensaje[1]);
                    break;
                case '2':
                    system("cls");
                    printf(titulo);
                    ingresoNumB = obtenerFlotante(ptrNumeroB,mensajeMenu[1],eMensaje[1]);
                    break;
                case '3':
                    if(ingresoNumA && ingresoNumB){

                        menuCalculo(mensajeOpcion3,eMensaje[0],ptrNumeroA,ptrNumeroB,ptrResultadoSuma,ptrResultadoResta,ptrResultadoDivision,ptrResultadoMultipliacion,ptrResultadoFactorialA,ptrResultadoFactorialB);

                    }else{
                        printf(eMensaje[2]);
                        system("pause");
                    }
                    break;
                case '4':
                    if(ingresoNumA && ingresoNumA){

                        menuInforme(mensajeOpcion4,eMensaje[0],ptrNumeroA,ptrNumeroB,ptrResultadoSuma,ptrResultadoResta,ptrResultadoDivision,ptrResultadoMultipliacion,ptrResultadoFactorialA,ptrResultadoFactorialB);

                    }else{
                        printf(eMensaje[2]);
                        system("pause");
                    }
                    break;
            }

    }while(*ptrOpcion != '5');

}

void menuCalculo(char mensaje[][51],char eMensaje[],float *numA,float *numB,float *resultadoSuma,float *resultadoResta,float *resultadoDivision,float *resultadoMultiplicacion,int *resultadoFactorialA,int *resultadoFactorialB){

    int i;
    int factorA;
    int factorB;
    char opcion[10];

    char *ptrOpcion;

    ptrOpcion = &opcion[0];

    do{
            system("cls");
            printf("--------------------------------------------------------\n\t\t\tCALCULADORA\n--------------------------------------------------------\n");
            for(i=0; i<8; i++){
                printf(mensaje[i]);
            }
            scanf("%s",opcion);
            validarOpcionMenu(ptrOpcion,1,7,1,eMensaje);

            switch(*ptrOpcion){
                case '1':
                    suma(numA,numB,resultadoSuma);
                    printf("La suma se realizo con exito\n");
                    system("pause");
                    break;
                case '2':
                    resta(numA,numB,resultadoResta);
                    printf("La resta se realizo con exito\n");
                    system("pause");
                    break;
                case '3':
                    if(*numB != 0){
                        division(numA,numB,resultadoDivision);
                        printf("La division se realizo con exito\n");
                        system("pause");
                    }
                    else{
                        printf("El numero B tiene que ser distinto de cero\n");
                        system("pause");
                    }
                    break;
                case '4':
                    multiplicacion(numA,numB,resultadoMultiplicacion);
                    printf("La multiplicaion se realizo con exito\n");
                    system("pause");
                    break;
                case '5':
                    factorA = factorial(numA,resultadoFactorialA);
                    factorB = factorial(numB,resultadoFactorialB);
                    if(factorA && factorB){

                        printf("El factorial se realizo con exito\n");
                        system("pause");

                    }else{

                        printf("Engreso un numero decimal, reingrese un numero entero\n");
                        system("pause");
                    }
                    break;
                case '6':
                    factorA = factorial(numA,resultadoFactorialA);
                    factorB = factorial(numB,resultadoFactorialB);

                    if((*numB != 0) && (factorA && factorB)){

                        suma(numA,numB,resultadoSuma);
                        resta(numA,numB,resultadoResta);
                        division(numA,numB,resultadoDivision);
                        multiplicacion(numA,numB,resultadoMultiplicacion);
                        printf("Todas las operaciones se realizaron con exito\n");
                        system("pause");

                    }else if(*numB == 0){

                        printf("El numero B tiene que ser distinto de cero\n");
                        system("pause");

                    }else{

                        printf("Engreso un numero decimal, reingrese un numero entero\n");
                        system("pause");
                    }
                    break;
            }

    }while(*ptrOpcion !='7');
}

void menuInforme(char mensaje[][51],char eMensaje[],float *numA,float *numB,float *resultadoSuma,float *resultadoResta,float *resultadoDivision,float *resultadoMultiplicacion,int *resultadoFactorialA,int *resultadoFactorialB){

    int i;
    float totalSuma = *numA + *numB;
    float totalResta = *numA - *numB;
    float totalDivision = *numA / *numB;
    float totalMultiplicacion = *numA * *numB;
    int totalFactorA;
    int totalFactorB;
    char opcion[10];

    char *ptrOpcion;
    int *ptrTotalFactorA;
    int *ptrTotalFactorB;

    ptrOpcion = &opcion[0];
    ptrTotalFactorA = &totalFactorA;
    ptrTotalFactorB = &totalFactorB;

    factorial(numA,ptrTotalFactorA);
    factorial(numB,ptrTotalFactorB);

    do{
            system("cls");
            printf("--------------------------------------------------------\n\t\t\tCALCULADORA\n--------------------------------------------------------\n");
            for(i=0; i<8; i++){
                printf(mensaje[i]);
            }
            fflush(stdin);
            scanf("%s",opcion);
            validarOpcionMenu(ptrOpcion,1,7,1,eMensaje);

            switch(*ptrOpcion){
                case '1':
                    if(*resultadoSuma == totalSuma){
                        printf("La suma de %.2f + %.2f = %.2f\n",*numA,*numB,*resultadoSuma);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case '2':
                    if(*resultadoResta == totalResta){
                        printf("La resta de %.2f - %.2f = %.2f\n",*numA,*numB,*resultadoResta);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case '3':
                    if(*resultadoDivision == totalDivision){
                        printf("La division de %.2f / %.2f = %.2f\n",*numA,*numB,*resultadoDivision);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case '4':
                    if(*resultadoMultiplicacion == totalMultiplicacion){
                        printf("La multiplicacion de %.2f * %.2f = %.2f\n",*numA,*numB,*resultadoMultiplicacion);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case '5':
                    if((*resultadoFactorialA == *ptrTotalFactorA) && (*resultadoFactorialB == *ptrTotalFactorB)){
                        printf("El factorial de %.0f es %d\n",*numA,*resultadoFactorialA);
                        printf("El factorial de %.0f es %d\n",*numB,*resultadoFactorialB);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case '6':
                    if((*resultadoSuma == totalSuma) && (*resultadoResta == totalResta) && (*resultadoDivision == totalDivision) && (*resultadoMultiplicacion == totalMultiplicacion) && (*resultadoFactorialA == *ptrTotalFactorA) && (*resultadoFactorialB == *ptrTotalFactorB)){
                        printf("La suma de %.2f + %.2f = %.2f\n",*numA,*numB,*resultadoSuma);
                        printf("La resta de %.2f - %.2f = %.2f\n",*numA,*numB,*resultadoResta);
                        printf("La division de %.2f / %.2f = %.2f\n",*numA,*numB,*resultadoDivision);
                        printf("La multiplicacion de %.2f * %.2f = %.2f\n",*numA,*numB,*resultadoMultiplicacion);
                        printf("El factorial de %.0f es %d\n",*numA,*resultadoFactorialA);
                        printf("El factorial de %.0f es %d\n",*numB,*resultadoFactorialB);
                        system("pause");
                    }else{
                        printf("Se ingreso un numero diferente, vuelva al menu de operaciones para realizar el calculo\n");
                        system("pause");
                    }

            }
    }while(*ptrOpcion !='7');

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

int obtenerFlotante(float *num,char mensaje[],char eMensaje[]){

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

    return 1;

}

void suma(float *numA,float *numB,float *resultado){

    float numeroA = *numA;
    float numeroB = *numB;
    float total;

    total = numeroA + numeroB;

    *resultado = total;
}

void resta(float *numA,float *numB,float *resultado){

    float numeroA = *numA;
    float numeroB = *numB;
    float total;

    total = numeroA - numeroB;

    *resultado = total;
}

void division(float *numA,float *numB,float *resultado){

    float numeroA = *numA;
    float numeroB = *numB;
    float total;

    total = numeroA / numeroB;

    *resultado = total;
}

void multiplicacion(float *numA,float *numB,float *resultado){

    float numeroA = *numA;
    float numeroB = *numB;
    float total;

    total = numeroA * numeroB;

    *resultado = total;
}

int factorial(float *num, int *resultado){

    long total = 0;
    float numero;
    int factor;
    int flag = 0;
    int ok = 0;
    factor = *num;
    numero = *num;

    if(numero == factor)
    {
        if(factor > 0)
        {
            while(factor != 1)
            {
                if(flag == 0)
                {
                    total = factor * (factor - 1);
                    factor = factor - 1;
                    flag = 1;
                }
                else
                {
                    total = (factor - 1) * total;
                    factor = factor - 1;
                }
            }
        }
        if(numero == 1){
            *resultado = 1;
        }
        else{
            *resultado = total;
        }

        ok = 1;
    }

    return ok;
}
