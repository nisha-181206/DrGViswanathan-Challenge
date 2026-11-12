class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();

        // Handle empty string
        if (n == 0)
            return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; i++) {

            // Odd-length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                int len = right - left + 1;

                if (len > maxLength) {
                    maxLength = len;
                    start = left;
                }

                left--;
                right++;
            }

            // Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                int len = right - left + 1;

                if (len > maxLength) {
                    maxLength = len;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};
