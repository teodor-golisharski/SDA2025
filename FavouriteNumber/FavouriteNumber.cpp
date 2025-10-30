#include <iostream>
#include <vector>
#include <cmath>

long long getCandies(long long l, long long r, long long x, int depth) {
	if (l == r) {
		return depth;
	}

	long long size = r - l + 1;
	long long third = size / 3;
	long long midL = l + third;
	long long midR = midL + third - 1;

	if (x >= midL && x <= midR) {
		return depth;
	}
	else if (x < midL) {
		return getCandies(l, midL - 1, x, depth + 1);
	}
	else {
		return getCandies(midR + 1, r, x, depth + 1);
	}
}

int main() {
	int p, n;
	std::cin >> p >> n;

	long long N = 1;
	for (int i = 0; i < p; i++) {
		N *= 3;
	}

	for (int i = 0; i < n; i++) {
		long long f;
		std::cin >> f;
		std::cout << getCandies(1, N, f, 1) << "\n";
	}

	return 0;
}
