// Given a sorted array in ascending order and a target value, 
// find the indexes of two numbers in the array that add up to the target value.
// if no such numbers exist , return [-1, -1].

// Time : O(n) space : O(1)
// Edge Cases
// 1. Empty array return [-1, -1]
// 2. Array with only one element return [-1, -1]
// 3. No two numbers add up to the target return [-1, -1]
// 4. Multiple pairs add up to the target return the first pair found - as any pair is acceptable
// 5. Negative numbers in the array should be handled correctly
// 6. Target value can be negative, zero, or positive
// 7. Array with duplicate numbers should be handled correctly
// 8. Large numbers in the array should be handled correctly without overflow issues
// 9. Target value larger than the sum of the two largest numbers in the array should return [-1, -1]
// 10. Target value smaller than the sum of the two smallest numbers in the array should return [-1, -1]

// Two pointers approach

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> twoSumSorted(const vector<int>& nums, int target)
{
    int n = nums.size();
    if (n < 2)
        return { -1, -1 };

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        long long sum = (long long)nums[left] + nums[right];

        if (sum == target)
            return { left, right };
        else if (sum < target)
            left++;
        else
            right--;
    }

    return { -1, -1 };
}