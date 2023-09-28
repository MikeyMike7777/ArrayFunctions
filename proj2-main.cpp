/*
 * file: proj2-main.cpp
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
 * Reads unknown number of int arrays from file and displays largest,
 * smallest, average, and median values of each array
 */

#include <iostream>
#include <fstream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main() {
    ifstream inputFile;
    int size = 0, tempS, tempL, largestVal = 0, smallestVal = 0;

    //open file
    inputFile.open("arrays.txt");

    if (!inputFile) {
        cerr << "Bad" << endl;
        return 1;
    }

    //get size of first array
    inputFile >> size;
    //allocate memory for new array and set pointer to memory allocated
    int* intArray = new int[size];
    //fill memory with values
    for (int i = 0; i < size; i++) {
        inputFile >> intArray[i];
    }
    //set initial value for largest value in all arrays and output largest val
    tempL = largestValue(intArray, size);
    cout << "Largest Value: " << tempL << endl;

    //set initial value for smallest value in all arrays and output smallest val
    tempS = smallestValue(intArray, size);
    cout << "Smallest Value: " << tempS << endl;

    //output average and median val
    cout << "Average Value: " << averageValue(intArray, size) << endl;
    cout << "Median Value: " << medianValue(intArray, size) << endl;

    //free allocated memory
    delete [] intArray;

    //get the rest of the arrays and do same thing as long as there is another size in arrays.txt
    while (inputFile >> size) {
        //allocate memory for new array of integers
        intArray = new int[size];
        //fill array
        for (int i = 0; i < size; i++) {
            inputFile >> intArray[i];
        }

        //output values
        tempL = largestValue(intArray, size);
        cout << "Largest Value: " << tempL << endl;

        tempS = smallestValue(intArray, size);
        cout << "Smallest Value: " << tempS << endl;

        cout << "Average Value: " << averageValue(intArray, size) << endl;
        cout << "Median Value: " << medianValue(intArray, size) << endl;

        //store largest value in all arrays in largestVal
        if (tempL > largestVal) {
            largestVal = tempL;
        }

        //store smallest value in all arrays in smallestVal
        if (tempS < smallestVal) {
            smallestVal = tempS;
        }

        //free allocated memory from each array
        delete [] intArray;
    }

    //close file
    inputFile.close();

    return 0;
}
