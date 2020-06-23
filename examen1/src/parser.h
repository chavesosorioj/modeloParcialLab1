/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* - file to open
 * \param pArray LinkedList*
 * \return 1 - null
 *         0 - OK
 */
int parser_FromText(FILE* pFile , LinkedList* pArray);
int parser_FromBinary(FILE *pFile, LinkedList *pArray);
