class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        if (m > n) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Calculate frequencies
        for (int i = 0; i < m; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Count matching frequencies
        int matches = 0;

        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) {
                matches++;
            }
        }

        if (matches == 26) {
            return true;
        }

        // Slide the window
        for (int right = m; right < n; right++) {

            // Outgoing character
            int leftIndex = s2[right - m] - 'a';

            if (freq1[leftIndex] == freq2[leftIndex]) {
                matches--;
            }

            freq2[leftIndex]--;

            if (freq1[leftIndex] == freq2[leftIndex]) {
                matches++;
            }

            // Incoming character
            int rightIndex = s2[right] - 'a';

            if (freq1[rightIndex] == freq2[rightIndex]) {
                matches--;
            }

            freq2[rightIndex]++;

            if (freq1[rightIndex] == freq2[rightIndex]) {
                matches++;
            }

            if (matches == 26) {
                return true;
            }
        }

        return false;
    }
};
