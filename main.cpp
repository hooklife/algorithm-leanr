#include <iostream>
#include "SortTestHelper.h"

template<typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    float arr[10] = {1, 10.1, 9, 8, 7, 6, 5, 4, 3, 2};
    SortTestHelper::testSort("Selection Sort", selectSort, arr, 10);
//    selectSort(a, 10);
//    SortTestHelper::printArray(a, 10);
    return 0;
}