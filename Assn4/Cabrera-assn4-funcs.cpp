/**********************************************************************
 FILENAME:          Cabrera-assn4-funcs.cpp
 DESCRIPTION:       Contains the functions definitions
 IMPLEMENTED BY:    Garry Cabrera
 **********************************************************************/

#include "CabreraNevarez-assn4-common.h"
#include "Cabrera-assn4-funcs.h"
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

/**********************************************************************************
 FUNCTION:          InsertionSort
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Sorts an array of numbers using the Insertion sort method
 INPUT:
    Parameters:     list - unordered list array of numbers
 OUTPUT:            Displays total click times = “Insertion sort time 777777…”
    Return:         totalClockTicks - amount of time the algorithm has been running
 **********************************************************************************/
int insertionSort (int list[]) {
    
    int currentIdx,                 // current index in loop
    temp;
    int startTime,                  // starting timer value
    endTime;                        // ending timer value
    
    
    startTime = clock();
    
    for (int sortedTopIdx = 1; sortedTopIdx < LIST_SIZE; sortedTopIdx++) {
        
        currentIdx = sortedTopIdx;
        
        while (currentIdx > 0 && list[currentIdx] < list[currentIdx - 1]) {
            temp = list[currentIdx];
            list[currentIdx] = list[currentIdx - 1];
            list[currentIdx - 1] = temp;
            currentIdx--;
        }
        
    }// end for loop
    
    endTime = clock();
    
    return (endTime - startTime);
}


/**********************************************************************************
 FUNCTION:          MergeSort
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Sorts an array of numbers using the Merge sort method
 INPUT:
    Parameters:     list - unordered list array of numbers
 OUTPUT:            Displays total click times = “Merge sort time 777777…”
    Return:         totalClockTicks - amount of time the algorithm has been running
 CALLS TO:          MergeSortSublist
 **********************************************************************************/
int mergeSort (int list[]) {
    
    return 0;
}

/**********************************************************************************
 FUNCTION:          MergeSortSublist
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Sorts a sublist that will be used in the merge algorithm
 INPUT:
    Parameters:     list - unordered sub-list array of numbers
                    lowIdx - lowest index value in the array
                    highIdx - highest index value in the array
 OUTPUT:
    Return:         list - ordered sublist of numbers
 **********************************************************************************/
void mergeSortList (int subList[]) {
    
}

/**********************************************************************************
 FUNCTION:          ValidateSort
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Validates an array of numbers to make sure that they are in order
 INPUT:
    Parameter:      list - array of numbers to be checked
 OUTPUT:
    Returns:        true if array is sorted correctly, false if not
 **********************************************************************************/
bool validateSort (int list[]) {
    bool isSorted = false;          // true if list is sorted
    int currIdx = 0;                // current index
    
    // loop while the list is sorted and within the list size
    do {
        
        if (list[currIdx] < list[currIdx + 1]) {
            isSorted = true;
            currIdx++;
        }
        else
            isSorted = false;
    
        std::cout << "In index "<<currIdx << " the value is: "<<list[currIdx]<<std::endl;
    } while (isSorted && currIdx < LIST_SIZE - 1);
    
    return isSorted;
}

/**********************************************************************************
 FUNCTION:          DisplayAverages
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Displays the average sort times for each sort method
 INPUT:
    Parameters:     firstResult - array with results of times for first sort method
                    secondResult - array with results of times for second sort method
 OUTPUT:            Averages for each sort
 **********************************************************************************/
void displayAverages (int firstResults[], int secondResults[]) {

}