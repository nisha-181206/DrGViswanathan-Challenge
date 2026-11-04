class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Step 1: Check string lengths
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        // Step 2: Create frequency array
        int freq[26] = {0};

        // Step 3: Count characters in magazine
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Step 4: Check required characters
        for (char ch : ransomNote) {

            freq[ch - 'a']--;

            if (freq[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
