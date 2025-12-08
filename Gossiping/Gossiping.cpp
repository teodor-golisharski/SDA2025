#include <iostream>
#include <unordered_map>
#include <climits>

int main() {
	std::unordered_map<int, int> gossipMap;

	int n;
	std::cin >> n;

	int minDist = INT_MAX;
	
	for (int i = 0; i < n; i++) {
		int topic;
		std::cin >> topic;


		if (gossipMap.find(topic) == gossipMap.end()) {
			gossipMap.insert({ topic, i });
		}
		else {
			if (minDist > i - gossipMap[topic]) {
				minDist = i - gossipMap[topic];
			}
		}
	}
	std::cout << minDist << "\n";
}

