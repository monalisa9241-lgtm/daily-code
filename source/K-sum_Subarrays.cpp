// Find the number of subarrays with sum equal to k.
// Question to ask the interviewer:
// 1. Can the array contain negative numbers ?
// 2. Can the array contain zeros ?
// 3. What should be the output if there are no such subarrays ?
// 4. can be the subarray with single element considered to the result
// 5. if all the elements in the array is target : n*(n+1)/2 subarrays
// Brute-force approach: O(n^2) time complexity 

// Optimal approach: O(n) time complexity using a hash map, Space complexity: O(n) 

// sum range problem can be solved using prefix sums and a hash map to store the frequency of prefix sums encountered while iterating through the array.
// prefix sum is the sum of elements from the start of the array to the current index
// If prefix sum at index j is prefixSum[j] and we want to find a subarray that sums to k, 
// we can check if there exists a prefix sum at index i such that prefixSum[i] = prefixSum[j] - k.
// If such a prefix sum exists, then the subarray from index i+1 to j has a sum of k.
// We can use a hash map to store the frequency of each prefix sum encountered while iterating through the array.

#include <vector>
#include <unordered_map>

using namespace std;

class solution
{
	int subArraySum_k(vector<int>& nums, int k)
	{
		unordered_map<long long, int> prefixSumCount;
		prefixSumCount.reserve(nums.size() + 1);

		prefixSumCount[0] = 1; // empty prefix to allow subarrays starting at index 0

		long long prefixSum = 0;
		int count = 0;

		for (int num : nums)
		{
			prefixSum += static_cast<long long>(num);

			long long needed = prefixSum - static_cast<long long>(k);
			auto it = prefixSumCount.find(needed);
			if (it != prefixSumCount.end())
			{
				count += it->second;
			}

			prefixSumCount[prefixSum]++;
		}

		return count;
	}
};

// Notes:
// Use long long for prefixSum and the map key to reduce overflow risk when sums grow large.
// reserve map capacity to reduce rehashing for large input

// With the prefix-sum approach, an empty nums naturally returns 0 because the loop never executes and count stays 0.