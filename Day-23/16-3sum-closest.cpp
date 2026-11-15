class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        if (n < 3) return 0;

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        int minDiff = abs(closestSum - target);

        for (int i = 0; i < n - 2; i++) {

            // Minimum possible sum for this fixed element
            int minSum = nums[i] + nums[i + 1] + nums[i + 2];

            // Exact minimum sum found
            if (minSum == target) {
                return target;
            }

            // Update answer using minimum sum
            if (abs(minSum - target) < minDiff) {

                minDiff = abs(minSum - target);
                closestSum = minSum;
            }

            // All future fixed elements can only increase
            if (minSum > target && minDiff <= minSum - target) {
                break;
            }

            // Maximum possible sum for this fixed element
            int maxSum = nums[i] + nums[n - 2] + nums[n - 1];

            if (maxSum == target) {
                return target;
            }

            if (abs(maxSum - target) < minDiff) {

                minDiff = abs(maxSum - target);
                closestSum = maxSum;
            }

            // All sums for this fixed element are below target
            // and cannot improve the current answer
            if (maxSum < target && minDiff <= target - maxSum) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return target;
                }

                int diff = abs(sum - target);

                if (diff < minDiff) {

                    minDiff = diff;
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
