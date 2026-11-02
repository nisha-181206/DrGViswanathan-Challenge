class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Handle empty array
        if (nums.empty()) {
            return {};
        }

        int n = nums.size();

        // Step 1: Mark present numbers
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Step 2: Find missing numbers
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
