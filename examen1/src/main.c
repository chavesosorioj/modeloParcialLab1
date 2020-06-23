/*
 ============================================================================
 Name        : practicaExamen1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "sale.h"
#include "menu.h"
#define MOVIE "data.csv"


int main(void) {

	LinkedList* movieList = ll_newLinkedList();
	LinkedList* moviesAmount=NULL;
	int cont;

	do {
		cont = menu();
		switch (cont) {
		case 1:
			if(!controller_loadFromText(MOVIE, movieList))
			{
				moviesAmount=ll_map(movieList, soldMap);
			}
			break;
		case 2:
			controller_add(moviesAmount);
			break;
		case 3:
			controller_edit(moviesAmount);
			break;
		case 4:
			controller_remove(moviesAmount);
			break;
		case 5:
			controller_List(moviesAmount);
			break;
		case 6:
			controller_sort(moviesAmount);
			break;
		case 7:
			controller_report(moviesAmount);
			break;
		case 8:
			controller_saveAsText(MOVIE, moviesAmount);
			break;
		case 9:
			ll_deleteLinkedList(movieList);
			ll_deleteLinkedList(moviesAmount);
			break;
		}
	} while (cont != 8);

	return EXIT_SUCCESS;
}
