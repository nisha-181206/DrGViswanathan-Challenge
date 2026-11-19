class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        // Handle empty array
        if (n == 0) {
            return {-1, -1};
        }

        int first = -1;
        int last = -1;

        // First Binary Search: Find first occurrence
        int low = 0, high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                // Store current occurrence
                first = mid;

                // Search towards the left
                high = mid - 1;
            }
            else if (nums[mid] < target) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        // Second Binary Search: Find last occurrence
        low = 0;
        high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                // Store current occurrence
                last = mid;

                // Search towards the right
                low = mid + 1;
            }
            else if (nums[mid] < target) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        return {first, last};
    }
};
