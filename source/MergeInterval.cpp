// Given a collection of intervals, merge all overlapping intervals.
// Sorting the intervals by their start time and then merging them is a common approach to solve this problem.
// Time complexity: O(n log n) due to sorting, where n is the number of intervals.
// Space complexity: O(n) for the output list of merged intervals.

// Why Sorting is necessary?
// Sorting ensures that intervals are processed in order, making it easier to detect and merge overlapping intervals.

// How to handle in production with 50M intervals?
// Step 1 : instead of vector<vector<int>>, use struct to handle heap memory more efficiently and improve readability 
// Step 2 : Different sorting techniques time sort or bucket sort 
//For large datasets, consider using an efficient sorting algorithm (like Timsort) 
// and optimizing memory usage by processing intervals in batches or using external sorting techniques 
// if they cannot fit into memory.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
	if (intervals.empty())
		return {};
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> output;

	for(const auto& interval : intervals)
	{
		if (output.empty() || output.back()[1] < interval[0])
		{
			output.push_back(interval);
		}
		else
		{
			output.back()[1] = max(output.back()[1], interval[1]);
		}
	}
	return output;
}