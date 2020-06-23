#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "sale.h"
#include "parser.h"
#include "utn.h"
#include "menu.h"

int controller_loadFromText(char *path, LinkedList *pArray) {
	int ret = -1;
	FILE *pFile;

	if (path != NULL && pArray != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			parser_FromText(pFile, pArray);
			ret = 0;
		} else {
			printf("file is null\n");
		}
	} else {
		printf("\nThe file doesn't exit");
	}
	if ((fclose(pFile)) == -1) {
		printf("\nThe file could not be closed\n");
	} else {
		printf("\nFile closed successtully\n");
	}
	return ret;
}
/*
int controller_loadFromBinary(char* path , LinkedList* pArray)
{
	int ret	=-1;
	FILE* pFile = fopen(path,"rb");

	if(pFile !=NULL && pArray !=NULL)
	{
		parser_EmployeeFromBinary(pFile, pArray);
		ret=0;
	}
	else
	{
		printf("\nThe file doesn't exit");
	}
	if((fclose(pFile))==-1)
	{
		printf("\nThe file could not be closed");
	}
	else
	{
		printf("\nFile closed successtully\n");
	}
    return ret;
}
*/

int controller_add(LinkedList *pArray) {
	int ret = -1;
	Sale *auxSale;
	int auxId;
	char auxName[51];
	int auxDay;
	char auxSch[10];
	int auxRoom;
	int auxCuantity;
	int auxAmount=0;

	auxSale = sale_new();
	if (pArray != NULL && auxSale!= NULL) {
		printf("\n****Add movie****\n");

		auxId = ll_len(pArray) + 1;
		getName(auxName, TAM_NAME);
		auxDay = validInt("Enter the day of the movie\n 0 Domingo \n 1 Lunes \n 2 Martes \n 3 Miercoles \n 4 Jueves \n 5 Viernes \n 6 Sabado");
		getSchedule(auxSch);
		auxRoom = validInt("Enter the room\n");
		auxCuantity = validInt("Enter numbers of tickets\n");


		sale_setId(auxSale, auxId);
		sale_setName(auxSale, auxName);
		sale_setDay(auxSale, auxDay);
		sale_setSchedule(auxSale, auxSch);
		sale_setRoom(auxSale, auxRoom);
		sale_setCuantity(auxSale, auxRoom);
		sale_setAmount(auxSale, auxAmount); // esta en cero para probar

		printf("\n\tID\tNAME\tDAY\tSCHEDULE\tROOM\tCUANTITY\tAMOUNT");
		printf("\n\t%d\t%s\t%d\t%s\t%d\t%d\t%d", auxId, auxName, auxDay,
				auxSch, auxRoom, auxCuantity, auxAmount);

		ret = 0;
		ll_add(pArray, auxSale);
		printf("\n****Movie registered successfully****\n");
	} else {
		printf("Error while adding movie\n");
		free(auxSale);
	}
	return ret;
}

int controller_findId(LinkedList *pArray, int id, int *index) {
	int ret = -1;
	Sale *auxSale= NULL;
	int lenthg;
	int i;
	int auxId = 1;

	if (pArray != NULL && id > 0) {
		lenthg = ll_len(pArray);
		for (i = 0; i < lenthg; i++) {
			auxSale= ll_get(pArray, i);
			if (auxSale!= NULL) {
				sale_getId(auxSale, &auxId);
				if (id == auxId) {
					*index = i;
					ret = 0;
					break;
				}
			}
			auxId++;
		}
	}
	return ret;
}

