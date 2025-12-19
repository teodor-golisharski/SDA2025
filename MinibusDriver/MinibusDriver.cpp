#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Group {
	int k, x, y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q;
	cin >> Q;

	while (Q--) {
		int N, C;
		cin >> N >> C;

		vector<Group> groups(N);
		for (int i = 0; i < N; i++) {
			cin >> groups[i].k >> groups[i].x >> groups[i].y;
		}

		sort(groups.begin(), groups.end(), [](const Group& a, const Group& b) {
			return a.x < b.x;
			});

		priority_queue<pair<int, int>,
			vector<pair<int, int>>,
			greater<pair<int, int>>> pq;

		int currentPassengers = 0;
		bool ok = true;

		for (const auto& g : groups) {
			while (!pq.empty() && pq.top().first <= g.x) {
				currentPassengers -= pq.top().second;
				pq.pop();
			}

			currentPassengers += g.k;
			if (currentPassengers > C) {
				ok = false;
				break;
			}

			pq.push({ g.y, g.k });
		}

		cout << (ok ? 1 : 0) << '\n';
	}

	return 0;
}