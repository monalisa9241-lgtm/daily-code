/*
* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
* with the colors in the order red, white, and blue.
* We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

// Could you come up with a one - pass algorithm using only constant extra space ?

// Edge Cases
/*
* Size based edge cases: Empty array, array with one element, array with two elements.
* Distribution based edge cases: All elements are the same, all elements are different, some elements are the same and some are different.
* Position Based edge cases: Elements are already sorted, elements are in reverse order, elements are randomly distributed.
* Pattern Based edge cases: Repeating patterns, alternating patterns, clustered patterns.
* Boundary Condition Edge Cases: extreme distribution of colors, maximum and minimum values of the integers representing colors.
*/

#include <vector>
#include<iostream>

using namespace std;

class solution {
public: 
	void sortColors(vector<int>& nums) {
		int low = 0, mid = 0, high = nums.size() - 1;
		while (mid <= high) {
			switch (nums[mid]) {
			case 0:
				swap(nums[low], nums[mid]);
				low++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(nums[mid], nums[high]);
				high--;
				break;
			}
		}
	}
};