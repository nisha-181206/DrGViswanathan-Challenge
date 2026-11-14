class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Check if the array is empty or has fewer than 2 elements
        if (numbers.size() < 2) {
            return {};
        }

        // Initialize two pointers
        int left = 0;
        int right = numbers.size() - 1;

        // Continue while two different elements are available
        while (left < right) {

            // Calculate the sum
            int sum = numbers[left] + numbers[right];

            // If the target sum is found
            if (sum == target) {
                return {left + 1, right + 1};
            }

            // If the current sum is smaller than target
            else if (sum < target) {
                left++;
            }

            // If the current sum is greater than target
            else {
                right--;
            }
        }

        // Return empty vector if no valid pair exists
        return {};
    }
};
