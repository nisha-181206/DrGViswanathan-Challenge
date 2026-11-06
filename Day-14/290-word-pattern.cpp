class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        stringstream ss(s);
        string word;

        int i = 0;

        while (ss >> word) {

            // Condition 1: Check for extra words
            if (i >= pattern.length()) {
                return false;
            }

            char ch = pattern[i];

            // Condition 2: Check character-to-word mapping
            if (charToWord.count(ch) && charToWord[ch] != word) {
                return false;
            }

            // Condition 3: Check word-to-character mapping
            if (wordToChar.count(word) && wordToChar[word] != ch) {
                return false;
            }

            // Store both mappings
            charToWord[ch] = word;
            wordToChar[word] = ch;

            i++;
        }

        // Condition 4: Check for missing words
        return i == pattern.length();
    }
};
