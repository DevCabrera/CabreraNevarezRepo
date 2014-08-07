//******************************************************************************
// CODE FILENAME:	Nevarezfuncs.h
// DESCRIPTION:		The file contains the ADT function prototypes for assn 3 
// CLASS/TERM:		CS372 14M8W2
// DESIGNER:		Juan Nevarez	
//******************************************************************************

void CreateUnsortedList (int unsortedList1[], int unsortedList2[]);
void displayMenu();
void getInput(char &firstSort, char &secondSort, int &repeat);


int bubbleSort(int list[]);
int quickSort(int list[]);
int partition(int list[],int low, int high);
void quickRecurs(int list[], int lowIdx, int highIdx);
