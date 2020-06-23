/*
 * sale.h
 *
 *  Created on: Jun 18, 2020
 *      Author: juliana
 */

#ifndef SALE_H_
#define SALE_H_
#define TAM_NAME 50
typedef struct{
	int iDay;
	char cDay[15];
}eDay;

typedef struct {
	int id;
	char name[50];
	eDay dayS;
	char schedule[10];
	int room;
	int cuantity;
	int amount;
} Sale;
#include "LinkedList.h"

Sale* sale_new();
Sale* sale_newParametros(char *idStr, char *nameStr, char *dayStr,
		char *scheduleStr, char *roomStr, char *cuantityStr, char amount);
void sale_delete(Sale *this);
int sale_setId(Sale *this, int id);
int sale_getId(Sale *this, int *id);
int sale_setName(Sale *this, char *name);
int sale_getName(Sale *this, char *name);
int sale_setSchedule(Sale *this, char *schedule);
int sale_getSchedule(Sale *this, char *schedule);
int sale_setRoom(Sale *this, int room);
int sale_getRoom(Sale *this, int *room);
int sale_setCuantity(Sale *this, int cuantity);
int sale_getCuantity(Sale *this, int *cuantity);
int sale_setAmount(Sale *this, int amount);
int sale_getAmount(Sale *this, int *amount);
int sale_setDay(Sale *this, int day);
int setDayLetter(Sale* this, int day);
int sale_setDayChar(Sale *this, char *day);
int sale_getDay(Sale *this, char *day);
int sale_getDayInt(Sale *this, int *day);
int sale_orderByName(void *aux1, void *aux2);
int sale_orderById(void *aux1, void *aux2);
void* soldMap(void *auxS);
#endif /* SALE_H_ */
