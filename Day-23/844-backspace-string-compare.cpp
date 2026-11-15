class Solution {
public:
    bool backspaceCompare(string s, string t) {

        // Condition 1: Both strings are empty
        if (s.empty() && t.empty()) {
            return true;
        }

        // Condition 2: Only one string is empty
        if (s.empty() || t.empty()) {
            return false;
        }

        int i = static_cast<int>(s.size()) - 1;
        int j = static_cast<int>(t.size()) - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {

            // Process string s
            while (i >= 0) {

                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Process string t
            while (j >= 0) {

                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            // Condition 3: Compare valid characters
            if (i >= 0 && j >= 0) {

                if (s[i] != t[j]) {
                    return false;
                }
            }

            // Condition 4: One string has remaining characters
            else if (i >= 0 || j >= 0) {
                return false;
            }

            // Move both pointers backward
            i--;
            j--;
        }

        // Condition 5: Both processed strings are equal
        return true;
    }
};
