// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

//The doctor advised Alice to only eat n / 2 of the candies she has(n is always even).Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

//Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int distributeCandies(vector<int>& candyType) {
	int n = candyType.size();
	unordered_set<int> unique_candies(candyType.begin(), candyType.end());
	return std::min(static_cast<int>(unique_candies.size()), n / 2);
}