class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        int freq[26] = {0};

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Add the current character
            freq[s[right] - 'A']++;

            // Maintain the highest frequency
            maxFreq = max(maxFreq,
                          freq[s[right] - 'A']);

            // Shrink the window if replacements exceed k
            if ((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;

                left++;
            }

            // Update maximum window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
