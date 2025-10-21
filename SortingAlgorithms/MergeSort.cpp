// Merge Sort Algorithm - fast sorting algorithm
// Time Complexity - O(nlog(n))
// Memory - O(n)

// Idea: recursively break the array to two others
// than at the base of the recursion start sorting them and
// merge the two sorted arrays into one

void merge(int arr[], int start, int middle, int end)
{
	// STEP 1 - Division of arr[] to arr1 and arr2 and pasting the elements in the corresponding array 
	// Create n1 and n2 which are the size of the two arrays
	int n1 = middle - start;
	int n2 = end - middle;

	// Create arrays arr1 and arr2
	int* arr1 = new int[n1];
	int* arr2 = new int[n1];

	// Paste the elements in arr1 and arr2 
	for (int i = 0; i < n1; i++)
	{
		arr1[i] = arr[start + i];
	}
	for (int j = 0; j < n2; j++)
	{
		arr2[j] = arr[middle + j];
	}

	// STEP 2 - Merge the arrays
	// Indices [ i for arr1, j for arr2, k for the original arr ]
	int i = 0, j = 0, k = start;

	// While loop till we reach the end of arr1 or arr2
	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	// Copy if there are any left elements in ARR1
	while (i < n1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}

	// Copy if there are any left elements in ARR2
	while (j < n2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}

	// Free the dynamically allocated memory
	delete[] arr1;
	delete[] arr2;
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) // base case for recursion
	{
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r); // merge the two sorted subarrays at this level of recursion
	}
}