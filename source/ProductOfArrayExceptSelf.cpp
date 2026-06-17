// Prefix : Suffix 
// Edge case : No zero, single zero, multiple zeros
//Time : O(n), Space : O(1) excluding the output array
#include<iostream>
#include<vector>

using namespace std;	

class Solution {
public:
	vector<int> productOfArrayExceptSelf(vector<int> nums)
	{
		int n = nums.size();
		if (n < 2)
			return {};
		vector<int> product(n, 1);

		for (int i = 1; i < n; i++)
		{
			product[i] = product[i-1] * nums[i-1];
		}
		int suffix = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			product[i] *= suffix;
			suffix *= nums[i];
		}
		return product;
	}
};