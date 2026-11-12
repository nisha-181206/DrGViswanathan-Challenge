class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        // Handle empty string
        if (n == 0)
            return 0;

        // Store the last seen index of each ASCII character
        vector<int> lastSeen(128, -1);

        int left = 0;
        int maxLen = 0;

        // Expand the sliding window
        for (int right = 0; right < n; right++) {

            unsigned char ch = s[right];

            // Check if the character is repeated
            if (lastSeen[ch] >= left) {

                // Move left pointer past the previous occurrence
                left = lastSeen[ch] + 1;
            }

            // Update the latest occurrence
            lastSeen[ch] = right;

            // Calculate the current window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
