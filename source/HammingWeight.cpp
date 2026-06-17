// Given a positive integer n, write a function that returns the number of 
// set bits in its binary representation (also known as the Hamming weight).

#include <cstdint>

using namespace std;

// Approach: Brian Kernighan's algorithm
// Time: O(k) where k = number of set bits
// Space: O(1)
// Each iteration clears the lowest set bit: n & (n - 1)
int hammingWeight(int n)
{
	// Treat n as unsigned to avoid sign-extension issues with right-shift
	uint32_t num = static_cast<uint32_t>(n);
	int count = 0;

	while (num)
	{
		num &= (num - 1); // Clear the lowest set bit
		++count;
	}

	return count;
}
