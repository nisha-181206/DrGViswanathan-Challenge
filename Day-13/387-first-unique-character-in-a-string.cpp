class Solution {
public:
    int firstUniqChar(string s) {

        // Step 1: Create frequency array
        int freq[26] = {0};

        // Step 2: Count character frequencies
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 3: Find first non-repeating character
        for (int i = 0; i < s.length(); i++) {

            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // Step 4: No unique character found
        return -1;
    }
};
