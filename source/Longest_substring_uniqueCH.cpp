// Given a string, find the length of the longest substring without repeating characters.

// Brute force approach: O(n^2) time complexity by checking all substrings and verifying uniqueness, by using a vector of 128 characters to count the frequency of characters in the current substring. 
// ASCII characters are 128, so we can use a vector of size 128 to count the frequency of characters in the current substring. so O(128) is ~ O(1)
// Space complexity: O(1) since the size of the frequency vector is constant (128).

// Optimized approach: O(n) time complexity using a sliding window technique with two pointers and a visited vector of 128 characters to track unique characters in 
// the current window.

//Edge Cases: 
// empty input string, input with single character, string with all unique characters, string with all identical characters, and string with special characters.
// duplicates reappearing outside the current window like abba

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	vector<int> visitedAt(128, -1); // Initialize visited vector to track last index of characters
	int maxLength = 0;
	int left = 0; // Left pointer of the sliding window
	for (int right = 0; right < s.length(); right++)
	{
		char currentChar = s[right];
		if (visitedAt[currentChar] >= left) // If the character is already in the current window
		{
			left = visitedAt[currentChar] + 1; // Move the left pointer to the right of the last occurrence
		}
		visitedAt[currentChar] = right; // Update the last index of the current character
		maxLength = max(maxLength, right - left + 1); // Update max length if needed
	}
	return maxLength;
}