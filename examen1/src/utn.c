/*
 * ejerUtn.c
 *
 *  Created on: Apr 14, 2020
 *      Author: juliana
 */
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
 int retorno =-1;
 int bufferInt;
 while(reintentos>=0)
 {
	 printf("%s",mensaje);
	 scanf("%d",&bufferInt);
	 __fpurge(stdin);
	 if(bufferInt >= minimo && bufferInt <= maximo)
	 {
		 *pResultado = bufferInt;
		 retorno=0;
		 break;
	 }
	 else
	 {
		 printf("%s", mensajeError);
		 reintentos--;
	 }

   }

return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

int getInt(char mensaje[])
{
	int aux;
	printf("%s",mensaje);
	scanf("%d",&aux);
	return aux;
}

float getFloat(char mensaje[])
{
	float aux;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;
}

char getChar(char mensaje[])
{
	char aux;
	printf("%s",mensaje);
	__fpurge(stdin);
	scanf("%c",&aux);
	return aux;
}

int getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

float isFloat(char* message)
{
	char buffer[41];
	float value;

	printf("%s",message);
	__fpurge(stdin);
	fgets(buffer,40,stdin);//tenia gets()

	while(validFloatNumber(buffer)==-1)
	{
		printf("\nError, invalid income. Try again ");
		__fpurge(stdin);
		fgets(buffer,40,stdin);

	}

		value =atof(buffer);

	return value;
}

int validFloatNumber(char* buffer)
{
	int ret;
	int i;

	if(buffer != NULL && strlen(buffer) > 0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			if((buffer[i]=='.' || buffer[i]=='.')&& (buffer[i]<'9' || buffer[i]>'0'))
			{
				ret=1;
			}
		}
	}
	else {
		ret = -1;
	}
	return ret;
}

int validInt(char* message)
{
	int num;
	char buffer[40];

	printf("%s",message);
	__fpurge(stdin);
	fgets(buffer,40,stdin);

	while(isNum(buffer)==-1)
	{
		printf("\nError, income in not a number. Try again");
		__fpurge(stdin);
		fgets(buffer,40,stdin);
	}

	num=atoi(buffer);
	return num;
}

int isNum(char* pBuffer)
{
    int i;
    int j;
    int ret=-1;

    j=strlen(pBuffer);

    for(i=0;i<j;i++)
    {
        if (isdigit(pBuffer[i])!=0)
        {
        	ret=0;
        }
    }
    return ret;
}
int isPhone(char str[])
{	int i=0;
	int hyphen=0;
	while(str[i] != '\0')
	{
		 if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		if(str[i]== '-')
		{
			hyphen++;
		}
		i++;
	}
	if(hyphen==1)
		return 1;

	return 0;
}

int isAlphanumeric(char str[])
{	int i=0;
	while(str[i] != '\0')
	{
		  if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		i++;
	}
	return 1;
}

int getStringNum(char message[], char input[])
{
		char aux[256];
		getString(message, aux);
		if(isNum(aux))
		{
			strcpy(input, aux);
			return 1;
		}
		return 0;
}

void initArrayInt(int array[], int size, int value)
{
	int i;
	for(i=0; i<size;i++)
	{
		array[i]=value;
	}
}

int getStringLetters(char* msg,char* msgErr,char* pBuffer)
{
    char aux[51];
    int ret=-1;
    do{
        getString(msg,aux);
        if(onlyLetters(aux))
        {
            strcpy(pBuffer,aux);
            ret=0;
            break;
        }
     msg=msgErr;
    }while(ret!=0);
    return ret;
}

int onlyLetters(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
    //gets(pBuffer);
}

