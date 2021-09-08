class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> mySet;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    mySet.emplace(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return vector<vector<int>>(mySet.begin(),mySet.end());
    }
};
