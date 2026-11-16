class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        if (n < 4)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Minimum possible sum is greater than target
            if ((long long)nums[i] + nums[i + 1] +
                nums[i + 2] + nums[i + 3] > target)
                break;

            // Maximum possible sum is smaller than target
            if ((long long)nums[i] + nums[n - 1] +
                nums[n - 2] + nums[n - 3] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Minimum possible sum for this pair
                if ((long long)nums[i] + nums[j] +
                    nums[j + 1] + nums[j + 2] > target)
                    break;

                // Maximum possible sum for this pair
                if ((long long)nums[i] + nums[j] +
                    nums[n - 1] + nums[n - 2] < target)
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] +
                                    nums[j] +
                                    nums[left] +
                                    nums[right];

                    if (sum < target) {
                        left++;
                    }

                    else if (sum > target) {
                        right--;
                    }

                    else {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        // Skip duplicate third elements
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // Skip duplicate fourth elements
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        if (n < 4)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Minimum possible sum is greater than target
            if ((long long)nums[i] + nums[i + 1] +
                nums[i + 2] + nums[i + 3] > target)
                break;

            // Maximum possible sum is smaller than target
            if ((long long)nums[i] + nums[n - 1] +
                nums[n - 2] + nums[n - 3] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Minimum possible sum for this pair
                if ((long long)nums[i] + nums[j] +
                    nums[j + 1] + nums[j + 2] > target)
                    break;

                // Maximum possible sum for this pair
                if ((long long)nums[i] + nums[j] +
                    nums[n - 1] + nums[n - 2] < target)
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] +
                                    nums[j] +
                                    nums[left] +
                                    nums[right];

                    if (sum < target) {
                        left++;
                    }

                    else if (sum > target) {
                        right--;
                    }

                    else {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        // Skip duplicate third elements
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // Skip duplicate fourth elements
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
