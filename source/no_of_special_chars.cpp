// Given a string 'word', a letter is called a special if it appears both in lowercase and uppercase in the word. Return the number of special letters in word.
// Return the number of special letters in word.

#include <string>
#include <unordered_set>

using namespace std;
class solution {
	int numSpecialChars(std::string word) {
		int count = 0;
		unordered_set<char> letters(word.begin(), word.end());
		for (char c = 'a'; c <= 'z'; ++c) {
			if(letters.count(c) > 0 && letters.count(c - 'a' + 'A') > 0) {
				++count;
			}
		}
		return count;
	}
};