//******************************************************************************
// CODE FILENAME:	Nevarezfuncs.cpp
// DESCRIPTION:		This file contains the ADT function definitions for assn 3
// CLASS/TERM:		CS372 14M8W2
// DESIGNER:		Juan Nevarez
// FUNCTIONS:		
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Nevarez-assn4-funcs.h"
#include "CabreraNevarez-assn4-common.h"

using namespace std;

//**************************************************************************
// FUNCTION: CreateUnsortedList
// DESCRIPTION: creates an array of 5000 unsorted unique numbers
// OUTPUT: Parameter: unsortedList - list of random unique numbers 
// IMPLEMENTED BY: Juan Navarez
//**************************************************************************
void CreateUnsortedList (int unsortedList1[], int unsortedList2[])    
{   
	int num,	 			// variable to store the number in
               
	srand( (unsigned)time(NULL) );      // seed random number generator
   
	for (int idx = 0; idx < LIST_SIZE; idx++)	  // Create list
	{
    
		num = (rand() % MAX_INTEGER) + 1; //generates random number between 1 and MAX_NUM
   
       
		unsortedList1[idx] = num;	//store the num value into the array
        unsortedList2[idx] = num;      

	}//ends for loop
	
}
//**************************************************************************
// FUNCTION: displayMenu
// DESCRIPTION: 
// OUTPUT: Parameter: 
// IMPLEMENTED BY: Juan Navarez
//**************************************************************************
void displayMenu()
{
	cout << "Choose two sorts you wish to compare: " << endl;
	cout << right << setw(23) << "B = Bubble sort" << endl;
	cout << right << setw(26) << "I = Insertion sort" << endl;
	cout << right << setw(22) << "M = Merge sort" << endl;
	cout << right << setw(22) << "Q = Quick sort" << endl;
	cout << right << setw(24) << "E = Exit Program" << endl;
}
//**************************************************************************
// FUNCTION: getInput
// DESCRIPTION: 
// OUTPUT: 
// IMPLEMENTED BY: Juan Navarez
//**************************************************************************
void getInput(char &firstSort, char &secondSort, int &repeat)
{
	
	cout << "\nEnter two letter choices (or EE to exit): ";
	
	cin >> firstSort >> secondSort;
	
	firstSort = toupper(firstSort);
	
	secondSort = toupper(secondSort);

	cout << endl << endl;

	if(firstSort != 'E')
	{
		do{
		
			cout << "Enter the number of times to repeat each sort (1 or more): ";
			cin >> repeat; 
			if(repeat < 1)
			 cout << "The sort minium is 1 " << endl;		
		
		}while(repeat < 1);
		
	}
	else
	{
		repeat = -1;
	}	
	
}

int bubbleSort(int list[]){return 0;}


int quickSort(int list[])
{
	int startTime,
    elapsedTime,
    endTime;
	
	startTime = clock()	;
	
	quickRecurs (list, 0, LIST_SIZE-1);
	
	endTime = clock();
	
	elapsedTime = endTime - startTime;
	
	return elapsedTime;
}
void quickRecurs(int list[], int lowIdx, int highIdx)
{
	int pivot;
    
	if(lowIdx < highIdx)
	{
		
		pivot = partition(list, lowIdx, highIdx);
        
		quickRecurs (list, lowIdx, pivot -1);
        
		quickRecurs (list, pivot + 1, highIdx);
	}
	
	
}//end quickRecurs function
int partition(int list[],int low, int high)
{
    
	int pivot = low,
    left = low + 1,
    nbrSwap = 0,
    right = high;
    
    
    while(list[left] < list[pivot])
    {
        left++;
    }
    
    while(list[right] > list[pivot])
    {
        right--;
    }
    
    if(left < right)
    {
        
        nbrSwap = list[left];
        list[left] = list[right];
        list[right] = nbrSwap;
        
    }
        

	
	nbrSwap = list[right];
	list[right] = list[pivot];
	list[pivot] = nbrSwap;
	
	
	return right;
}
