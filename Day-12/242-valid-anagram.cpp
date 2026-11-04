class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Check if either string is empty
        if (s.empty() || t.empty()) {
            return false;
        }

        // Step 2: Check if lengths are different
        if (s.length() != t.length()) {
            return false;
        }

        // Step 3: Create an unordered map
        unordered_map<char, int> freq;

        // Step 4: Count characters in s
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 5: Decrease character frequencies in t
        for (char ch : t) {
            freq[ch]--;

            // Character is not available
            if (freq[ch] < 0) {
                return false;
            }
        }

        // Step 6: All frequencies must match
        return true;
    }
};
