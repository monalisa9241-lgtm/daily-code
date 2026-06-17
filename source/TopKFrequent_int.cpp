#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std; 


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        vector<int> result;
        result.reserve(k);

        for (int& num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for (auto& pair : freq)
        {
            minheap.push({ pair.second, pair.first });
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }
        while (!minheap.empty())
        {
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        return result;
    }
};