class Solution {
public:
    int maxArea(vector<int>& height) {

        // Handle empty array and insufficient elements
        int n = height.size();

        if (n < 2) {
            return 0;
        }

        int left = 0;
        int right = n - 1;

        int maxWater = 0;

        while (left < right) {

            int minHeight = min(height[left], height[right]);

            // Calculate current container area
            int currentArea = (right - left) * minHeight;

            // Update maximum area
            maxWater = max(maxWater, currentArea);

            // Move the shorter boundary and skip
            // heights that cannot improve the area
            if (height[left] <= height[right]) {

                while (left < right && height[left] <= minHeight) {
                    left++;
                }

            }
            else {

                while (left < right && height[right] <= minHeight) {
                    right--;
                }
            }
        }

        return maxWater;
    }
};
