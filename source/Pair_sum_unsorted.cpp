// Given an array of integers and a target value, return the indices of two numbers in the array that add up to the target value. 
// The array is not sorted. If no such numbers exist, return [-1, -1].

// Question to ask
// the interviewer : Can we assume that there is at most one solution ? Can the same element be used twice ?
// is there duplicates in the array ? in that case what should be the output ? 
// for example if the input is [1, 2, 3, 4, 5, 2] and target is 5, should we return [1, 2] or [2, 5] ?
// Brute -force approach: O(n^2) time complexity

// Optimal approach: O(n) time complexity using a hash map, Space complexity: O(n)

#include <vector>
#include <unordered_map>

using namespace std;

class solution
{
	public:
	vector<int> twoSumUnsorted(const vector<int>& nums, int target) {
		unordered_map<int, int> num_to_index; // number -> index
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			int complement = target - nums[i];
			if (num_to_index.count(complement) > 0) {
				return { num_to_index[complement], i };
			}
			num_to_index[nums[i]] = i;
		}
		return { -1, -1 }; // no solution found
	}
};
