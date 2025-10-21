#include <utility>

// Selection Sort - slow sorting algorithm
// Time Complexity = O(n^2)

// Quick Explanation: 
// The algorithm repeatedly finds the smallest element 
// from the unsorted part of the array and places it 
// at the beginning. This process is repeated until 
// the entire array is sorted in ascending order.

void selectionSort(int arr[], int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int iMin = j;
		for (int i = j + 1; i < n; i++)
		{
			if (arr[i] < arr[iMin])
			{
				iMin = i;
			}
		}

		if (iMin != j)
		{
			std::swap(arr[j], arr[iMin]);
		}
	}
}



