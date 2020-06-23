/*
 * menu.c
 *
 *  Created on: May 7, 2020
 *      Author: juliana
 */

#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "utn.h"

int menu() {
	int option;
	printf("\n*************************M E N U*************************\n");
	printf("1 - Charge file's data from data.csv (text mode) \n");
	printf("2 - Add Movie\n");
	printf("3 - Modify movie\n");
	printf("4 - Remove movie\n");
	printf("5 - List movie\n");
	printf("6 - Sort movie\n");
	printf("7 - Reports per room");
	printf("8 - Save employee's data in file data.cvs(text mode)\n");
	printf("9	| - Exit\n");

	option = validInt("Option:\n");
	while (option < 0 || option > 10) {
		option = validInt("\nWrong number. try again");
	}
	__fpurge(stdin);

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuOne() {
	int option;
	printf("\n***Enter the number of what you want to change***\n");
	printf("1 - Name\n");
	printf("2 - Schedule\n");
	printf("3 - Room \n");
	printf("4 - Exit\n");
	option = validInt("Option:\n");
	while (option < 0 || option > 4) {
		option = validInt("\nWrong number. Try againg\n");
	}

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuTwo() {
	int option;
	printf("\n***Enter the number of what you want to order****\n");
	printf("\n  1 - Name in ascending order\n");
	printf("\n  2 - Name in descending order\n");
	printf("\n  3 - ID in ascending order\n");
	printf("\n  4 - ID in descending order\n");
	option = validInt("Option:\n");
	__fpurge(stdin);
	while (option < 0 || option > 8) {
		option = validInt("\nWrong number. Try againg\n");
	}
	printf("\nChosen option: %d\n", option);
	return option;
}

int menuThree() {
	int option;

	option = validInt("\n1 - Ascending order- \n2 - Descending order");
	__fpurge(stdin);
	while (option != 1 && option != 2) {
		option = validInt("\nWrong number. Try againg\n");
	}

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuFour() {
	int option;
	printf("\n***Enter the number of the room you want to see the report****\n");
	printf("\n  Number of tickets sold per room\n");
	printf("\n  Total charged\n");
	printf("\n  Films proyected in the room \n");
	option = validInt("Option:\n");
	__fpurge(stdin);
	while (option < 0 || option > 8) {
		option = validInt("\nWrong number. Try againg\n");
	}
	printf("\nChosen option: %d\n", option);
	return option;
}
