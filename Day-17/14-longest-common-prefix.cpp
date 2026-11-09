class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

         // Handle an empty first string
        if (strs[0].empty())
            return "";

        // Traverse characters of the first string
        for (int i = 0; i < strs[0].size(); i++) {

            char ch = strs[0][i];

            // Compare with remaining strings
            for (int j = 1; j < n; j++) {

                // Check whether current string has this index
                if (i >= strs[j].size())
                    return strs[0].substr(0, i);

                // Check character mismatch
                if (strs[j][i] != ch)
                    return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};

        
  
