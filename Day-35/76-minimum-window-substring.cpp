class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        if (m < n) return "";

        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int missing = n;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < m; right++) {

            char c = s[right];

            if (need[c] > 0) {
                missing--;
            }

            need[c]--;

            // When all required characters are found
            while (missing == 0) {

                int len = right - left + 1;

                // Update minimum window
                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                // Remove the leftmost character
                char ch = s[left];

                need[ch]++;

                if (need[ch] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};
