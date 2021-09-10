class Solution {
public:
//     int rob(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         if (nums.size() == 2) return max(nums[0],nums[1]);
//         vector<int> cache(nums.size(),-1);
        
//         return max(maxProfitFromPos(nums, 0,cache), maxProfitFromPos(nums,1,cache));
//     }
    
//     int maxProfitFromPos (vector<int>& nums, int pos, vector<int>& cache) {
//         if (pos >= nums.size()) return 0;
//         if (cache[pos] != -1) return cache[pos];
//         cache[pos] = nums[pos] + max(maxProfitFromPos(nums, pos+2,cache), maxProfitFromPos(nums,pos+3,cache));
        
//         return cache[pos];
//     }
    
//     int rob(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         if (nums.size() == 2) return max(nums[0],nums[1]);  
//         int n = nums.size();
        
//         nums[2] += nums[0];
//         for (int i = 3; i < n; ++i) {
//             nums[i] += max(nums[i-2], nums[i-3]);
//         }
        
//         return max(nums[n-1], nums[n-2]);
//     }
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);  
        
        // nums[i] represent the maximum at this index
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() ; i++) {
            nums[i] = max(nums[i-1], nums[i-2] + nums[i]);
        }
        return nums.back();
    }
};
