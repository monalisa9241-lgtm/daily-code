//Minimum coin change required to make a certain amount of money given a set of coin denominations.
// This version also prints the actual coins used to make the amount.
//Time complexity: O(amount * number of coins), Space complexity: O(amount)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		vector<int> coinUsed(amount + 1, -1); // To track the last coin used for each amount
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int coin : coins) {
				if (coin <= i && dp[i - coin] != INT_MAX) {
					if (dp[i] > dp[i - coin] + 1) {
						dp[i] = dp[i - coin] + 1;
						coinUsed[i] = coin; // Update the last coin used
					}
				}
			}
		}
		if (dp[amount] == INT_MAX) {
			return -1; // No solution
		}
		// Print the coins used
		cout << "Coins used to make amount " << amount << ": ";
		int currentAmount = amount;
		while (currentAmount > 0) {
			cout << coinUsed[currentAmount] << " ";
			currentAmount -= coinUsed[currentAmount];
		}
		cout << endl;
		return dp[amount];
	}
};