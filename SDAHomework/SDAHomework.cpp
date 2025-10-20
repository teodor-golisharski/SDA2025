#include <iostream>
#include <vector>

void quicksort(std::vector<std::string>& names, std::vector<int>& scores, int left, int right)
{
	int i = left, j = right;
	int pivot = scores[(left + right) / 2];
	std::string pivotName = names[(left + right) / 2];

	while (i <= j)
	{
		while (scores[i] > pivot || (scores[i] == pivot && names[i] < pivotName))
		{
			i++;
		}
		while (scores[j] < pivot || (scores[j] == pivot && names[j] > pivotName))
		{
			j--;
		}

		if (i <= j)
		{
			std::swap(scores[i], scores[j]);
			std::swap(names[i], names[j]);
			i++; 
			j--;
		}
	}

	if (left < j)
	{
		quicksort(names, scores, left, j);
	}
	if (i < right)
	{
		quicksort(names, scores, i, right);
	}
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::string> names(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> names[i];
	}

	std::vector<int> scores(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> scores[i];

	}

	quicksort(names, scores, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		std::cout << names[i] << " " << scores[i] << std::endl;
	}

	return 0;
}
