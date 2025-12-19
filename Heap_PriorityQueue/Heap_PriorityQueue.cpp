#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;

		for (auto s : stones) {
			pq.push(s);
		}

		while (pq.size() > 1) {
			int w1 = pq.top();
			pq.pop();

			int res = w1;

			if (!pq.empty()) {
				int w2 = pq.top();
				pq.pop();
				res -= w2;
			}

			if (res != 0) {
				pq.push(res);
			}

		}
		return pq.size() ? pq.top() : 0;
	}

	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;
		for (auto n : nums) {
			pq.push(n);
		}

		for (int i = 1; i < k; ++i) {
			pq.pop();
		}
		return pq.top();
	}
	
	struct Point {
		int dist;
		int x;
		int y;

		Point(int d, int xx, int yy) : dist(d), x(xx), y(yy) {}
	};
	struct Compare {
		bool operator()(Point& p1, Point& p2) {
			return p1.dist < p2.dist;
		}
	};
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<Point, vector<Point>, Compare> maxHeap;

		for (auto& p : points) {
			int x = p[0];
			int y = p[1];
			int d = x * x + y * y;

			maxHeap.push({ d, x, y });

			if (maxHeap.size() > k) {
				maxHeap.pop();
			}
		}

		vector<vector<int>> result;

		while (!maxHeap.empty()) {
			Point p = maxHeap.top();
			maxHeap.pop();
			result.push_back({ p.x, p.y });
		}

		return result;
	}

	int leastInterval(vector<char>& tasks, int n) {
		vector<int> taskFrequency(26, 0);

		for (char t : tasks) {
			taskFrequency[t - 'A']++;
		}

		priority_queue<int> pq;
		for (int freq : taskFrequency) {
			if (freq > 0) {
				pq.push(freq);
			}
		}

		int currentTime = 0;
		while (!pq.empty()) {
			int cycleLength = n + 1;
			vector<int> taskToReinsert;
			
			while (cycleLength > 0 && !pq.empty()) {
				int remainingCount = pq.top();
				pq.pop();

				if (--remainingCount > 0) {
					taskToReinsert.push_back(remainingCount);
				}

				currentTime++;
				cycleLength--;
			}

			for (int& count : taskToReinsert) {
				pq.push(count);
			}

			if (pq.empty()) {
				break;
			}

			currentTime += cycleLength;
		}
		return currentTime;
	}
};

int main() {
	cout << "Hello World!\n";
}
