#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> studentsWeights;

int lowerBound(int value) { 
    int left = 0, right = studentsWeights.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
     
        if (studentsWeights[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int upperBound(int value) { 
    int left = 0, right = studentsWeights.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (studentsWeights[mid] <= value) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main() {
	int n, q;
	std::cin >> n >> q;

	studentsWeights.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> studentsWeights[i];
	}

	std::sort(studentsWeights.begin(), studentsWeights.end());

	for (int j = 0; j < q; j++) {
		int minJ, maxJ;

		std::cin >> minJ >> maxJ;

		int leftIndex = lowerBound(minJ);
		int rightIndex = upperBound(maxJ);

		std::cout << rightIndex - leftIndex << std::endl;
	}

	return 0;
}
