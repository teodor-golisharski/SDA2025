#include <iostream>
#include <vector>
using namespace std;

int getRank(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0' + 1;
	}
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 11;
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 37;
	}
	return 0;
}

char getCharByRank(int rank)
{
	if (rank >= 1 && rank <= 10)
	{
		return '0' + (rank - 1);
	}
	if (rank >= 11 && rank <= 36)
	{
		return 'a' + (rank - 11);
	}
	if (rank >= 37 && rank <= 62)
	{
		return 'A' + (rank - 37);
	}
	return '?'; 
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	char* arr = new char[n];
	cin.read(arr, n);

	vector<int> count(63, 0); 

	for (int i = 0; i < n; i++)
	{
		int rank = getRank(arr[i]);
		count[rank]++;
	}

	for (int r = 1; r <= 62; r++)
	{
		for (int i = 0; i < count[r]; i++)
			cout << getCharByRank(r);
	}

	delete[] arr;
	return 0;
}
