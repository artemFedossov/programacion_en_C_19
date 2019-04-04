#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief muestra el menu principal
 *
 * \return void
 *
 */
void menu();


/** \brief muestra el menu secundario donde se hacen los calculos correspondientes
 *
 * \param char mensaje: una matriz que contiene las opciones del menu secundario
 * \param char eMensaje: un array que contiene los posibles errores del menu
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultadoSuma: puntero al resultado que contiene la suma de ambos operadores
 * \param float *resultadoResta: puntero al resultado que contiene la resta de ambos operadores
 * \param float *resultadoDivision: puntero al resultado que contiene la division de ambos operadores
 * \param float *resultadoMultiplicacion: puntero al resultado que contiene la multiplicacion de ambos operadores
 * \param float *resultadoFactorialA: puntero al resultado que contiene el factorial del primer operador
 * \param float *resultadoFactorialB: puntero al resultado que contiene el factorial del segundo operador
 * \return void
 *
 */
void menuCalculo(char mensaje[][51],char eMensaje[],float *numA,float *numB,float *resultadoSuma,float *resultadoResta,float *resultadoDivision,float *resultadoMultiplicacion,int *resultadoFactorialA,int *resultadoFactorialB);


/** \brief muestra el menu secundario donde se hacen los informes de los calculos correspondientes
 *
 * \param char mensaje: una matriz que contiene las opciones del menu secundario
 * \param char eMensaje: un array que contiene los mensajes de los posibles errores del menu
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultadoSuma: puntero al resultado que contiene la suma de ambos operadores
 * \param float *resultadoResta: puntero al resultado que contiene la resta de ambos operadores
 * \param float *resultadoDivision: puntero al resultado que contiene la division de ambos operadores
 * \param float *resultadoMultiplicacion: puntero al resultado que contiene la multiplicacion de ambos operadores
 * \param float *resultadoFactorialA: puntero al resultado que contiene el factorial del primer operador
 * \param float *resultadoFactorialB: puntero al resultado que contiene el factorial del segundo operador
 * \return void
 *
 */
void menuInforme(char mensaje[][51],char eMensaje[],float *numA,float *numB,float *resultadoSuma,float *resultadoResta,float *resultadoDivision,float *resultadoMultiplicacion,int *resultadoFactorialA,int *resultadoFactorialB);


/** \brief valida la opcion que se ingresa en los menu
 *
 * \param char *opcion: puntero que contiene la opcion que se ingreso
 * \param int desde: limite del menu
 * \param int hasta: limite del menu
 * \param int cantidad: cantidad que indica cuantos carracteres tiene el menu
 * \param char eMensaje: array que contiene el mensaje de error al ingresar una opcion incorrecta
 * \return void
 *
 */
void validarOpcionMenu(char *opcion,int desde,int hasta,int cantidad,char eMensaje[]);


/** \brief realiza la suma de dos operadores
 *
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultado: puntero que contiene el resultado de la operacion
 * \return void
 *
 */
void suma(float *numA,float *numB,float *resultado);


/** \brief realiza la resta de dos operadores
 *
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultado: puntero que contiene el resultado de la operacion
 * \return void
 *
 */
void resta(float *numA,float *numB,float *resultado);


/** \brief realiza la division de dos operadores
 *
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultado: puntero que contiene el resultado de la operacion
 * \return void
 *
 */
void division(float *numA,float *numB,float *resultado);


/** \brief realiza la multiplicacion de dos operadores
 *
 * \param float *numA: puntero al primer operador
 * \param float *numB: puntero al segundo operador
 * \param float *resultado: puntero que contiene el resultado de la operacion
 * \return void
 *
 */
void multiplicacion(float *numA,float *numB,float *resultado);


/** \brief obtiene un numero ingresado atravez del teclado
 *
 * \param float *num: puntero que va guardar el numero ingresado
 * \param char mensaje: array que contiene un mensaje
 * \param char eMensaje: array que contiene el mensaje de error al ingresar una opcion incorrecta
 * \return 1: comprueba que se a ingresado un numero
 *
 */
int obtenerFlotante(float *num,char mensaje[],char eMensaje[]);


/** \brief obtiene un factorial de un numero
 *
 * \param float *num: puntero que contiene el numero a operar
 * \param float *resultado: puntero que contiene el resultado de la operacion
 * \return 1: si se pudo hacer la operacion o 0: si no se pudo hacer la operacion
 *
 */
int factorial(float *num, int *resultado);

#endif

