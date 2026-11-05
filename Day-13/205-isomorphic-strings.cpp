class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Step 1: Check string lengths
        if (s.length() != t.length()) {
            return false;
        }

        // Handle empty strings defensively
        if (s.empty()) {
            return true;
        }

        // Step 2: Create two mapping arrays
        int mapST[256];
        int mapTS[256];

        // Step 3: Initialize mappings
        fill(mapST, mapST + 256, -1);
        fill(mapTS, mapTS + 256, -1);

        // Step 4: Traverse both strings
        for (int i = 0; i < s.length(); i++) {

            unsigned char a = s[i];
            unsigned char b = t[i];

            // Check forward mapping
            if (mapST[a] != -1 && mapST[a] != b) {
                return false;
            }

            // Check reverse mapping
            if (mapTS[b] != -1 && mapTS[b] != a) {
                return false;
            }

            // Update both mappings
            mapST[a] = b;
            mapTS[b] = a;
        }

        // Step 5: All mappings are valid
        return true;
    }
};
