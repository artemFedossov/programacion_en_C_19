#include <stdio.h>
#include <stdlib.h>

/*Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y
muestre el resultado.*/

float obtenerFlotante(char mensaje[]);
float mayorCero(float num);
void superficieTriangulo(float, float);

int main()
{
    float base;
    float altura;
    float resultado;
    char mensaje[2][51] = {"Ingrese la base del triangulo: ","Ingrese la altura del triangulo: "};

    base = obtenerFlotante(mensaje[0]);
    altura = obtenerFlotante(mensaje[1]);

    superficieTriangulo(altura,base);

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

void superficieTriangulo(float altura, float base){

    float superficie;

    superficie = base * altura;

    printf("\nLa superficie del triangulo es: %.2f\n",superficie);

}
