// distribute the candies to the children such that each child gets at least one candy and children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?


//Edge case
//uniform, increasing, decreasing, mixed patterns
//Initialize with base case of 1 candy per child, then adjust based on ratings
//left ->right pass to ensure right neighbor condition, then right -> left pass to ensure left neighbor condition

#include <vector>
#include <iostream>

using namespace std;	

class solution
{
public:
	solution();
	~solution();

	int candyCountWithExtraSpace(vector<int>& ratings)
	{
		int n = ratings.size();
		if (n <= 1) return n;
		vector<int> candies(n, 1); // Initialize all children with 1 candy
		// Left to right pass
		for (int i = 1; i < n; ++i)
		{
			if (ratings[i] > ratings[i - 1])
			{
				candies[i] = candies[i - 1] + 1;
			}
		}
		// Right to left pass
		for (int i = n - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1])
			{
				candies[i] = max(candies[i], candies[i + 1] + 1);
			}
		}
		int totalCandies = 0;
		for (int candy : candies)
		{
			totalCandies += candy;
		}
		return totalCandies;
	}

	//candyCOuntUpDownSlope : 
	//On an increasing slope, each child must get 1 more candy than the previous one. This ensures all local rising conditions are satisfied.
	//On a decreasing slope, the same logic applies in reverse, so each child gets 1 more than the next.
	//At a peak, both conditions apply.
	// By subtracting the smaller overlap, we avoid double - counting but still guarantee the peak has more candies than both neighbors.

	int candyCountUpDownSlope(vector<int>& ratings)
	{
		int n = ratings.size();
		int total = n;
		int i = 1;

		//traverse from left to right
		while (i < n)
		{
			if (ratings[i] == ratings[i - 1])
			{
				i++;
				continue;
			}
			int peak = 0; //to find the increasing sequence
			while (i <n && ratings[i] > ratings[i - 1]) {
				peak++;
				total += peak;
				i++;
			}
			if (i == n) return total;

			//to find the decreaing sequence
			int valley = 0;
			while (i < n && ratings[i] < ratings[i - 1]) {
				valley++;
				total += valley;
				i++;
			}
			//remove the extra candy added twice
			total -= min(peak, valley);
		}
		return total;
	}

private:

};

solution::solution()
{
}

solution::~solution()
{
}