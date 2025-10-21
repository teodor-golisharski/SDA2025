// Insertion Sort - slow slorting algorithm
// Time Complexity = O(n^2)

void insertionSort(int arr[], int n)
{
	// Start from the second element (first is considered sorted)
	for (int i = 1; i < n; i++)
	{
		// Store the current element to be inserted
		int key = arr[i]; 

		// j points to the last index of the sorted part of the array
		int j = i - 1;

		// Move elements of arr[0...i-1] that are greater than key
		// one position ahead to make space for key
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		// Insert the key at the correct position
		arr[j + 1] = key;
	}
}