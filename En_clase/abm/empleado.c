#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"


#define TAM 5

void menu(char menu[][31],int filaMenu,char *eMensaje,char *opcion,char desde,char hasta){

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

void inicializarEstado(eEmpleado *emp,int tam){

    int i;

    for(i=0; i<tam; i++){

        emp[0].estado = 0;
    }

}

void mostrarEmpleado(eEmpleado emp){

    printf("%6d %10s %7c\t%.2f\n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);
}

void mostrarEmpleados(eEmpleado *lista,int tam){

    int i;

    printf("Legajo\t   Nombre\tSexo\tSueldo\n\n");

    for(i=0; i<tam; i++){

        if(lista[i].estado != 0){

            mostrarEmpleado(lista[i]);
        }
    }
    getch();
}

int buscarLibre(eEmpleado *lista,int tam){

    int i;
    int indice = -1;

    for(i=0; i<tam; i++){

        if(lista[i].estado == 0){

            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado *lista,int tam,int legajo){

    int i;
    int indice = -1;

    for(i=0; i<tam; i++){

        if(lista[i].estado != 0 && lista[i].legajo == legajo){

            indice = i;
            break;
        }
    }

    return indice;
}

void alta(eEmpleado *lista,int tam){

    int legajo;
    int esta;
    int libre;

    libre = buscarLibre(lista,TAM);

    if(libre == -1){
        printf("NO HAY LUGAR\n");

    }else{
        printf("Ingrese Legajo: ");
        scanf("%d",&legajo);

        esta = buscarEmpleado(lista,TAM,legajo);

        if(esta != -1){
            printf("YA EXISTE UN EMPLEADO CON EL MISMO LEGAJO\n\n");
            mostrarEmpleado(lista[esta]);
            getch();
        }else{

            lista[libre].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[libre].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c",&lista[libre].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f",&lista[libre].sueldo);

            lista[libre].estado = 1;
            printf("El empleado fue dado de alta con exito!!!");
            getch();
        }
    }

}
