class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int zeroCount = 0;
        int maxi = 0;

        for (int right = 0; right < n; right++) {

            // Count zeros in the current window
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Maintain at most one zero
            while (zeroCount > 1) {

                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            // Delete exactly one element
            maxi = max(maxi, right - left);
        }

        return maxi;
    }
};
