//******************************************************************************
// CODE FILENAME:	Nevarezfuncs.cpp
// DESCRIPTION:		This file contains the ADT function definitions for assn 3
// CLASS/TERM:		CS372 14M8W2
// DESIGNER:		Juan Nevarez
// FUNCTIONS:
//******************************************************************************

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "Nevarez-assn4-funcs.h"
#include "CabreraNevarez-assn4-common.h"

using namespace std;

//**************************************************************************
// FUNCTION: createUnsortedList
// DESCRIPTION: creates an array of 5000 unsorted unique numbers
// OUTPUT: Parameter: List1 - list of random numbers
//                  : List2 - list of random numbers
// IMPLEMENTED BY: Juan Nevarez
//**************************************************************************
void createUnsortedList(int list1[], int list2[])
{
	srand(time(0));
    
	for(int idx = 0; idx < LIST_SIZE; idx++)
	{
		list1[idx] = list2[idx] = (rand() % MAX_INTEGER) + 1;
        
	}
}//end cretaeUnsorteList func
//**************************************************************************
// FUNCTION: displayMenu
// DESCRIPTION:
// OUTPUT: Parameter:
// IMPLEMENTED BY: Juan Nevarez
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
// IMPLEMENTED BY: Juan Nevarez
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
//**************************************************************************
// FUNCTION: bubbleSort
// DESCRIPTION:
// OUTPUT:
// IMPLEMENTED BY: Juan Nevarez
//**************************************************************************
int bubbleSort(int list[])
{
	int startTime,
    endTime;
    
	int	elapsedTime,
    swap;
    
	
	startTime = clock();
	
	for(int iteration = 1; iteration < LIST_SIZE; iteration ++)
	{
		for(int index = 0; index < LIST_SIZE-iteration; index++)
		{
			if(list[index] > list[index + 1])
			{
				swap = list[index];
				list[index] = list[index + 1];
				list[index + 1] = swap;
			}//ends if statement
            
		}//end inner loop
        
	}//end first for loop
	
	endTime = clock();
	
	elapsedTime = endTime - startTime;
    
	cout << setw(19) << right << sortsStr[BUBBLE] << " time " << elapsedTime << endl;
	
	return  elapsedTime;
    
}//ends void
//**************************************************************************
// FUNCTION: quickSort
// DESCRIPTION:
// OUTPUT:
// IMPLEMENTED BY: Juan Nevarez
//**************************************************************************
int quickSort(int list[])
{
	int endTime,
    startTime,
    elapsedTime;
    
	startTime = clock();
    
	quickRecurs(list, 0, LIST_SIZE -1);
    
	endTime = clock();
	
	elapsedTime = endTime - startTime;
    
	cout << setw(19) << right << sortsStr[QUICK] << " time " << elapsedTime << endl;
	
	return elapsedTime;
    
}//end quickSort
//**************************************************************************
// FUNCTION: quickRecurs
// DESCRIPTION:
// OUTPUT:
// IMPLEMENTED BY: Juan Nevarez
//**************************************************************************
void quickRecurs(int list[],int lowIdx, int highIdx)
{
	int pivot;
    
	if(lowIdx < highIdx)//base case is lowIdx >= highIdx
	{
		pivot = partition(list, lowIdx, highIdx);
		
		quickRecurs(list, lowIdx, pivot - 1);
		
		quickRecurs(list, pivot + 1, highIdx);
	}
}//end quickRecurs func
//**************************************************************************
// FUNCTION: partition
// DESCRIPTION:
// OUTPUT:
// IMPLEMENTED BY: Juan Nevarez
//**************************************************************************
int partition(int list[],int low, int  high)
{
    int pivot = low,
    left = low + 1,
    right = high,
    nbrSwap = 0;
    
    while(left < right)
    {
        while(list[left] <= list[pivot] && left < right)
        {
            left++;
        }
        while(list[right] > list[pivot])
        {
            right--;
        }
        if(left < right)
        {
            nbrSwap = list[left];//variable to store number from left for the swap
            list[left] = list[right];//moves right into left index
            list[right] = nbrSwap;//stores number in swap to right
        }
    }    
    nbrSwap = list[right];
    list[right] = list[pivot];
    list[pivot] = nbrSwap;
    
    return right;
    
}//end partition funcs
