//Jump to the end
/*
* As goal is to reach destination n-1, and lets consider we have reached n-1, 
A Possible way to reach index n-1 is from n-2. 
if we find a way to reach n-2 then we know we can each the destination. 
So the idea is if we can reach the last index from any earlier index m then  m becomes our new destination.

with this approach of backward moving starting i at index n-2, 
for each index if we can reach the current destination from i, 
i index becomes our new destination. we do this by checking it's possible to jump to the destination from i.
if i + nums[i] >= destination then we can jump to the destination from i. 
if we reach the index 0 from index n-1 then jump possible.
i → destination and destination → end, then i → end. (transitive reachability)
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		if (n <= 1) return true;
		int destination = n - 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (i + nums[i] >= destination)
			{
				destination = i;
			}
		}
		return destination == 0;
	}

	int jump(const vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return 0;

		int jumps = 0;
		int farthest = 0;
		int currentEnd = 0;

		for (int i = 0; i < n - 1; ++i)
		{
			farthest = max(farthest, i + nums[i]);

			if (i == currentEnd)
			{
				currentEnd = farthest;
				++jumps;
			}
		}

		return jumps;
	}
};