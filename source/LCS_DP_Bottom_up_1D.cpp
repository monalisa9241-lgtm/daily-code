//find the length of the longest common subsequence of two strings using a 1D DP array (space optimized).

#include <iostream>
#include <vector>	
#include <string>	
#include <algorithm>	
#include <limits>	
#include <stdexcept>	

using namespace std;

int longestCommonSubsequence_1D(const string& text1, const string& text2) {
	int m = static_cast<int>(text1.size());
	int n = static_cast<int>(text2.size());
	vector<int> dp(n + 1, 0);
	for (int i = m - 1; i >= 0; --i) {
		int prev = 0; // This will hold the value of dp[j+1] from the previous iteration
		for (int j = n - 1; j >= 0; --j) {
			int temp = dp[j]; // Store current dp[j] before updating it
			if (text1[i] == text2[j]) {
				dp[j] = 1 + prev;
			}
			else {
				dp[j] = max(dp[j], dp[j + 1]);
			}
			prev = temp; // Update prev to the old value of dp[j]
		}
	}
	return dp[0];
}