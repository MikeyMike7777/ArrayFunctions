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
 * Tests the functions in proj2-arrayFunctions.cpp with extremities
 */

#include <iostream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main() {
    int a[3] = {1, 2, 3};
    // test basic values
    cout << "Largest Value: " << largestValue(a, sizeof(a)/4) << endl; //use sizeof to find size in bites
    cout << "Smallest Value: " << smallestValue(a, sizeof(a)/4) << endl; //divide sizeof by 4 because array is of
    cout << "Average Value: " << averageValue(a, sizeof(a)/4) << endl; //type int which takes 4 bites per value
    cout << "Median Value: " << medianValue(a, sizeof(a)/4) << endl;

    cout << endl;

    int b[100];
    //fill array with incrementing values all the way to 100
    //test if functions work with a big array of values
    for (int i = 0; i < 100; i++) {
        b[i] = i+1;
    }

    cout << "Largest Value: " << largestValue(b, sizeof(b)/4) << endl;
    cout << "Smallest Value: " << smallestValue(b, sizeof(b)/4) << endl;
    cout << "Average Value: " << averageValue(b, sizeof(b)/4) << endl;
    cout << "Median Value: " << medianValue(b, sizeof(b)/4) << endl;

    cout << endl;

    int c[20];
    //fill array with largest value being first and smallest last
    for (int i = 0; i < 100; i++) {
        c[i] = 20-i;
    }

    bubbleSort(c, 20);
    //make sure bubble sort is working correctly
    cout << "Should be 1: " << c[0] << endl;
    cout << "Should be 20: " << c[19] << endl;

    cout << endl;

    cout << "Largest Value: " << largestValue(c, sizeof(c)/4) << endl;
    cout << "Smallest Value: " << smallestValue(c, sizeof(c)/4) << endl;
    cout << "Average Value: " << averageValue(c, sizeof(c)/4) << endl;
    cout << "Median Value: " << medianValue(c, sizeof(c)/4) << endl;

    cout << endl;

    //test to see if calling functions again will give same values
    cout << "Largest Value: " << largestValue(c, sizeof(c)/4) << endl;
    cout << "Smallest Value: " << smallestValue(c, sizeof(c)/4) << endl;
    cout << "Average Value: " << averageValue(c, sizeof(c)/4) << endl;
    cout << "Median Value: " << medianValue(c, sizeof(c)/4) << endl;

    cout << endl;

    int d[3] = {1029, 325263, 23453}; //Testing with large values and biggest value in middle

    cout << "Largest Value: " << largestValue(d, sizeof(d)/4) << endl;
    cout << "Smallest Value: " << smallestValue(d, sizeof(d)/4) << endl;
    cout << "Average Value: " << averageValue(d, sizeof(d)/4) << endl;
    cout << "Median Value: " << medianValue(d, sizeof(d)/4) << endl;

    cout << endl;

    //Testing with dynamic memory
    int *e = new int[5];

    for (int i = 0; i < 5; i++) {
        e[i] = 10-(i*2);
    }

    //have to use exact size instead of size
    cout << "Largest Value: " << largestValue(e, 5) << endl;
    cout << "Smallest Value: " << smallestValue(e, 5) << endl;
    cout << "Average Value: " << averageValue(e, 5) << endl;
    cout << "Median Value: " << medianValue(e, 5) << endl;
    return 0;
}
