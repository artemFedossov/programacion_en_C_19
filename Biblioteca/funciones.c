#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematica.h"


/** \brief Calcula el promedio de numeros enteros
 *
 * \param numero[]: array que contiene los numeros ingresado
 * \param hasta: la cantidad de numeros promediados
 * \return promedio: retorna el promedio de los numeros
 *
 */
float calcularPromedio(int numero[],int hasta){

    int i;
    int acumulador = 0;
    float promedio;

    for(i=0; i<hasta; i++){
        scanf("%d",&numero[i]);
        acumulador = acumulador + numero[i];
    }

    promedio = (float)acumulador / hasta;

    return promedio;
}


/** \brief obtiene un numero entero
 *
 * \param mensaje[]: mensaje que pide un numero por pantalla
 * \return num: retorna el numero ingresado
 *
 */
int obtenerEntero(char mensaje[]){

    int num;

    printf(mensaje);
    scanf("%d",&num);

    num = distinoDeCero(num);

    return num;
}


/** \brief valida que un numero sea distinto de cero
 *
 * \param num: el numero que sera validado para que sea distinto de cero
 * \return num: retorna el numero
 *
 */
int distinoDeCero(int num){

    char mensaje[51] = "Reingrese un numero distinto de Cero: ";

    while(num==0){

        num = obtenerEntero(mensaje);
    }

    return num;
}


/** \brief multiplica dos numeros
 *
 * \param numA: un numero que sera multiplicado
 * \param numB: el otro numero a multiplicar
 * \return total: retorna el total de la multiplicacion
 *
 */
int multiplicar(int numA, int numB){

    int total;

    total = numA * numB;

    return total;
}


/** \brief calcula el cuadrado de un numero
 *
 * \param num: un numero que sera multiplicado por si mismo
 * \return total: retorna el total de la multiplicacion
 *
 */
int cuadradoDeUnNumero(int num){

    int total;

    total = num * num;

    return total;
}


/** \brief obtiene un numero flotante
 *
 * \param mensaje[]: mensaje que pide un numero por pantalla
 * \return num: retorna el numero ingresado
 *
 */
float obtenerFlotante(char mensaje[]){

    float num;

    printf(mensaje);
    scanf("%f",&num);

    num = mayorCero(num);

    return num;
}


/** \brief valida que un numero sea mayor a cero
 *
 * \param num: el numero que sera validado para que sea mayor a cero
 * \return num: retorna el numero
 *
 */
float mayorCero(float num){

    char mensaje[51] = "Reingrese un numero mayor de Cero: ";

    while(num<=0){

        num = obtenerFlotante(mensaje);
    }

    return num;
}


/** \brief calcular la longitud de una circunferencia teniendo como dato el radio y muestra el dato
 *
 * \param radio: es el dato para calcular la circunferencia
 * \return void
 *
 */
void longitudCircunferencia(float radio){
    float pi = 3.14;
    float longitud;
    float diamentro = radio * 2;

    longitud = diamentro * pi;

    printf("La longitud es %.2f\n",longitud);
}


/** \brief calcular el area de una circunferencia teniendo como dato el radio y muestra el dato
 *
 * \param radio: es el dato para calcular el area
 * \return void
 *
 */
void areaCircunferencia(float radio){
    float pi = 3.14;
    float area;

    area = (radio*radio)*pi;

    printf("El area es %.2f\n",area);
}


/** \brief calcula la superficie de un triangulo teniendo la altura y la base y muestra por pantalla el resultado
 *
 * \param altura: dato para calcular la superficie
 * \param base: dato para calcular la base
 * \return void
 *
 */
void superficieTriangulo(float altura, float base){

    float superficie;

    superficie = base * altura;

    printf("\nLa superficie del triangulo es: %.2f\n",superficie);

}
