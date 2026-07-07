// given a string text and a pattern, find the maximum number of times the pattern can be formed using the characters in the text. 
// Each character in the text can only be used once.
// For example, if the text is "ababc" and the pattern is "abc", the maximum number of times the pattern can be formed is 1.

/*
* Questions to ask in interview
* - What is the maximum length of the text and pattern?
* - Are the characters in the text and pattern case sensitive?
* - Can the pattern contain characters that are not present in the text?
* - Can the text contain characters that are not present in the pattern?
* - What should be the output if the pattern cannot be formed from the text?
* - Can the pattern be formed from the text using characters that are in the pattern but with different cases?
* - Can the pattern be formed from the text using characters that are in the pattern but with different encodings (e.g. ASCII, Unicode)?
* - assuming the text and pattern are in English.
*/

/*
* Edge Cases
* - The text is empty and the pattern is not empty. 
* - The pattern is empty and the text is not empty.
* - Both the text and pattern are empty.
* - The text and pattern are the same.
* - The text contains all the characters in the pattern but in different frequencies.
* - The text contains some characters in the pattern but not all.
* - The text contains characters that are not in the pattern.
* - The text and pattern contain the same characters but in different cases (e.g. "a" and "A").
*/

/*
* Algorithm 
* Store the frequency of all the characters in text in freqInText and the frequency of all the characters in pattern in freqInPattern.
* Find the potential of all the lowercase English letters. The potential will be equal to its frequency in text divided by its frequency in pattern.
* Return the minimum potential of a character.
*/

// Time Complexity : O(N+M) - text : N , pattern: M
// Space: O(k) k = 26 -> so its constant

#include <iostream>

using namespace std;

int findMaxNumberOfPattern(string text, string pattern) {
	int n = text.length(), m = pattern.length(), answer = INT_MAX;
	int freqInText[26] = { 0 }, freqInPattern[26] = { 0 };

    // Frequency of characters in text.
    for (int i = 0; i < n; i++) {
		freqInText[text[i] - 'a']++; // here it is case sensitive, so we are assuming that the text and 
        // pattern are in lowercase. for uppercase, we can use text[i] - 'A' and pattern[i] - 'A'.
		// if the text and pattern are in mixed case, we can use tolower(text[i]) - 'a' and tolower(pattern[i]) - 'a'.
    }
    // Frequency of characters in pattern.
    for (int i = 0; i < m; i++) {
        freqInPattern[pattern[i] - 'a']++;
    }

    // Compare the maximum string that can be produced
    // considering one character at a time.
    for (int i = 0; i < 26; i++) {
        // Do not divide by zero.
        if (freqInPattern[i]) {
            answer = min(answer, freqInText[i] / freqInPattern[i]);
        }
    }

    return answer;
}

