class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax{-9999999};
        int cumSum{};
        for (int num: nums) {
            cumSum += num;
            if (cumSum > curMax) {
                curMax = cumSum;
            }
            if (cumSum < 0)
                cumSum = 0;
        }
        return curMax;
    }
};
