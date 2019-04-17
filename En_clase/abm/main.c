#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

#define TAM 3

int main()
{
    char mensaje[8][31] = {"\t\tABM Empleados\n\n\n","1) Altas Empleados\n","2) Bajas Empleados\n","3) Modificar Empleados\n","4) Listar\n","5) Ordenar\n","6) Salir\n\n","Opcion: "};
    char eMensaje[2][51] = {"\nERROR: Reingrese opcion: "};
    char opcion[5];
    eEmpleado lista[TAM] = {{1234,1,"Juan",'m',20000},{2345,-1,"Maria",'f',34000},{3456,1,"Jorge",'m',33000}};

    char *ptrOpcion;

    ptrOpcion = &opcion[0];

    do{
        system("cls");
        menu(mensaje,8,eMensaje[0],ptrOpcion,'1','8');

        switch(*ptrOpcion){
            case '1':
                alta(lista,TAM);
                break;

            case '2': printf("baja empleado\n");
                system("pause");
                break;

            case '3': printf("modificar empleado\n");
                system("pause");
                break;

            case '4':
                mostrarEmpleados(lista,TAM);
                break;

            case '5': printf("ordenar empleado\n");
                system("pause");
                break;

            }


    }while(*ptrOpcion != '6');

    return 0;
}

