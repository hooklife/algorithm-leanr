//
// Created by fuckrm on 18-5-23.
//

#ifndef UNTITLED_SORTTABLEHELPER_H
#define UNTITLED_SORTTABLEHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper {
    int *generateRandomArray(int n, int min, int max) {
        assert(min <= max);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (max - min + 1) + min;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        printArray(arr, n);
        assert(isSorted(arr, n));
        cout << fixed << sortName
             << ":" << (endTime - startTime) / (double) CLOCKS_PER_SEC << " s" << endl;
        return;
    }
}
#endif //UNTITLED_SORTTABLEHELPER_H
