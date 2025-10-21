#include <iostream>
#include "QuickSort.h"

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}