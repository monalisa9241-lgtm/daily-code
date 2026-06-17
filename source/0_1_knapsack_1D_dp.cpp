//Write clean C++ code for the 1D DP solution

#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
	int n = weights.size();

	if (capacity <= 0) {
		return 0;
	}
	if (n != values.size()) {
		return 0;
	}
	vector<int> dp(capacity + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int c = capacity; c >= weights[i]; --c) {
			dp[c] = max(dp[c], dp[c - weights[i]] + values[i]);
		}
	}
	return dp[capacity];
}
// Example usage: capacity is very huge, so we can not use 2D DP solution, 
// but 1D DP solution is still efficient.
// dimension of dp array is capacity + 1, so for huge capacity, it may still cause memory issues, 
// dimension flipping is used to reduce the dimension of dp array, 
// so that we can solve the problem with large capacity.

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
	int n = weights.size();
	if (capacity <= 0) {
		return 0;
	}
	if (n != values.size()) {
		return 0;
	}
	int max_value = 0;
	for (int v : values) {
		max_value += v;
	}	
	vector<long long> dp(max_value + 1, LLONG_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int v = max_value; v >= values[i]; --v) {
			if (dp[v - values[i]] != LLONG_MAX) {
				dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
			}
		}
	}
	//find the best value within the capacity
	for(int v = max_value; v>= 0; --v) {
		if (dp[v] <= capacity) {
			return v;
		}
	}
	return 0;	
}