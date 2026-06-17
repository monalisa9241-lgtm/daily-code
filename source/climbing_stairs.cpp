

#include <iostream>
using namespace std;

class Solution {
public:
	// 1 or 2 steps at a time
	// space O(1) time O(n)
    int climbStairs(int n) {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        int one_step = 1, two_step = 2;
        for (int i = 3; i <= n; i++)
        {
            int current_step = one_step + two_step;
            one_step = two_step;
            two_step = current_step;    
        }
        return two_step;
    }
    // Allowed steps: 1, 2, 3
    // dp[i] = dp[i-1] + dp[i-2] + dp[i-3], with dp[0]=1
    int climbStairs(int n) {


        if (n == 0 || n== 1) return 1;   
        if (n == 2) return 2;

        int a = 1; // dp[0]
        int b = 1; // dp[1]
        int c = 2; // dp[2]

        for (int i = 3; i <= n; ++i)
        {
            const int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }

};