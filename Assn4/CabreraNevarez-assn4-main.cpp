/**********************************************************************
 FILENAME:      CabreraNevarez-Assn4-main.cpp
 DESCRIPTION:   TODO
 CLASS/TERM:    CS372 / Summer 2nd term
 DESIGNERS:     Garry Cabrera and Juan Nevarez
 FUNCTIONS:     TODO
 **********************************************************************/

#include <iostream>
#include <iomanip>

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

int main()
{
    funcPtrType funcPtr;                // pointer to sort function chosen by user
    int *firstResults;                  // first results array
    int *secondResults;                 // second results array
    char firstSort;                     // first sort function user will choose
    char secondSort;                    // second sort function user will choose
    int sortsCount;                     // number of times sorts will be repeated
    int resultsIdx;                     // index where results will be stored in results arrays
    int list1[LIST_SIZE];               // first list array to be sorted
    int list2[LIST_SIZE];               // second list array to be sorted
    

    resultsIdx = 0;
    
    // initial menu display and user input
    displayMenu();
    getInput(firstSort, secondSort, sortsCount);
    
    cout << getFuncTypeIndex(firstSort)<<endl;
    cout << getFuncTypeIndex(secondSort)<<endl;
    
    // loop while user doesn't choose EE to exit
    while (firstSort != 'E')
    {
        // initialize the results arrays
        firstResults = new int[sortsCount];
        secondResults = new int[sortsCount];
        
        // display error message if unable to allocate memory for results array
        if (firstResults == NULL || secondResults == NULL)
            cout << "\nUnable to allocate memory for the results array. Exiting program...\n";
        
        // loop number of reps and while list are correctly sorted
        do
        {
            CreateUnsortedList(list1, list2);
            
            // call first sort function
            funcPtr = funcPtrArray[getFuncTypeIndex(firstSort)];
            firstResults[resultsIdx] = funcPtr(list1);

            // call second sort function
            funcPtr = funcPtrArray[getFuncTypeIndex(secondSort)];
            secondResults[resultsIdx] = funcPtr(list2);
            
            // verify that lists are sorted, if not exit the program
            if (!validateSort(list1) && !validateSort(list2)) {
                cout << "Lists are not sorted! Exiting program ...\n\n";
                return EXIT_ERROR_CODE;
            }
            
            sortsCount--;       //****** DON'T USE THIS FOR THE INDEX FOR THE RESULTS ARRAY
            resultsIdx++;
            cout << "Sorts Validated\n";
        }while (sortsCount > 0);
        

        //displayAverages(list1, list2);
        
        // de-allocate the memory of the results arrays
        delete firstResults;
        delete secondResults;
        
        // display menu options again
        displayMenu();
        getInput(firstSort, secondSort, sortsCount);
        
    }// end main program while

    return 0;
}// end main

