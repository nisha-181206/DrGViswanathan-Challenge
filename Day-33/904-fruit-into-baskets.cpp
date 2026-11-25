class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int left = 0;
        int maxi = 0;

        int type1 = -1;
        int type2 = -1;

        int last1 = -1;
        int last2 = -1;

        for (int right = 0; right < n; right++) {

            int curr = fruits[right];

            if (curr == type1) {
                last1 = right;
            }
            else if (curr == type2) {
                last2 = right;
            }
            else {

                if (last1 < last2) {
                    left = last1 + 1;
                    type1 = curr;
                    last1 = right;
                }
                else {
                    left = last2 + 1;
                    type2 = curr;
                    last2 = right;
                }
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};


