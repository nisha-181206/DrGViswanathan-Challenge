class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: Handle empty input
        if (intervals.empty()) {
            return {};
        }

        // Step 2: Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Step 3: Create result vector
        vector<vector<int>> ans;

        // Reserve capacity to avoid repeated reallocations
        ans.reserve(intervals.size());

        // Step 4: Traverse all intervals
        for (const auto& interval : intervals) {

            // Case 1: No overlap
            if (ans.empty() || interval[0] > ans.back()[1]) {

                ans.push_back(interval);
            }

            // Case 2: Overlapping intervals
            else {

                // Extend the ending point
                ans.back()[1] = max(
                    ans.back()[1],
                    interval[1]
                );
            }
        }

        // Step 5: Return merged intervals
        return ans;
    }
};
