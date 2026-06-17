//Minimum coin change required to make a certain amount of money given a set of coin denominations,
// but each coin can only be used once.
//Time complexity: O(amount * number of coins), Space complexity: O(amount)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	

class Solution {
	public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int coin : coins) {
			// Descend to ensure each coin is used at most once (0/1 knapsack style)
			for (int t = amount; t >= coin; t--) {
				if (dp[t - coin] != INT_MAX) {
					dp[t] = min(dp[t], dp[t - coin] + 1);
				}
			}
		}
		return (dp[amount] == INT_MAX) ? -1 : dp[amount];
	}
};