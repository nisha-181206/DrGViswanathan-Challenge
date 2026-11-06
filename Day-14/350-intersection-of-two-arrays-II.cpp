class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;
        vector<int> result;

        // Step 1: Count frequencies of nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Step 2: Traverse nums2
        for (int num : nums2) {

            // Find the element in the map
            auto it = freq.find(num);

            // Condition 1: Element must exist
            // Condition 2: Frequency must be positive
            if (it != freq.end() && it->second > 0) {

                result.push_back(num);

                // Condition 3: Decrease available frequency
                it->second--;

                // Condition 4: Remove exhausted element
                if (it->second == 0) {
                    freq.erase(it);
                }
            }
        }

        return result;
    }
};
