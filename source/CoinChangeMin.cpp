//Minimum coin change required to make a certain amount of money given a set of coin denominations.
//bottom-up dynamic programming approach. 
// We create a dp array where dp[i] represents the minimum number of coins needed to make the amount i.
// We initialize dp[0] to 0 (since no coins are needed to make the amount 0) 
// and all other values to INT_MAX (indicating that those amounts cannot be made with the given coins). 
// We then iterate through each amount from 1 to the target amount, and for each coin denomination,
// we check if it can be used to make the current amount. If it can, we update our dp array accordingly. 
// Finally, we return the value in dp[amount], or -1 if it is still INT_MAX (indicating that the amount cannot be made with the given coins).
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

		for (int i = 1; i <= amount; i++) {
			for (int coin : coins) {
				if (coin <= i && dp[i - coin] != INT_MAX) {
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}
		return (dp[amount] == INT_MAX) ? -1 : dp[amount];
	}
};