int controller_edit(LinkedList *pArray) {
	int ret = -1;
	Sale *auxSale= NULL;
	int auxId, buffer, findId;
	char auxName[51];
	char auxSchedule[10];
	int auxRoom;

	if (pArray != NULL && ll_len(pArray) > 0) {
		printf("\n****EDIT****\n");
		auxId = validInt("\nEnter de ID\n");
		findId = controller_findId(pArray, auxId, &buffer);
		if (findId == -1) {
			printf("\n**Error, the ID wasn't found**\n");
			free(auxSale);
		} else {
			auxSale = ll_get(pArray, buffer);
			if (auxSale != NULL) {
				printf("ID: %d - Name: %s \n", auxSale->id,
						auxSale->name);
				switch (menuOne()) {
				case 1:
					printf("\n**Change name**\n");
					getName(auxName, TAM_NAME);
					sale_setName(auxSale, auxName);
					ret = 0;
					printf("\n The change was succesfulled\n");
					break;
				case 2:
					printf("\n**Change Schedule**\n");
					getSchedule(auxSchedule);
					sale_setSchedule(auxSale, auxSchedule);
					ret = 0;
					printf("\n\tThe change was succesfulled\t\n");
					break;
				case 3:
					printf("\nChange room\n");
					auxRoom = validInt(
							"\nEnter the new room");
					sale_setRoom(auxSale, auxRoom);
					ret = 0;
					printf("\n\tThe change was succesfulled\t\n");
					break;
				case 4:
					printf("\n**Edit was cancelled**");
					break;
				}
			}
		}
	} else {
		printf("Error\n");
	}
	return ret;
}

int controller_remove(LinkedList *pArray) {
	Sale *auxSale = NULL;
	int ret = -1;
	int auxId, findId, buffer;

	if (pArray != NULL) {
		printf("\n****REMOVE****\n");
		auxId = validInt("\nEnter de ID\n");
		findId = controller_findId(pArray, auxId, &buffer);
		if (findId == -1) {
			printf("\n**Error, the ID wasn't found**\n");
			free(auxSale);
		} else {
			auxSale = ll_get(pArray, buffer);
			printf("ID: %d - Name: %s", auxSale->id, auxSale->name);
			if (validConfir() == 2) {
				printf("\n**Remove was cancel**\n");
			} else {
				auxSale = ll_pop(pArray, buffer);
				if (auxSale != NULL) {
					sale_delete(auxSale);
					printf("\n**Delete successfull**\n");
					ret = 0;
				}
			}
		}
	}
	return ret;
}

int controller_List(LinkedList *pArray) {
	Sale *bufferStuct = NULL;
	int i;
	int auxId;
	char auxName[TAM_NAME];
	char auxDay[15];
	char auxSchedule[10];
	int auxRoom;
	int auxcuantity;
	int auxAmount;
	int ret = -1;

	if (pArray != NULL) {

		if (ll_len(pArray) == 0) {
			printf("The list is empty\n");
			free(bufferStuct);
		} else {
			printf("\n\tID\tNAME\tDAY\tSCHEDULE\tROOM\tCUANTITY\tAMOUNT");
			for (i = 0; i < ll_len(pArray); i++) {
				bufferStuct = ll_get(pArray, i);
				if (bufferStuct != NULL) {
					if (!sale_getId(bufferStuct, &auxId)
							&& !sale_getName(bufferStuct, auxName)
							&& !sale_getDay(bufferStuct, auxDay)
							&& !sale_getSchedule(bufferStuct, auxSchedule)
							&& !sale_getRoom(bufferStuct, &auxRoom)
							&& !sale_getCuantity(bufferStuct, &auxcuantity)
							&& !sale_getAmount(bufferStuct, &auxAmount)) {

						printf("\n\t%d\t\t%s\t%s\t\t%s\t%d\t%d\t%d", auxId, auxName, auxDay,
								auxSchedule, auxRoom, auxcuantity, auxAmount);
						ret = 0;
					}
				}
			}
		}
	}
	return ret;
}



int controller_sort(LinkedList *pArray) {
	int ret = -1;

	if (pArray != NULL) {
		switch (menuTwo()) {
		case 1:
			ll_sort(pArray, sale_orderByName, 1);
			break;
		case 2:
			ll_sort(pArray, sale_orderByName, 0);
			break;
		case 3:
			ll_sort(pArray, sale_orderById, 1);
			break;
		case 4:
			ll_sort(pArray, sale_orderById, 0);
			break;
		}
		ret = 0;
	}
	return ret;
}
int filmProyected(LinkedList* this, int room) {
	int ret = -1;
	Sale *auxS = NULL;
	int cont;
	int len;
	int i;
	if (this != NULL) {
		printf("\n  Films proyected:\n");
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			auxS = ll_get(this, i);
			if (auxS != NULL) {
				if (auxS->room == room) {
					printf("\n\t%s\n", auxS->name);
					cont++;
					ret = 0;
				}
			}
		}
		if (cont == len) {
			printf("\nThere were no films proyected in that room");
			ret = 0;
		}
	}
	return ret;
}

