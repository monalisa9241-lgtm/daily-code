// group anagrams
//hash map + frequency count : O(nk) time, O(nk) space 
//			- performance is better than sorting approach, especially for long strings with many characters
//hash map + sorting : O(nk log k) time, O(nk) space 
//			- Readability is better than frequency count approach, especially for short strings with few characters
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;	

class Solution {
public:
	vector<vector<string>> groupAnagramsFrequency(vector<string>& strs) {
		unordered_map<string, vector<string>> anagramGroups;
		for (const string& word : strs) {
			string key = getHash(word);
			anagramGroups[key].push_back(word);
		}
		vector<vector<string>> result;
		for (auto& pair : anagramGroups) {
			result.push_back(move(pair.second));
		}
		return result;
	}
	string getHash(const string& word) {
		vector<int> charCount(26, 0);
		for (char c : word) {
			charCount[c - 'a']++;
		}
		string hash;
		for (int count : charCount) {
			hash += to_string(count) + '#'; // Use '#' as a separator
		}
		return hash;
	}

	vector<vector<string>> groupAnagramsSort(vector<string>& strs) {
		unordered_map<string, vector<string>> anagramGroups;
		for (const string& word : strs) {
			string key = word;
			sort(key.begin(), key.end());
			anagramGroups[key].push_back(word);
		}
		vector<vector<string>> result;
		for (auto& pair : anagramGroups) {
			result.push_back(move(pair.second));
		}
		return result;
	}
};