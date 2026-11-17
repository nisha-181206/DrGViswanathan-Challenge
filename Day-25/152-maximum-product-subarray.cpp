
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();

        int prefix = 1;
        int suffix = 1;

        int answer = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (prefix == 0) {
                prefix = 1;
            }

            if (suffix == 0) {
                suffix = 1;
            }

            prefix *= nums[i];

            suffix *= nums[n - 1 - i];

            answer = max(answer, max(prefix, suffix));
        }

        return answer;
    }
};
