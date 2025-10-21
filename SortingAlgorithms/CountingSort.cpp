// Counting Sort
// Time Complexity = O(n+k)
// Works best when the range of values is small (like char)

void conting_sort(char arr[], int n)
{
	// Make a copy of the original array
	char* arr_copy = new char[n];
	for (int i = 0; i < n; ++i)
	{
		arr_copy[i] = arr[i];
	}

	// 
	int* count = new int[256];
	for (int i = 0; i < n; ++i)
	{
		count[arr[i]] = count[arr[i]] + 1;
	}
	for (int i = 1; i <= 255; ++i)
	{
		count[i] += count[i - 1];
	}
	// To make it stable we are operating in reverse order.
	for (int i = n - 1; i >= 0; i--)
	{
		arr[count[arr_copy[i]] - 1] = arr_copy[i];
		count[arr_copy[i]] = count[arr_copy[i]] - 1;
	}
}