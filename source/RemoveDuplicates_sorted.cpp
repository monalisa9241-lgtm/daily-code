#include<iostream>
using namespace std;	

// Given a sorted array nums, 
// remove the duplicates in-place such that each element appears only once and returns the new length.
// Do not allocate extra space for another array,
// you must do this by modifying the input array in-place with O(1) extra memory.
// Approach
// Use two pointers technique: one for iterating through the array and 
// the other for tracking the position of the next unique element.
// Time complexity: O(n), where n is the length of the input array.
// Space complexity: O(1), since we are modifying the array in-place without using extra space.
// Duplicates are placed next to each other, 
// so we can compare the current element with the previous one to identify duplicates.
class Solution 
{
	public:
		int removeDuplicates(int* nums, int numsSize)
		{
			if (numsSize == 0) return 0;
			int i = 0;
			for (int j = 1; j < numsSize; j++)
			{
				if (nums[j] != nums[i])
				{
					i++;
					nums[i] = nums[j];
				}
				return i + 1;
			}
		}
};