class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans{};
        for (int i = 0; i < nums.size() / 2; ++i) {
            int freq = nums[2*i];
            int val = nums[2*i+1];
            for (int j = 0; j < freq; ++j) {
                ans.emplace_back(val);
            }
        }
        return ans;
    }
};
