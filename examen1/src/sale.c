/*
 * sale.c
 *
 *  Created on: Jun 18, 2020
 *      Author: juliana
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Controller.h"
#include "LinkedList.h"
#include "sale.h"
#include "utn.h"

Sale* sale_new() {
	Sale *this;

	this = (Sale*)malloc(sizeof(Sale));

	if (this != NULL) {
		sale_setId(this, 0);
		sale_setName(this, " ");
		sale_setDay(this, 0);
		sale_setSchedule(this, " ");
		sale_setRoom(this, 0);
		sale_setCuantity(this, 0);
		sale_setAmount(this, 0);
	}
	else
	{
		sale_delete(this);
		printf("there is no memory\n");
	}
	return this;
}
Sale* sale_newParametros(char *idStr, char *nameStr, char *dayStr,
		char *scheduleStr, char* roomStr, char* cuantityStr, char amountStr) {
	Sale *auxSale;
	Sale* ret=NULL;
	auxSale = sale_new();

	int auxId;
	int auxDay;
	int auxRoom;
	int auxCuantity;
	int auxAmount;

	if (auxSale!= NULL && idStr != NULL && nameStr != NULL
			&& dayStr != NULL && scheduleStr != NULL && roomStr != NULL && cuantityStr != NULL) {

		auxId = atoi(idStr);
		auxDay =atoi(dayStr);
		auxRoom = atoi(roomStr);
		auxCuantity = atoi(cuantityStr);
		auxAmount= atoi(&amountStr);
		if (!sale_setId(auxSale, auxId) && !sale_setName(auxSale, nameStr)
				&& !sale_setDay(auxSale, auxDay)
				&& !sale_setSchedule(auxSale, scheduleStr)
				&& !sale_setRoom(auxSale, auxRoom)
				&& !sale_setCuantity(auxSale, auxCuantity)
				&& !sale_setAmount(auxSale, auxAmount)
				) {
				ret = auxSale;
		} else {
			printf("esta liberando Sale\n");
			sale_delete(auxSale);
		}
	}
	return ret;
}
void sale_delete(Sale *this) {
	if (this != NULL) {
		free(this);
	}
}

int sale_setId(Sale *this, int id) {
	int ret = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}
int sale_getId(Sale *this, int *id) {
	int ret = -1;
	if (this != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}
int sale_setDay(Sale *this, int day) {
	int ret = -1;
	if (this != NULL && day >= 0) {
		this->dayS.iDay = day;
		setDayLetter(this, day);
		ret = 0;
	}
	return ret;
}

int setDayLetter(Sale *this, int day) {
	int ret = -1;
	switch (day) {
	case 0:
		sale_setDayChar(this, "domingo");
		break;
	case 1:
		sale_setDayChar(this, "lunes");
		break;
	case 2:
		sale_setDayChar(this, "martes");
		break;
	case 3:
		sale_setDayChar(this, "miercoles");
		break;
	case 4:
		sale_setDayChar(this, "jueves");
		break;
	case 5:
		sale_setDayChar(this, "viernes");
		break;
	case 6:
		sale_setDayChar(this, "sabado");
		break;
	}
	return ret;
}
int sale_setDayChar(Sale *this, char *day) {
	int ret = -1;
	if (this != NULL && day != NULL) {
		strcpy(this->dayS.cDay, day);
		ret = 0;
	}
	return ret;
}
int sale_getDay(Sale *this, char *day) {
	int ret = -1;
	if (this != NULL) {
		strcpy(day, this->dayS.cDay);
		ret = 0;
	}
	return ret;
}
int sale_getDayInt(Sale *this, int *day) {
	int ret = -1;
	if (this != NULL) {
		*day = this->dayS.iDay;
		ret = 0;
	}
	return ret;
}


int sale_setName(Sale *this, char *name) {
	int ret = -1;
	if (this != NULL && name != NULL) {
		strcpy(this->name, name);
		ret = 0;
	}
	return ret;
}
int sale_getName(Sale *this, char *name) {
	int ret = -1;

	if (this != NULL) {
		strcpy(name, this->name);
		ret = 0;
	}
	return ret;
}

int sale_setSchedule(Sale *this, char *schedule) {
	int ret = -1;
	if (this != NULL && schedule !=NULL) {
		strcpy(this->schedule, schedule);
		ret = 0;
	}
	return ret;
}
int sale_getSchedule(Sale *this, char *schedule) {
	int ret = -1;
	if (this != NULL) {
		strcpy(schedule, this->schedule);
		ret = 0;
	}
	return ret;
}

int sale_setRoom(Sale *this, int room) {
	int ret = -1;
	if (this != NULL && room > 0) {
		this->room = room;
		ret = 0;
	}
	return ret;
}
int sale_getRoom(Sale *this, int *room) {
	int ret = -1;
	if (this != NULL) {
		*room = this->room;
		ret = 0;
	}
	return ret;
}
int sale_setCuantity(Sale *this, int cuantity) {
	int ret = -1;
	if (this != NULL && cuantity > 0) {
		this->cuantity= cuantity;
		ret = 0;
	}
	return ret;
}
int sale_getCuantity(Sale *this, int *cuantity) {
	int ret = -1;
	if (this != NULL) {
		*cuantity = this->cuantity;
		ret = 0;
	}
	return ret;
}
int sale_setAmount(Sale *this, int amount) {
	int ret = -1;
	if (this != NULL && amount >= 0) {
		this->amount = amount;
		ret = 0;
	}
	return ret;
}
int sale_getAmount(Sale *this, int *amount) {
	int ret = -1;
	if (this != NULL) {
		*amount = this->amount;
		ret = 0;
	}
	return ret;
}

int sale_orderByName(void *aux1, void *aux2) {
	int ret = 0;
	Sale *s1 = NULL;
	Sale *s2 = NULL;
	char name1[200];
	char name2[200];
	if (aux1 != NULL && aux2 != NULL) {
		s1 = (Sale*) aux1;
		s2 = (Sale*) aux2;
		sale_getName(s1, name1);
		sale_getName(s2, name2);
		if (strcmp(name1, name2) > 0) {
			ret = 1;
		} else if (strcmp(name1, name2) < 0) {
			ret = -1;
		}
	}
	return ret;
}
int sale_orderById(void *aux1, void *aux2) {
	int ret = 0;
	Sale *s1 = NULL;
	Sale *s2 = NULL;
	int id1;
	int id2;
	if (aux1 != NULL && aux2 != NULL) {
		s1 = (Sale*) aux1;
		s2 = (Sale*) aux2;
		sale_getId(s1, &id1);
		sale_getId(s2, &id2);
		if (id1 > id2) {
			ret = 1;
		} else if (id1 < id2) {
			ret = -1;
		}
	}
	return ret;
}


void* soldMap(void *auxS) {
	Sale *sale = NULL;
	int auxDay;
	int auxCuant;
	int price;
	int auxAmount;
	sale = (Sale*) auxS;
	if (auxS != NULL) {
		sale_getDayInt(auxS, &auxDay);
		sale_getCuantity(auxS, &auxCuant);

		if (auxDay <=1 || auxDay <=3) {
			price = 240;
		} else {
			price = 350;
		}
		if (auxCuant > 3) {
			price -= (price * 0.10);
		}
		auxAmount = price * auxCuant;
		sale_setAmount(sale, auxAmount);
	}
	return auxS;
}
