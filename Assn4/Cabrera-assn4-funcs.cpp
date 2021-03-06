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
int insertionSort (int list[])
{    
    int remainTopIdx;               // top index
    int lastIdx;                    // last index
    int currentIdx;                 // current index in the loop
    int inserValue;                 // value to be swaped
    int startTime,                  // starting timer value
    endTime,                        // ending timer value
    elapsedTime;                    // total time sorting
    
    remainTopIdx = 1;
    lastIdx = LIST_SIZE - 1;
    
    startTime = clock();
    
    while (remainTopIdx <= lastIdx) {
        inserValue = list[remainTopIdx];
        currentIdx = remainTopIdx - 1;
        
        while ((currentIdx >= 0) && (inserValue < list[currentIdx])) {
            list[currentIdx + 1] = list[currentIdx];
            currentIdx--;
        }
        
        list[currentIdx + 1] = inserValue;
        remainTopIdx++;
    }
    
    endTime = clock();
    
    elapsedTime = endTime - startTime;
        
    return elapsedTime;
}// end insertionSort

/**********************************************************************************
 FUNCTION:          ValidateSort
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Validates an array of numbers to make sure that they are in order
 INPUT:
    Parameter:      list - array of numbers to be checked
 OUTPUT:
    Returns:        true if array is sorted correctly, false if not
 **********************************************************************************/
bool validateSort (int list[])
{
    bool isSorted = false;          // true if list is sorted
    int currIdx = 0;                // current index
    
    // loop while the list is sorted and within the list size
    do {
        
        if (list[currIdx] <= list[currIdx + 1]) {
            isSorted = true;
            currIdx++;
        }
        else
            isSorted = false;
    
    } while (isSorted && currIdx < LIST_SIZE - 1);
    
    return isSorted;
}// end validateSort

/**********************************************************************************
 FUNCTION:          mergeSort
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Sorts an array of numbers using the Merge sort method
 INPUT:
    Parameters:     list - unordered list array of numbers
 OUTPUT:            Displays total click times = “Merge sort time 777777…”
    Return:         totalClockTicks - amount of time the algorithm has been running
 CALLS TO:          mergeSortRecurs
 **********************************************************************************/
int mergeSort (int list[])
{
    
    int startTime;                      // starting timer value
    int endTime;                        // ending timer value
    int elapsedTime;                    // total time sorting
    
    startTime = clock();
    mergeSortRecurs(list, 0, LIST_SIZE - 1);
    endTime = clock();

    elapsedTime = endTime -startTime;
    
    return elapsedTime;
}// end mergeSort

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
 CALLS TO:          merge
 **********************************************************************************/
void mergeSortRecurs (int list[], int lowIdx, int highIdx)
{
    int midIdx;                        // middle index
    
    if (lowIdx < highIdx)
    {
        midIdx = (lowIdx + highIdx) / 2;
        mergeSortRecurs(list, lowIdx, midIdx);
        mergeSortRecurs(list, midIdx + 1, highIdx);
        
        merge(list, lowIdx, midIdx, highIdx);
    }
    
}// end mergeSortRecurs

/**********************************************************************************
 FUNCTION:          merge
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Merges two ordered lists and combines them into a single ordered
                    list.
 INPUT:
    Parameters:     list - array of numbers
                    lowIdx - lowest index value in the array
                    midIdx - middle index value in the array
                    highIdx - highest index value in the array
 OUTPUT:
    Return:         list - ordered list of numbers
 **********************************************************************************/
void merge (int list[], int lowIdx, int midIdx, int highIdx)
{
    int leftIdx;                        // left most element
    int rightIdx;                       // right most element
    int tempPos;                        // used to swap the values
    static int tempList[LIST_SIZE];     // temp list used to sort the array
    
    leftIdx = lowIdx;
    rightIdx = midIdx + 1;
    tempPos = lowIdx;
    
    // copy values from the current part of array being merged
    for (int i = lowIdx; i <= highIdx; i++)
        tempList[i] = list[i];
    
    while ((leftIdx <= midIdx) && (rightIdx <= highIdx))
    {
        if (tempList[leftIdx] <= tempList[rightIdx])
        {
            list[tempPos] = tempList[leftIdx];
            leftIdx++;
        }
        else
        {
            list[tempPos] = tempList[rightIdx];
            rightIdx++;
        }
        
        tempPos++;
    }// end while
    
    // loop while additional elements are on the left side
    while (leftIdx <= midIdx) {
        list[tempPos] = tempList[leftIdx];
        tempPos++;
        leftIdx++;
    }// end while
    
    // loop while additional elements are on the right side
    while (rightIdx <= highIdx) {
        list[tempPos] = tempList[rightIdx];
        tempPos++;
        rightIdx++;
    }// end while

}// end merge

/**********************************************************************************
 FUNCTION:          getFuncTypeIndex
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Returns the enumerated sort function entered by user
 INPUT:
    Parameters:     ch - sort function user entered
 OUTPUT:
    Return:         index - enumerated type index
 **********************************************************************************/
int getFuncTypeIndex (char ch)
{
    int index = 0;          // function pointer array index
    
    switch (ch)
    {
        case 'B':
            index = BUBBLE;
            break;
        case 'I':
            index = INSERTION;
            break;
        case 'M':
            index = MERGE;
            break;
        case 'Q':
            index = QUICK;
            break;
    }
    return index;
}// end getFuncTypeIndex

/**********************************************************************************
 FUNCTION:          getAvg
 IMPLEMENTED BY:	Garry Cabrera
 DESCRIPTION:       Returns the average clock ticks
 INPUT:
    Parameters:     list - array with results
                    size - size of the results array
 OUTPUT:
    Return:         average clock ticks
 **********************************************************************************/
double getAvg (int list[], int size)
{
    double avg;                 // average clock ticks
    int idx;                    // loop index
    
    for (idx = 0; idx < size; idx++) {
        avg += (double)list[idx];
    }
    
    return (avg / (double)size);
}

