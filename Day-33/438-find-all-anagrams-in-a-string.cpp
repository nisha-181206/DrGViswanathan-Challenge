class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> freq(26, 0);

        for (char c : p) {
            freq[c - 'a']++;
        }

        int remaining = m;
        int left = 0;

        for (int right = 0; right < n; right++) {

            int in = s[right] - 'a';

            if (freq[in] > 0) {
                remaining--;
            }

            freq[in]--;

            // Maintain fixed window size
            if (right - left + 1 > m) {

                int out = s[left] - 'a';

                freq[out]++;

                if (freq[out] > 0) {
                    remaining++;
                }

                left++;
            }

            // Check for anagram
            if (right - left + 1 == m &&
                remaining == 0) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};


