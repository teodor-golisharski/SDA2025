#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];
    int count = 0;

    for (size_t i = 0; i < n; i++)
    {
        int x;                
        std::cin >> x;

        // binary search
        int left = 0, right = count;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }
        int pos = left;

        // move to right
        for (int j = count; j > pos; j--)
            arr[j] = arr[j - 1];

        arr[pos] = x;
        count++;

        // median
        double median;
        if (count % 2 == 1)
            median = arr[count / 2];
        else
            median = (arr[count / 2 - 1] + arr[count / 2]) / 2.0;

        std::cout << median << std::endl;
    }

    return 0;

    delete[] arr;
}
