#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000005730;
int dp[100000], n;

std::vector<std::vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
};

std::vector<std::vector<int>> result(3, std::vector<int>(3, 0));

// Fibonachi numbers (Top-Down)
int fib(int n) {
	// Base
	if (n <= 1) return n;

	// Check whether already calculated
	if (dp[n] != 0) {
		return dp[n];
	}

	// Recurrence equation 
	return dp[n] = fib(n - 1) + fib(n - 2);
}

// Fibonachi numbers (Bottom-Up)
int fib_bottom_up(int n) {
	if (n <= 1) {
		return n;
	}

	std::vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (size_t i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

// Money problem (Top-Down)
int Min(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}
int ans(int x) {
	// Base
	if (x == 0) {
		return 0;
	}
	if (x < 0) {
		return INF;
	}

	// Check whether already calculated
	if (dp[x] != 0) {
		return dp[x];
	}

	// Recurrence equation
	int val = Min(ans(x - 2), ans(x - 3), ans(x - 7));

	// Check whether val is found
	if (val == INF) {
		return INF;
	}

	return dp[x] = val + 1;
}


// Money problem (Bottom-Up)
int moneyProblem_bottom_up(std::vector<int>& coins, int amount) {
	// Array dp
	std::vector<int> dp(amount + 1, INT_MAX);

	// Base
	dp[0] = 0;

	for (size_t i = 1; i <= amount; i++) {

		for (int coin : coins) {
			
			// Check whether current coin could be used
			if (coin <= i) {
				
				// Check whether dp[i - coin] is calculated
				if (dp[i - coin] != INT_MAX) {
					
					// Find the minimum coins used
					dp[i] = std::min(dp[i], dp[i - coin] + 1);
				}
			}
		}
	}

	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Money problem (Bottom_Up)
int minPathSum(std::vector<std::vector<int>>& grid) {
	int rows = grid.size();
	if (rows == 0) return 0;
	int cols = grid[0].size();

	std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));

	// Base
	dp[0][0] = grid[0][0];

	// Firs row
	for (int j = 1; j < cols; j++) {
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}

	// First column
	for (int i = 1; i < rows; i++) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}

	for (size_t i = 1; i < rows; i++) {
		for (size_t j = 1; j < cols; j++) {
			dp[i][j] = grid[i][j] + std::min(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	return dp[rows - 1][cols - 1];

}

int minPathSum_top_down(int x, int y) {
	// to-do
}

int main() {
	std::vector<std::vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};
	// std::cin >> n;

	std::cout << minPathSum(grid) << std::endl;
}