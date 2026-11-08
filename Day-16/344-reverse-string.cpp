class Solution {
public:
    void reverseString(vector<char>& s) {

        int n = s.size();

        // Initialize two pointers
        int left = 0;
        int right = n - 1;

        // Reverse the array in-place
        while (left < right) {

            // Swap characters at opposite positions
            swap(s[left], s[right]);

            // Move pointers towards the center
            left++;
            right--;
        }
    }
};
