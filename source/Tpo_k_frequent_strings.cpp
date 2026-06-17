// given an array of strings, return the k most frequent strings in the array. The returned answer should be sorted by the frequency from highest to lowest. 
// If two different strings have the same frequency, sort them in lexicographical order.
// k can be > unique strings in the array, in which case return all the unique strings.

//use unordered_map to count frequency of each string, then use a min-heap (priority_queue) to keep track of the top k frequent strings.
// use a custom comparator for the priority queue to sort by frequency and lexicographical order. 
// Finally, extract the top k elements from the min-heap and reverse the result to get the correct order.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> 

using namespace std;

class Solution {
public:

    struct Node {
        string word;
        int freq;
    };

    struct Compare {
        bool operator()(const Node& a, const Node& b) {

            // Smaller frequency = worse
            if (a.freq != b.freq)
                return a.freq > b.freq;

            // Lexicographically larger = worse
            return a.word < b.word;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        if (words.empty() || k == 0)
            return {};

        unordered_map<string, int> freq;

        for (const string& word : words)
            freq[word]++;

        // Min heap
        priority_queue<Node, vector<Node>, Compare> pq;

        for (const auto& kvp : freq)
        {
            pq.push({ kvp.first, kvp.second });

            if (static_cast<int>(pq.size()) > k)
                pq.pop();
        }

        vector<Node> temp;
        temp.reserve(pq.size());

        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }

        // Final ordering:
        // frequency descending
        // lexicographically ascending
        std::sort(temp.begin(), temp.end(),
            [](const Node& a, const Node& b) {

                if (a.freq != b.freq)
                    return a.freq > b.freq;

                return a.word < b.word;
            });

        vector<string> result;

        for (const auto& node : temp)
            result.push_back(node.word);

        return result;
    }
};