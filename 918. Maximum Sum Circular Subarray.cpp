class Solution {
public:
    // https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
    int maxSubarraySumCircular(vector<int>& nums) {
        int total{}, locMin{}, gloMin{nums[0]}, locMax{}, gloMax{nums[0]};
        for (int a: nums) {
            locMin = min (a, locMin + a);
            gloMin = min (locMin, gloMin);
    
            locMax = max (a, locMax + a);
            gloMax = max (locMax, gloMax);
            total += a;
        }
        
        return gloMax > 0 ? max(total - gloMin, gloMax) : gloMax;
    }
};
