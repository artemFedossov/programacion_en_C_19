#include <stdio.h>
#include <stdlib.h>

/*Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado*/

float obtenerFlotante(char []);
float mayorCero(float);
void longitudCircunferencia(float);
void areaCircunferencia(float);

int main()
{
    float radio;
    float longitud;
    float area;
    int opcionMenu=0;
    char mensaje[5][51] = {"Ingrese el radio de un circulo: ","Mostrar longitud de la circunferencia","Mostrar el area del circulo","3-Reingresar el raio\n","Salir"};

    radio = obtenerFlotante(mensaje[0]);

    do{
            system("cls");
            printf("Radio = %.2f\n------------------------------------------------\n",radio);
            printf("1-Mostrar longitud de la circunferencia\n");
            printf("2-Mostrar el area del circulo\n");
            printf("3-Reingresar el radio\n");
            printf("4-Salir\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcionMenu);

            switch(opcionMenu){

                case 1: system("cls");
                        longitudCircunferencia(radio);
                        system("pause");
                    break;

                case 2: system("cls");
                        areaCircunferencia(radio);
                        system("pause");
                    break;

                case 3: system("cls");
                        radio = obtenerFlotante(mensaje[0]);
                    break;

                case 4: opcionMenu = 4;
                    break;

            }

    }while(opcionMenu!=4);

    return 0;
}

float obtenerFlotante(char mensaje[]){

    float num;

    printf(mensaje);
    scanf("%f",&num);

    num = mayorCero(num);

    return num;
}

float mayorCero(float num){

    char mensaje[51] = "Reingrese un numero mayor de Cero: ";

    while(num<=0){

        num = obtenerFlotante(mensaje);
    }

    return num;
}

void longitudCircunferencia(float radio){
    float pi = 3.14;
    float longitud;
    float diamentro = radio * 2;

    longitud = diamentro * pi;

    printf("La longitud es %.2f\n",longitud);
}

void areaCircunferencia(float radio){
    float pi = 3.14;
    float area;

    area = (radio*radio)*pi;

    printf("El area es %.2f\n",area);
}
