// Minimum element after replacement with sum of digits
// Given an array of integers, replace each element with the sum of its digits and return the minimum element in the modified array.

//Clarification:
//1. Can the array contain negative numbers ?
//2. Can the array contain zeros ?
//3. is there any need of array element replacement or we can directly calculate the sum of digits and find the minimum ?
//4. input constraints ?
//5. what should be the output if the array is empty ?

#include <vector>
#include <algorithm>

using namespace std;

class solution
{
	int min_element(vector<int>& nums)
	{
		int curr_min = numeric_limits<int>::max();
		for (int num : nums)
		{
			int digit_sum = 0;
			while (num)
			{
				digit_sum += num % 10;
				num /= 10;
			}
			curr_min = min(curr_min, digit_sum);
		}
		return curr_min;
	}
};