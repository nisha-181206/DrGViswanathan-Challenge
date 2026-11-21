class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();

        if (m == 0)
            return false;

        int n = matrix[0].size();

        if (n == 0)
            return false;

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Convert 1D index into 2D coordinates
            int row = mid / n;
            int col = mid % n;

            // Target found
            if (matrix[row][col] == target)
                return true;

            // Search right half
            else if (matrix[row][col] < target)
                left = mid + 1;

            // Search left half
            else
                right = mid - 1;
        }

        return false;
    }
};
