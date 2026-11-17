class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if (nums.empty()) {
            return 0;
        }

        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        mp[0] = 1;

        for (int num : nums) {

            prefixSum += num;

            int required = prefixSum - k;

            if (mp.find(required) != mp.end()) {
                count += mp[required];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};
