class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {

            // Handle both possible elements according to constraints
            if (nums[right] == 0) {
                zeros++;
            }
            else if (nums[right] == 1) {
                // No change in zero count
            }

            // Shrink window if zeros exceed k
            while (zeros > k) {

                if (nums[left] == 0) {
                    zeros--;
                }
                else if (nums[left] == 1) {
                    // No change in zero count
                }

                left++;
            }

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
