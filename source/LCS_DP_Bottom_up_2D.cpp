//find the length of the longest common subsequence of two strings. 
// The longest common subsequence of two strings is the longest sequence that can be obtained from 
// both original strings by deleting some characters (without changing the order of the remaining characters).

//use bottom-up dynamic programming approach to solve the longest common subsequence problem.
// 2D table to store the lengths of longest common subsequence for substrings of the two input strings.

#include <iostream>
#include <vector>	
#include <string>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;

int longestCommonSubsequence_2D(const string& text1, const string& text2) {
	int m = static_cast<int>(text1.size());
	int n = static_cast<int>(text2.size());

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (text1[i] == text2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	return dp[0][0];
}

int longestCommonSubsequence_INT_MAX(const string& text1, const string& text2) {
	const size_t m = text1.size();
	const size_t n = text2.size();

	// dp is O(m*n). For extremely large inputs (e.g., near INT_MAX), this is not feasible.
	// Guard against size_t overflow and impossible allocation.
	const size_t rows = m + 1;
	const size_t cols = n + 1;

	if (rows != 0 && cols > (numeric_limits<size_t>::max() / rows)) {
		throw overflow_error("LCS DP table size overflows size_t.");
	}

	const size_t cellCount = rows * cols;
	if (cellCount > (numeric_limits<size_t>::max() / sizeof(int))) {
		throw overflow_error("LCS DP table byte size overflows size_t.");
	}

	// At this point allocation may still be impractically large; let allocation fail or add your own limit.
	vector<vector<int>> dp(rows, vector<int>(cols, 0));

	// Building the dp table
	for (size_t i = m; i-- > 0; ) {
		for (size_t j = n; j-- > 0; ) {
			if (text1[i] == text2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	return dp[0][0];
}