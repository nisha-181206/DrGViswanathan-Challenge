class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Check if the array is empty
        if (nums.empty()) {
            return;
        }

        int n = nums.size();

        // Handle rotations greater than array size
        k = k % n;

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
