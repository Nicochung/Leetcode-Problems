class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit{};
        int curMin{INT_MAX};
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < curMin) {
                curMin = prices[i];
            }
            maxProfit = max(maxProfit, prices[i]-curMin);
        }
        return maxProfit;
    }
};
