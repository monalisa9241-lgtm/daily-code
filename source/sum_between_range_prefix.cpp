// Given an int array, write a fucntion to return the sum of values between two given indices (inclusive) in the array.
// The function will be called multiple times with different indices, so optimize for multiple calls.

#include <vector>
#include <numeric>

using namespace std;

class solution {
public:
	solution(const vector<int>& nums) {
		prefix_sum.resize(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); ++i) {
			prefix_sum[i + 1] = prefix_sum[i] + nums[i];
		}
	}
	int sumRange(int left, int right) {
		return prefix_sum[right + 1] - prefix_sum[left];
	}
private:
	vector<int> prefix_sum;
};