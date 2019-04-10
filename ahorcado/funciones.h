#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief muestra el menu principal
 *
 * \param char menu[][]: matriz que contiene los mensajes del menu
 * \param int filaMenu: las filas de la matriz
 * \param char eMensaje[]: vector que contiene mensajes de error
 * \param char *opcion: puntero que contien la opcion del menu
 * \param char desde: limite del menu
 * \param char hasta: limite del menu
 * \return void
 *
 */
void menu(char menu[][31],int filaMenu,char eMensaje[],char *opcion,char desde,char hasta);


/** \brief valida la opciones del menu
 *
 * \param char eMensaje[]: vector que contiene mensajes de error
 * \param char validar[]: vector que contien la opcion del menu que sera analizada antes de asignar
 * \param char *opcion: puntero que contien la opcion del menu
 * \param char desde: limite del menu
 * \param char hasta: limite del menu
 * \return void
 *
 */
void validarOpcion(char eMensaje[],char validar[],char *opcion,char desde,char hasta);


/** \brief pide el ingreso de la palabra para empezar a jugar
 *
 * \param char *palabra: puntero que va contener la palabra ingresada
 * \return 1: si hizo con exito el ingreso de la palabra
 *
 */
int ingresoPalabra(char *palabra);


/** \brief opcion del menu que en donde se ingresan letra para adivinar la palabra
 *
 * \param char *palabra: puntero que contiene la palabra ingresada
 * \param char *opcionMenu: puntero que contiene la opcion del menu secundario, al finalizar el juego le asigna '3', para regresar al menu principal
 * \return void
 *
 */
void adivinarPalabra(char *palabra,char *opcionMenu);


/** \brief pide el ingreso de una letra para jugar
 *
 * \param char *letra: puntero que va contener la letra ingresada
 * \return void
 *
 */
void ingresoLetra(char *letra);


/** \brief busca concidencias entre la palabra y la letra ingresada
 *
 * \param char *ptrLetra: puntero que contiene la letra ingresada
 * \param char *palabra: puntero que contiene la palabra ingresada
 * \param int *posicion: puntero que contiene una posicion, si la letra concide con un caracter de la palabra se le asigna un 1 en ese indice
 * \param int *vida: puntero que contiene las vidas del jugador, se van restando por cada letra mal ingresada
 * \return
 *
 */
void concidencia(char *ptrLetra,char *palabra,int *posicion,int *vida);


#endif
