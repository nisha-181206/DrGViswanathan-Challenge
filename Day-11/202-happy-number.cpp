class Solution {
public:

    // Function to calculate sum of squares of digits
    int getNext(int n) {

        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            sum += digit * digit;

            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        while (true) {

            // Slow moves one step
            slow = getNext(slow);

            // Fast moves two steps
            fast = getNext(getNext(fast));

            // Happy number condition
            if (fast == 1) {
                return true;
            }

            // Cycle detected
            if (slow == fast) {
                return false;
            }
        }
    }
};
