class Solution {
public:
    int mySqrt(int x) {

        // Handle edge cases
        if (x == 0 || x == 1) {
            return x;
        }

        // Initial approximation
        long long r = x;

        // Continue until the integer square root is reached
        while (r > x / r) {

            // Apply Newton's Method
            r = (r + x / r) / 2;
        }

        // Return the integer square root
        return (int)r;
    }
};
