class Solution {
public:
    string reverseWords(string s) {

        // Condition 1: Handle empty string
        if (s.empty())
            return "";

        int n = s.size();
        int i = 0, j = 0;

        // Step 1: Remove extra spaces using two pointers
        while (i < n) {

            // Skip leading and consecutive spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            // Stop if no characters remain
            if (i >= n)
                break;

            // Add exactly one space between words
            if (j > 0) {
                s[j++] = ' ';
            }

            // Copy the current word
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }

        // Remove unused characters
        s.resize(j);

        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each individual word
        int start = 0;

        for (int k = 0; k <= s.size(); k++) {

            // Identify the end of each word
            if (k == s.size() || s[k] == ' ') {

                reverse(s.begin() + start,
                        s.begin() + k);

                start = k + 1;
            }
        }

        return s;
    }
};
