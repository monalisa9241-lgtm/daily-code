// Given a list of meeting time intervals consisting of start and end times, determine if a person could attend all meetings.
// Requirements:
/*
1. Input Constraints 
	1 <= intervals.length <= 10 ^ 5
	0 <= start_i < end_i <= 10 ^ 6
2. Input may be empty. If input is empty, return true.
3. Only return a boolean indicating whether all meetings can be attended.
4. A meeting ending at time t and another starting at time t do not overlap.So[1, 5] and [5, 8] is valid.
5. Input is not guaranteed to be sorted.
*/

//Brute Force Approach: O(n^2) time, O(1) space - compairing each meeting with every other meeting to check for overlaps.
// Overlap codition: min(end1, end2) > max(start1, start2)

// Use sorting approach: O(n log n) time, O(1) space - sort the meetings by start time and then check for overlaps in a single pass.
// Ignoring implementation details of introsort stack frames, auxiliary space is effectively constant from the algorithm perspective.
// Overlap condition: end of current meeting > start of next meeting

// Edge Cases: empty input, single meeting, meetings that end and start at the same time, unsorted input. input with same start time but different end times. input with same end time but different start times.
#include <vector>
#include <algorithm>

using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
	if (intervals.empty())
		return true; // No meetings, so can attend all (trivially true)
	sort(intervals.begin(), intervals.end());

	for (size_t i = 1; i < intervals.size(); ++i) {
		if (intervals[i][1] > intervals[i - 1][0]) {
			return false; // Overlapping meetings found
		}
	}
	return true; // No overlapping meetings
}