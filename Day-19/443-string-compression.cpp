class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        // Handle empty array
        if (n == 0) {
            return 0;
        }

        int read = 0;
        int write = 0;

        while (read < n) {

            char current = chars[read];
            int count = 0;

            // Count consecutive occurrences
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write frequency if greater than 1
            if (count > 1) {

                string freq = to_string(count);

                for (char digit : freq) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};
