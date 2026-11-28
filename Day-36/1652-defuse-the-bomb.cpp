class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        vector<int> ans(n, 0);

        // Case 1: k = 0
        if (k == 0) {
            return ans;
        }

        int steps = abs(k);
        int sum = 0;

        // Case 2: Positive k
        if (k > 0) {

            // Calculate the initial window
            for (int j = 1; j <= k; j++) {
                sum += code[j % n];
            }

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                // Remove outgoing element
                sum -= code[(i + 1) % n];

                // Add incoming element
                sum += code[(i + k + 1) % n];
            }
        }

        // Case 3: Negative k
        else {

            // Calculate the initial window
            for (int j = 1; j <= steps; j++) {

                int idx = (n - j) % n;

                sum += code[idx];
            }

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                // Remove outgoing element
                sum -= code[(i - steps + n) % n];

                // Add incoming element
                sum += code[i];
            }
        }

        return ans;
    }
};
