/*
 * file: proj2-arrayFunctions.cpp
 * author: Michael Mathews
 * course: CSI 1440
 * assignment: Project 2
 * due date: 9/7/21
 *
 * date modified: 9/4/21
 *      - File Created
 *
 * date modified: 9/5/21
 *      - code written
 *
 * date modified: 9/6/21
 *      - code finished
 *
 * Creates functions to be used to sort and find specific values in integer arrays
 */

#include "proj2-arrayFunctions.h"
#include <iostream>

using namespace std;

void bubbleSort(int *array, int size) {
    //bubble sort algorithm
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j+1] < array[j]) {
                //swap values if not in increasing order
                swap(array[j+1], array[j]);
            }
        }
    }
}

int largestValue(int *array, int size) {
    //sort array
    bubbleSort(array, size);
    //return last value in array
    return array[size-1];
}

int smallestValue(int *array, int size) {
    //sort array
    bubbleSort(array, size);
    //return first value in array
    return array[0];
}

double averageValue(int *array, int size) {
    double avg = 0;
    //add all values in array
    for (int i = 0; i < size; i++) {
        avg += array[i];
    }
    //divide sum by size to find average
    avg /= size;
    return avg;
}

int medianValue(int *array, int size) {
    //sort array
    bubbleSort(array, size);
    //if number is even, decrease size by one to give the lower of the two middle values
    if (size%2 == 0){
        size--;
    }
    //return middle value in sorted array
    return array[(size/2)];
}