int validConfir(void)
{
	int val;


	val =validInt("\nDo yo want to continue?:\n1 - Yes\n2 - No\n");
	while(val!= 1 && val!= 2)
	{
			printf("Error. Invalid income\n 1 - Yes\n2 - No");
			__fpurge(stdin);
			scanf("%d",&val);
	}
	return val;
}
void getCuil(char *cuil) {
	int bufferOne;
	int bufferTwo;
	int bufferThree;
	char auxBufferOne[10];
	char auxBufferTwo[10];
	char auxBufferThree[10];
	char buffer[1000];

	//system("clear");
	printf("\n Formato de cuil: XX-XXXXXXXX-X");

	bufferOne = validInt(
			"\nEnter the first two numbers. [20-23-24-27 // 30-33-34]\n");
	while (bufferOne != 20 && bufferOne != 23 && bufferOne != 24
			&& bufferOne != 27 && bufferOne != 30 && bufferOne != 33
			&& bufferOne != 34) {
		bufferOne = validInt(
				"\nInvalid income. Try again. [20-23-24-27 // 30-33-34]\n");
	}
	//system("clear");
	bufferTwo = validInt("\nIngrese el número de DNI o numero de sociedad\n");
	while (bufferTwo < 1000000 || bufferTwo > 100000000) {
		bufferTwo = validInt("\nInvalid income. Try again.\n");
	}
	bufferThree = validInt("\nEnter last digit.");
	while (bufferThree < 0 || bufferThree > 10) {
		bufferThree = validInt("\nError. It must be one digit");
	}

	sprintf(auxBufferOne, "%d", bufferOne);
	sprintf(auxBufferTwo, "%d", bufferTwo);
	sprintf(auxBufferThree, "%d", bufferThree);

	strcpy(buffer, auxBufferOne);
	strcat(buffer, "-");
	strcat(buffer, auxBufferTwo);
	strcat(buffer, "-");
	strcat(buffer, auxBufferThree);

	strcpy(cuil, buffer);

	printf("\nThe cuil is %s", buffer);
	printf("\n\tCuit successfully loaded\t\n");
	//system("clear");
}

void getName(char pName[], int size) {
	char buffer[1000];
	int maxChars = size;
	int ret = -1;
	int i;

	do {
		getStringLetters("\nEnter name\n",
				"\nError, what is entered are not letters", buffer);
		fflush(stdin);

		while (strlen(buffer) > maxChars || strlen(buffer) < 2) {
			system("clear");
			getStringLetters(
					"\nError. The name must have at least two caracthers. Try again.\n",
					"\nError, what is entered are not letters", buffer);
		}

		for (i = 0; buffer[i] != '\0'; i++) {
			buffer[i] = tolower(buffer[i]);
		}
		strcpy(pName, buffer);
		ret = 1;
	} while (ret != 1);
}

void getSchedule(char *sche) {
	int bufferOne;
	int bufferTwo;
	char auxBufferOne[10];
	char auxBufferTwo[10];
	char buffer[1000];

		bufferOne = validInt("Enter the hour\n");
		while(bufferOne<0 ||bufferOne>24)
		{
			bufferOne= validInt("Invalid income. Try again.\n");
		}
		//system("clear");
		bufferTwo = validInt("Enter the minutes\n");
		while(bufferTwo<0 || bufferTwo>59)
		{
			bufferTwo = validInt("\nInvalid income. Try again.\n");
		}

		sprintf(auxBufferOne,"%d",bufferOne);
		sprintf(auxBufferTwo,"%d",bufferTwo);

		strcpy(buffer,auxBufferOne);
		strcat(buffer,":");
		strcat(buffer,auxBufferTwo);

		strcpy(sche, buffer);

		printf("\nThe schedule is %s",buffer);
	printf("\n\tSchedule successfully loaded\t\n");
}

void getLastName(char *pLastName[], int size) {
	char buffer[1000];
	int maxChars = size;
	int ret = -1;
	int i;

	do {
		getStringLetters("\nEnter last name\n",
				"\nError, what is entered are not letters", buffer);
		fflush(stdin);

		while (strlen(buffer) > maxChars || strlen(buffer) < 2) {
			system("clear");
			getStringLetters(
					"\nError. The last name must have at least two caracthers. Try again.\n",
					"\nError, what is entered are not letters", buffer);
		}

		for (i = 0; buffer[i] != '\0'; i++) {
			buffer[i] = tolower(buffer[i]);
		}
		*pLastName = buffer;
		ret = 1;
	} while (ret != 1);
}
