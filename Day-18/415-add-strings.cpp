class Solution {
public:
    string addStrings(string num1, string num2) {

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        int carry = 0;

        string result;
        result.reserve(max(num1.size(), num2.size()) + 1);

        // Process digits from right to left
        while (i >= 0 || j >= 0 || carry > 0) {

            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            // Add corresponding digits and carry
            int sum = digit1 + digit2 + carry;

            // Extract the current digit
            result.push_back('0' + (sum % 10));

            // Calculate the next carry
            carry = sum / 10;

            // Move to the previous digits
            i--;
            j--;
        }

        // Reverse to obtain the correct order
        reverse(result.begin(), result.end());

        return result;
    }
};