int totalAmount(LinkedList *this, int room) {
	int ret = -1;
	Sale *auxS = NULL;
	int money = 0;
	int amount;
	int len;
	int i;
	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			auxS = ll_get(this, i);
			if (auxS != NULL) {
				if (auxS->room == room) {
					sale_getAmount(auxS, &amount);
					money += amount;
					ret = 0;
				}
			}
		}
		printf("\n Full amount billed: %d\n", money);
	}

	return ret;
}

int totalTickets(LinkedList *this, int room) {
	int ret = -1;
	Sale *auxS = NULL;
	int total = 0;
	int cuantity;
	int len;
	int i;
	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			auxS = ll_get(this, i);
			if (auxS != NULL) {
				if (auxS->room == room) {
					sale_getCuantity(auxS, &cuantity);
					total += cuantity;
					ret = 0;
				}
			}
		}
		printf("\n Total tickets sold: %d\n", total);
	}

	return ret;
}

int controller_report(LinkedList *pArray) {
	int ret = -1;
	int option;

	option = menuFour();
	if (!totalAmount(pArray, option) && !filmProyected(pArray, option)
			&& !totalTickets(pArray, option))
		ret = 0;

	return ret;
}

int controller_saveAsText(char *path, LinkedList *pArray) {
	int ret = -1;
	Sale *bufferStruct = NULL;
	FILE *pFile = NULL;
	int auxId;
	char auxName[TAM_NAME];
	int auxDay;
	char auxSchedule[10];
	int auxRoom;
	int auxcuantity;
	int auxAmount;
	int length;
	int i;

	if (path != NULL && pArray != NULL) {
		pFile = fopen(path, "w+");
		if (pFile != NULL) {
			length = ll_len(pArray);
			for (i = 0; i < length; i++) {
				bufferStruct = ll_get(pArray, i);
				//fseek(pFile, 0L, SEEK_END);//no estoy segura
				if (!sale_getId(bufferStruct, &auxId)
						&& !sale_getName(bufferStruct, auxName)
						&& !sale_getDayInt(bufferStruct, &auxDay)
						&& !sale_getSchedule(bufferStruct, auxSchedule)
						&& !sale_getRoom(bufferStruct, &auxRoom)
						&& !sale_getCuantity(bufferStruct, &auxcuantity)
						&& !sale_getAmount(bufferStruct, &auxAmount)) {
					fprintf(pFile, "%d,  %s,  %d, %s, %d, %d, %d, \n", auxId,
							auxName, auxDay, auxSchedule, auxRoom, auxcuantity,
							auxAmount);
				} else {
					sale_delete(bufferStruct);
				}
			}
			ret = 0;
			printf("File saved successfully");
			if ((fclose(pFile)) == -1) {
				printf("The file could not be closed");
			} else {
				printf("File closed successtully\n");
				ret = 0;
			}
		} else {
			printf("File doesnt exits");
		}
	}
	return ret;
}


/*
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int ret = -1;
	FILE *pFile = NULL;
	Employee *auxEmployee = NULL;
	int length;
	int i;
	int c;

	if (pArrayListEmployee != NULL && path != NULL) {

		pFile = fopen(path, "w+b");
		if (pFile != NULL) {
			length = ll_len(pArrayListEmployee);
			for (i = 0; i < length; i++) {
				auxEmployee = ll_get(pArrayListEmployee, i);
				if (auxEmployee != NULL) {
					c = fwrite(auxEmployee, sizeof(Employee), 1, pFile);
				}
				if (c != 1) {
					printf("\nError, file could not be written");
					break;
				}
			}
			ret = 0;
		}
		printf("File saved successfully");
		if ((fclose(pFile)) == -1) {
			printf("The file could not be closed");
		} else {
			printf("File closed successtully\n");
		}
	}

	return ret;
}
*/
