class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size());

        for (const string& s : strs) {

            // Count lowercase character frequencies
            string key(26, '\0');

            for (char c : s) {
                key[c - 'a']++;
            }

            // Group strings having the same frequency
            mp[key].push_back(s);
        }

        // Collect the anagram groups
        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& it : mp) {
            ans.push_back(move(it.second));
        }

        return ans;
    }
};
