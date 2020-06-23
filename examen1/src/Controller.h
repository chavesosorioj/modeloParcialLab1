/** \brief Load the data from the file data.csv (text mode).
 * param path char*                                - Direction / Name where the data is load.
 * param pArrayListEmployee LinkedList*            - List where data is load.
 * 	return - -1 NULL
 * 	        or the data
 */
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArray);
/** \brief Load the data from the file data.csv (bin mode).
 *
 * \param path char*                                - Direction / Name where the data is load.
 * \param pArray LinkedList*			            - List where data is load.
 * 	return - -1 NULL
 * 	        0 if its ok
 */
int controller_loadFromBinary(char* path , LinkedList* pArray);
/*
 * breif Adds and element
 * 	param LinkedList* pArray- pointer to the list
 * 	return - -1 NULL
 * 	        0 if its ok
 */
int controller_add(LinkedList *pArray);
/*
 * breif edits and element of the list
 * 	param LinkedList* pArray - pointer to the list
 * 	return - -1 NULL
 * 	        0 ok
 */
int controller_edit(LinkedList *pArray);
/*
 * breif removes one element of the list
 * 	param LinkedList* pArray - pointer to the list
 * 	return - -1 NULL
 * 	        0 ok
 */
int controller_remove(LinkedList *pArray);
/*
 * breif list data
 * 	param LinkedList* pArray- pointer to the list
 * 	return - -1 NULL
 * 	         0 ok
 */
int controller_List(LinkedList* pArray);
/** \brief sorts the list as requested by the user
 *
 * \param pArray LinkedList*            - List where the data will be sorted.
 * \return int                                      - (-1) NULL // (0) Employee sorted.
 *
 */
int controller_sort(LinkedList *pArray);
/** \brief Saves the data in the file data.csv (text mode).
 *
 * \param path char*                     - Direction / Name where the data is save.
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArray);

/** \brief Saves the data of the employee in the file data.csv (binary mode).
 *
 * \param path char*               - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * breif finds the index of and id
 * 	param LinkedList* pArrayListEmployee - pointer to the list
 * 	param int - id to find
 * 	param int - index that found
 * 	return - -1 NULL
 * 	         0 is it was ok
 */
int controller_findId(LinkedList *pArray, int id, int *index);
int filmProyected(LinkedList *this, int room);
int totalAmount(LinkedList *this, int room);
int totalTickets(LinkedList *this, int room);
/*
 * brief
 * param pArray LinkedList*
 * return -1 NULL
 *         0 OK
 */
int controller_report(LinkedList* pArray);


