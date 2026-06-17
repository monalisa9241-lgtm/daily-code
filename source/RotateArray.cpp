// Rotate array to the right by k steps, where k is non-negative.
//Reversing the whole array moves the tail to the front but in reverse order. 
// Reversing the first k elements moves them to the front in correct order. 
// Reversing the rest moves them to the back in correct order.	

#include <vector>	
#include <iostream>
#include <algorithm>
using namespace std;	

class Solution {
public:
	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size(); 
		if (n <= 1) return;

		k = k % n; // Handle cases where k is greater than n
		if (k == 0) return; // No rotation needed if k is 0

		reverse(nums.begin(), nums.end()); // Reverse the entire array
		reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
		reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements

	}
};

