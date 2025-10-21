#include <vector>

// Bubble Sort - slow sorting algorithm
// Time Complexity = O(n^2)

// Bubble Sort using std::vector
void bubbleSort(std::vector<int>& arr)
{
	bool swapped;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

// Bubble Sort using standard array
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n)
{
	bool swapped;

	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			swap(&arr[j], &arr[j + 1]);
		}

		if (!swapped)
		{
			break;
		}
	}
}