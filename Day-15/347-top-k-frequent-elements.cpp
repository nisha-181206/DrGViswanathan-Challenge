class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies using the given value range
        array<int, 20001> freq{};

        for (int num : nums) {
            freq[num + 10000]++;
        }

        // Step 2: Store unique elements with their frequencies
        vector<pair<int, int>> elements;
        elements.reserve(20001);

        for (int i = 0; i <= 20000; i++) {

            if (freq[i] > 0) {
                elements.push_back({freq[i], i - 10000});
            }
        }

        // Step 3: Select the k highest-frequency elements
        if (k < elements.size()) {

            nth_element(
                elements.begin(),
                elements.begin() + k,
                elements.end(),
                [](const auto& a, const auto& b) {
                    return a.first > b.first;
                }
            );
        }

        // Step 4: Construct the answer
        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; i++) {
            ans.push_back(elements[i].second);
        }

        return ans;
    }
};
