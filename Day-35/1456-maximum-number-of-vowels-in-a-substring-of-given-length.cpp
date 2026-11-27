class Solution {
public:
    int maxVowels(string s, int k) {

        int n = s.size();

        int count = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {

            char c = s[i];

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                count++;
            }
        }

        int maxi = count;

        // Early termination
        if (maxi == k) return k;

        // Slide the window
        for (int right = k; right < n; right++) {

            char outgoing = s[right - k];
            char incoming = s[right];

            // Remove outgoing vowel
            if (outgoing == 'a' || outgoing == 'e' ||
                outgoing == 'i' || outgoing == 'o' ||
                outgoing == 'u') {
                count--;
            }

            // Add incoming vowel
            if (incoming == 'a' || incoming == 'e' ||
                incoming == 'i' || incoming == 'o' ||
                incoming == 'u') {
                count++;
            }

            maxi = max(maxi, count);

            // Maximum possible answer achieved
            if (maxi == k) return k;
        }

        return maxi;
    }
};
