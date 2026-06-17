// Count the number of special charachters II
// Given a string word, a letter c is called special if it appears in lowercase and uppercase in word 
// and every lowercase letter appears before its uppercase in word. Return the number of special letters in word.

// Hint : For each character c, store the first occurrence of its uppercase and the last occurrence of its lowercase.

#include <string>
#include <unordered_map>

using namespace std;

class solution {
	int numSpecialCharsII_map(string word) {
		int count = 0;
		unordered_map<char, pair<int, int>> char_positions; // char -> (first_uppercase_pos, last_lowercase_pos)
		for (int i = 0; i < word.size(); ++i) {
			char c = word[i];
			if (isupper(c)) {
				char_positions[tolower(c)].first = min(char_positions[tolower(c)].first, i);
			} else {
				char_positions[c].second = max(char_positions[c].second, i);
			}
		}
		for (const auto& entry : char_positions) {
			if (entry.second.first != 0 && entry.second.second != 0 && entry.second.second < entry.second.first) {
				++count;
			}
		}
		return count;
	}

	int numSpecialCharsII_26(string word) {
		vector<int> firstUpper(26, INT_MAX);
		vector<int> lastLower(26, -1);

		for (int i = 0; i < word.size(); ++i) {
			char c = word[i];

			if (islower(c)) {
				lastLower[c - 'a'] = i;
			}
			else {
				firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
			}
		}

		int count = 0;

		for (int i = 0; i < 26; ++i) {
			if (lastLower[i] != -1 &&
				firstUpper[i] != INT_MAX &&
				lastLower[i] < firstUpper[i]) {
				++count;
			}
		}

		return count;
	}

	int numSpecialCharsII_state(string word) {
		vector<int> state(26, 0);

		// 0 -> unseen
		// 1 -> lowercase seen
		// 2 -> valid special
		// 3 -> invalid

		for (char c : word) {
			int idx = tolower(c) - 'a';

			if (islower(c)) {
				if (state[idx] == 0) {
					state[idx] = 1;
				}
				else if (state[idx] == 2) {
					state[idx] = 3; // lowercase after uppercase -> invalid
				}
			}
			else {
				if (state[idx] == 1) {
					state[idx] = 2;
				}
				else if (state[idx] == 0) {
					state[idx] = 3; // uppercase before lowercase
				}
			}
		}

		int count = 0;

		for (int s : state) {
			if (s == 2)
				++count;
		}

		return count;
	}
};