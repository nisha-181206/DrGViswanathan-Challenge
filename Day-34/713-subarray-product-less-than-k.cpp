class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();

        if (k <= 1)
            return 0;

        int left = 0;
        long long product = 1;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Expand the window
            product *= nums[right];

            // Shrink while product is invalid
            while (product >= k) {

                product /= nums[left];
                left++;
            }

            // Count all valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
    }
};
