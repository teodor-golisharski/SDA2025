#include <iostream>
#include <unordered_map>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::unordered_map<int, int> map;
	for (int x : arr) {
		map[x]++;
	}
	int count = 0;
	for (auto& a : map) {
		int key = a.first;
		int value = a.second;

		if (map.find(key * m) != map.end()) {
			int secondValue = map[key * m];

			if (map.find(key * m * m) != map.end()) {
				int thirdValue = map[key * m * m];
				count += value * secondValue * thirdValue;
			}
		}
	}

	std::cout << count << "\n";
}

