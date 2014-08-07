/**********************************************************************
 FILENAME:          Cabrera-assn4-funcs.h
 DESCRIPTION:       Contains the functions prototypes
 IMPLEMENTED BY:    Garry Cabrera
 **********************************************************************/


int insertionSort (int list[]);
int mergeSort (int list[]);
void mergeSortRecurs (int list[], int lowIdx, int highIdx);
void merge (int list[], int lowIdx, int midIdx, int highIdx);
bool validateSort (int list[]);
void displayAverages (int firstResults[], int secondResults[]);
int getFuncTypeIndex (char ch);
