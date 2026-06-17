//Given an array of integers, find the first and last position of a given target value. If the target is not found in the array, return [-1, -1].
// The algorithm should have a time complexity of O(log n) and a space complexity of O(1).
//Edge Cases: 
/* 
- empty input, 
- target not found, 
- target found at the beginning of the array, 
- target found at the end of the array, 
- target found multiple times in the array. 
- target > right most element in the array
- target < left most element in the array */
// first occurance : find the leftmost index of the target value using binary search: right = mid -1
// last occurance : find the rightmost index of the target value using binary search: mid = left + (right - left +1) / 2; left = mid 
// to remove the infinite loop case when left and right are adjacent and mid always rounds down to left index.

// 1 search binary + linear expansion is easy to implment but it sacrifies worst case gaurantees, o(lgn + k) time, where k is the number of occurrences of the target value. 
// In worst case, when all elements are the same as the target, it degrades to O(n) time.

/*
* We can attempt a unified single-pass binary-search variant, but before optimizing for that constraint, I’d want to understand whether we are optimizing for:
* asymptotic complexity,
* constant factors,
* memory,
* or interview exploration.
* Because from a production engineering perspective, two clean binary searches already give optimal asymptotic complexity with much lower correctness risk.
*/

#include <vector>

using namespace std;

int findFirstOccurrence(const vector<int>& nums, int target);
int findLastOccurrence(const vector<int>& nums, int target);

vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.empty())
		return { -1, -1 };
	int n = nums.size() - 1;
	if (target < nums[0] || target > nums[n])
		return { -1, -1 };
	int first_Occurrence = findFirstOccurrence(nums, target);
	if (first_Occurrence == -1)
		return { -1, -1 };
	int last_Occurrence = findLastOccurrence(nums, target);
	return { first_Occurrence, last_Occurrence };
}

int findFirstOccurrence(const vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return (nums[left] == target) ? left : -1;
}

int findLastOccurrence(const vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left + 1) / 2; // Bias towards the right
		if (nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid; // Move left up to mid
		}
	}
	return (nums[right] == target) ? right : -1;
}	
