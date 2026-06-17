#include<iostream>
using namespace std;

//Same as Remove duplicates , but each element at max can occur 2 times
//At most two occurance of the element is allowed, so will compare the current with k-2, if it is different then two of that element is not placed in the array. 


class solution
{
	int removeDuplicates_2max(int* nums, int numsSize)
	{
		if (numsSize < 2) return numsSize;
		int i = 2;
		for (int j = 2; j < numsSize; j++)
		{
			if (nums[j] != nums[i-2])
			{
				nums[i++] = nums[j];
			}
			return i;
		}
	}
};