#include <utility>
#include "QuickSort.h"

// QuickSort - fast sorting algorithm
// Time Complexity - worst O(n^2), average O(nlog(n))
// Memory - no additional memory

// ### Faster then mergesort for small arrays !!!

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // choose the last element as pivot
    int i = low; // index of smaller element (track position to place smaller elements)             

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot) // if current element <= pivot
        {
            std::swap(arr[i], arr[j]); // move it to the "smaller" section
            i++; // increment the position for the next smaller element
        }
    }
    std::swap(arr[i], arr[high]); // put pivot in its correct sorted position
    return i; // return pivot index
}

void sort(int arr[], int low, int high)
{
    if (low < high) // base case: if subarray has more than 1 element
    {
        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1); // recursively sort left subarray
        sort(arr, pi + 1, high); // recursively sort right subarry
    }
}