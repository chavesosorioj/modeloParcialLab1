/*
 * ejerUtn.h
 *
 *  Created on: Apr 14, 2020
 *      Author: juliana
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * brief solicita un número al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el número ingresado por el usuario
 */

int getInt(char mensaje[]);
/*
 * brief solicita un número al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el número ingresado por el usuario
 */
float getFloat(char mensaje[]);
/*
 * brief solicita un caracter al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el caracter ingresado por el usuario
 */
char getChar(char mensaje[]);
/*
 * brief genera un numero aleatorio
 * param desde y hasta los parametros dentro del que se genera el numero
 * return el número aleatorio
 */
int getNumeroAleatorio(int desde, int hasta, int iniciar);
/*
 * brief Verifica si el valor es numerico
 * str Array con la cadena a analizar
 * return 1 si es numerico y 0 si no lo es
 */
int isNum(char* string);
/*
 * brief Verifica si el valor recibido es un numero telefónico
 * param str Array con la cadena a analizar
 * return 1 si es un telefon y 0 si no lo es
 */
int isPhone(char str[]);

/*
 * breif valida que lo ingresado sea un cuil
 * param string array con la cadena a analizar
 * return 1 si se pudo y 0 si no.
 */
//int esCuil(char str[]);
/*
 * brief Verifica si el valor recibido contiene letras y numeros
 * param str Array con la cadena a analizar
 * return 1 si son letras y numeros o 0 si no lo son
 */
int isAlphanumeric(char str[]);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/*
* \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero minimo a ser aceptado
* \param maximo Es el numero maximo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*
*/
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

/*
 * brief Solicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param imput Array donde se guarda lo ingresado
 * return 1 si el texto contiene numeros y 0 si no
 *
 */
int getStringNum(char message[], char input[]);
/*
 * brief Inicializa un array de enteros	con el valor recibido
 * param array Es el Array a ser inicializado
 * param cantidad_de_elementos indica longitud de array
 * param valor Es el valor que será cargado en cada posiciones
 * return -
 */
void initArrayInt(int array[], int size, int value);

/*
 * brief Pide por mensaje que se ingrese un número y valida que sea flotante
 * param mensaje, mensaje a usuario solicitando ingreso de dato
 * return número flotante
 */

float isFloat(char* message);

/*
 * brief valida número flotante
 * param buffer, cadena de caracteres a validar
 * return 1 la cadena tiene numeros y ",  ." o -1 en caso de tener letras o signo negativo
 */

int validFloatNumber(char* buffer);

/*
 * brief valida numero entero
 * param mensaje, mensaje al usuario solicitando ingrese un número
 * return número entero validado
 */

int validInt(char* message);
/*
 * brief Solicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param error, mensaje de error a ser mostrado
 * param input Array donde se guardará lo ingresado
 * return 1 si el texto contiene solo letras y 0 si no
 */
int getStringLetters(char* msg,char* msgErr,char* pBuffer);
/*
 * brief Verifica si el valor recibido contiene solo letras
 * param str Array con la cadena a analizar
 * return 1 si son solo letras o 0 si no lo son
 */
int onlyLetters(char str[]);
/*
 * brief soslicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param input es Array donde se cargara lo ingresado
 * return void
 */
void getString(char msg[],char* pBuffer);

/*
 * breif solicita confirmación para continuar
 * 		1 - Si // 2 - No
 * param void
 * 	return 1 o 2
 */

int validConfir(void);

/*
 * breif pide al usuario cargue cuit
 * param cuit, puntero donde se cargan los datos ingresados
 * return void
 */
void getCuil(char *cuil);
/*
 * brief solicita un nombre al usuario
 * param pName, puntero al nombre
 * tam, tamaño del array
 * return void
 */
void getName(char pName[], int size);
/*
 * brief solicita un apellido al usuario
 * param pName, puntero al nombre
 * tam, tamaño del array
 * return void
 */
void getLastName(char* pLastName[], int size);
/*
 * brief solicita al usuario un horario
 * param sche, puntero al horario
 * return void
 */
void getSchedule(char *sche);

#endif /* UTN_H_ */
