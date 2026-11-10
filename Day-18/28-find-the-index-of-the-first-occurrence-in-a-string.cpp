class Solution {
public:

    // Build the LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(const string& needle) {

        int m = needle.size();

        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {

            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        // Condition 1: Needle cannot fit inside haystack
        if (m > n) {
            return -1;
        }

        // Condition 2: Both strings have equal lengths
        if (m == n) {
            return (haystack == needle) ? 0 : -1;
        }

        // Condition 3: Single-character needle
        if (m == 1) {
            size_t pos = haystack.find(needle[0]);
            return (pos == string::npos) ? -1 : static_cast<int>(pos);
        }

        // Build LPS array
        vector<int> lps = buildLPS(needle);

        int i = 0;  // Pointer for haystack
        int j = 0;  // Pointer for needle

        // Search for the first occurrence
        while (i < n) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            // Complete pattern matched
            if (j == m) {
                return i - j;
            }

            // Mismatch handling
            else if (i < n && haystack[i] != needle[j]) {

                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return -1;
    }
};




