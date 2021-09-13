class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxVal{nums[0]}, minVal{nums[0]}, ans{nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            int temp = maxVal;
            maxVal = max({nums[i], maxVal * nums[i], minVal * nums[i]});
            minVal = min({nums[i], temp * nums[i], minVal * nums[i]});
            ans = max(ans, maxVal);
        }
        return ans;
    }
};
