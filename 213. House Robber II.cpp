class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);  
        
        int oneToLastMinus1 = helper(vector<int>(nums.begin(), prev(nums.end(),1)));
        int twoToLast = helper(vector<int>(next(nums.begin(),1),nums.end()));
        return max(oneToLastMinus1, twoToLast);

    }
    
    int helper(vector<int>nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);  
        int n = nums.size();
        
        nums[2] += nums[0];
        for (int i = 3; i < n; ++i) {
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        return max(nums[n-1], nums[n-2]);        
    }
};
