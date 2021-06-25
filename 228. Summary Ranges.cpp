class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int startNum{};
        bool inProgress = false;
        int n = nums.size();
        if (n == 0) return ans;
        
        for (int i = 0; i < n - 1; ++i) {
            if (inProgress) {
                if (nums[i] + 1 != nums[i+1]) {
                    // Construct string to be append, startNum -> nums[i]
                    ans.emplace_back(to_string(startNum)+"->"+to_string(nums[i]));
                    inProgress = false;
                }
            } else {
                if (nums[i] + 1 == nums[i+1]) {
                    // First number
                    startNum = nums[i];
                    inProgress = true;
                } else {
                    // Independet number
                    ans.emplace_back(to_string(nums[i]));
                }          
            }
        }
        
        if (inProgress) {
            ans.emplace_back(to_string(startNum)+"->"+to_string(nums[n-1]));
        } else {
            ans.emplace_back(to_string(nums[n-1]));
        }
        
        return ans;
    }
};
