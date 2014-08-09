/**********************************************************************
 FILENAME:      CabreraNevarez-Assn4-main.cpp
 DESCRIPTION:   This program takes 100,000 unsorted numbers and sorts 
                them using the bubble, insertion, merge, and quick sort
                algorithms. It displays the total clock times it took
                for each sort.
 CLASS/TERM:    CS372 / Summer 2nd term
 DESIGNERS:     Garry Cabrera and Juan Nevarez
 FUNCTIONS:     displayMenu - displays the option menu
                getInput - obtains the user choice of which sort 
                algorithm to use and how many times to repeat
                getFunctionTypeIndex - returns the index of sort to be
                used
                createUnsortedList - returns an array of unsorted numbers
                validateSort - determines if an array is sorted
                getAvg - returns the average clock clicks from a sort
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "Cabrera-assn4-funcs.h"
#include "CabreraNevarez-assn4-common.h"
#include "Nevarez-assn4-funcs.h"

using namespace std;


// Array of pointers for the sorting prototypes
const funcPtrType funcPtrArray[NUM_SORT_FUNCS] = {
    &bubbleSort,
    &insertionSort,
    &mergeSort,
    &quickSort
};

/**********************************************************************
 FILENAME:      CabreraNevarez-Assn4-main.cpp
 DESCRIPTION:   Controls the overall execution of the program
 CALLS TO:      displayMenu, getInput, getFuncTypeIndex, 
                createUnsortedList, validateSort, getAvg
 IMPLEMENTED BY:Garry Cabrera
 **********************************************************************/
int main()
{
    funcPtrType funcPtr;                // pointer to sort function chosen by user
    string ch;                          // used to pause the screen
    int *firstResults;                  // first results array
    int *secondResults;                 // second results array
    char firstSort;                     // first sort function user will choose
    char secondSort;                    // second sort function user will choose
    int sortsCount;                     // number of times sorts will be repeated
    int resultsIdx;                     // index where results will be stored in results arrays
    int list1[LIST_SIZE];               // first list array to be sorted
    int list2[LIST_SIZE];               // second list array to be sorted
    int firstSortType;                  // first sort enum value being used
    int secondSortType;                 // second sort enum value being used
    
    // initial menu display and user input
    displayMenu();
    getInput(firstSort, secondSort, sortsCount);
    
    
    // loop while user doesn't choose EE to exit
    while (firstSort != 'E')
    {
        resultsIdx = 0;

        firstSortType = getFuncTypeIndex(firstSort);
        secondSortType = getFuncTypeIndex(secondSort);
        
        // initialize the results arrays
        firstResults = new int[sortsCount];
        secondResults = new int[sortsCount];
        
        // display error message if unable to allocate memory for results array
        if (firstResults == NULL || secondResults == NULL)
            cout << "\nUnable to allocate memory for the results array. Exiting program...\n";
        
        // loop number of reps and while list are correctly sorted
        do
        {
            createUnsortedList(list1, list2);
            
            cout << "\nStarting sort #" << resultsIdx + 1 << "...\n";
            // call first sort function
            funcPtr = funcPtrArray[firstSortType];
            firstResults[resultsIdx] = funcPtr(list1);
            
            cout << setw(19) << right << sortsStr[firstSortType] << " time "
                 << firstResults[resultsIdx] << endl;

            // call second sort function
            funcPtr = funcPtrArray[secondSortType];
            secondResults[resultsIdx] = funcPtr(list2);
            
            cout << setw(19) << right << sortsStr[secondSortType] << " time "
            << secondResults[resultsIdx] << endl;
            
            // verify that lists are sorted, if not exit the program
            if (!validateSort(list1) && !validateSort(list2)) {
                cout << "Lists are not sorted! Exiting program ...\n\n";
                return EXIT_ERROR_CODE;
            }
            
            sortsCount--;
            resultsIdx++;
            cout << setw(25) << right << "Sorts Validated\n";
            
        }while (sortsCount > 0);

        // display the result averages
        cout << showpoint << fixed << setprecision(1);
        cout << "\nSORTING RESULTS\n";
        cout << "---------------\n";
        cout << setw(20) << right << sortsStr[firstSortType] << " "
             << getAvg(firstResults, resultsIdx) << " clock ticks on average\n";
        cout << setw(20) << right << sortsStr[secondSortType] << " "
             << getAvg(secondResults, resultsIdx) << " clock ticks on average\n";

        // de-allocate the memory of the results arrays
        delete []firstResults;
        delete []secondResults;
        
        // display menu options again and get input
        cout << "\nPress any key to continue . . .\n\n";
        cin.ignore();
        getline(cin, ch);
        displayMenu();
        getInput(firstSort, secondSort, sortsCount);
        
    }// end main program while

    return 0;
}// end main

