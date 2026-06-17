// Given a sorted array in ascending order and a target value,
// find the indexes of two numbers in the array whose sum is closest to the target value.
// If no such numbers exist (size < 2), return [-1, -1].

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cstdlib>

using namespace std;

vector<int> twoSumSortedClosest(const vector<int>& nums, int target)
{
    int n = static_cast<int>(nums.size());
    if (n < 2)
        return { -1, -1 };

    int left = 0;
    int right = n - 1;

    int bestLeft = -1;
    int bestRight = -1;
    long long bestDiff = numeric_limits<long long>::max();

    while (left < right)
    {
        long long sum = static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);
        long long diff = llabs(sum - static_cast<long long>(target));

        if (diff < bestDiff)
        {
            bestDiff = diff;
            bestLeft = left;
            bestRight = right;

            if (bestDiff == 0)
                break; // exact match is the closest possible
        }

        if (sum < target)
            left++;
        else
            right--;
    }

    return { bestLeft, bestRight };
}