/**********************************************************************
 FILENAME:          CabreraNevarez-Assn4-common.h
 DESCRIPTION:       Contains constants, function pointer array and constant
                    variables needed for the overall program
 IMPLEMENTED BY:    Garry Cabrera and Juan Nevarez
 **********************************************************************/

// Constants
// TODO: CHANGE TO 4 ONCE OTHER 2 FUNCS ARE ADDED
// number of sorting functions
const int NUM_SORT_FUNCS = 2;
// max size of unsorted list of integers
const int LIST_SIZE = 10;
// max value of random integer to insert into hash table
const int MAX_INTEGER = 30000;
// error code that will exit the program
const int EXIT_ERROR_CODE = 1;

// Defines a TYPE which is a pointer to a function that takes
// an int array argument and returns an int
typedef int (*funcPtrType)(int[]);

/*
// Array of pointers for the sorting prototypes
const funcPtrType funcPtrArray[NUM_SORT_FUNCS] = {
    &mergeSort,
    &insertionSort};
 */