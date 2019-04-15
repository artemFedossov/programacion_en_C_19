#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct{

    int legajo;
    int estado;
    char nombre[20];
    char sexo;
    float sueldo;

}eEmpleado;

void menu(char menu[][31],int filaMenu,char *eMensaje,char *opcion,char desde,char hasta);
void validarOpcion(char eMensaje[],char validar[],char *opcion,char desde,char hasta);
void inicializarEstado(eEmpleado *emp,int tam);

int main()
{
    char mensaje[8][31] = {"\t\tABM Empleados\n\n\n","1) Altas Empleados\n","2) Bajas Empleados\n","3) Modificar Empleados\n","4) Listar\n","5) Ordenar\n","6) Salir\n\n","Opcion: "};
    char eMensaje[2][51] = {"\nERROR: Reingrese opcion: "};
    char opcion[5];
    int legajo;
    int esta;
    eEmpleado lista[TAM] = {{1234,1,"Juan",'m',20000},{2345,0,"Maria",'f',34000},{3456,1,"Jorge",'m',33000}};

    char *ptrOpcion;

    ptrOpcion = &opcion[0];

    do{
        system("cls");
        menu(mensaje,8,eMensaje[0],ptrOpcion,'1','8');

        switch(*ptrOpcion){
            case '1':
                if(buscarLibre(lista,TAM) == -1){
                    printf("NO HAY LUGAR\n");

                }else{
                    printf("Ingrese Legajo: ");
                    scanf("%d",&legajo);

                    esta = buscarEmpleado(lista,TAM,legajo);

                    if(esta != -1){
                        printf("YA EXISTE UN EMPLEADO CON EL MISMO LEGAJO\n\n");
                        mostrarEmpleado(lista[esta]);
                    }
                }
                getch();
                break;

            case '2': printf("baja empleado\n");
                system("pause");
                break;

            case '3': printf("modificar empleado\n");
                system("pause");
                break;

            case '4':
                mostrarEmpleados(lista,TAM);
                getch();
                break;

            case '5': printf("ordenar empleado\n");
                system("pause");
                break;

            }


    }while(*ptrOpcion != '6');

    return 0;
}

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

        if(lista[i].estado == 1 && lista[i].legajo == legajo){

            indice = i;
            break;
        }
    }

    return indice;
}
