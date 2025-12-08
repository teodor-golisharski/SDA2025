#include <iostream>

int dp[1000], n;

int fib(int n) {
    // База
    if (n == 1 || n == 2) {
        return 1;
    }

	// Проверка за вече изчислено
    if (dp[n] != 0) {
        return dp[n];
    }

    // Рекурентно уравнение
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    std::cin >> n;

    std::cout << fib(n) << std::endl;
}