class Solution {
public:
    // int jump(vector<int>& nums) {
    //     return helper(nums, nums.size() - 1);
    // }
    // // Helper to find first index to pos
    // int helper(vector<int>& nums, int pos) {
    //     if (pos <= 0) return 0;
    //     for (int i = 0; i < pos; ++i) {
    //         if (nums[i] + i >= pos)
    //             return 1 + helper(nums, i);
    //     }
    //     return 0;
    // }
    
    /*
    The basic idea is DP solution.

    We use 2 variables to keep track of moving:

    prevDist: record the furthest postion we can reach

    curDist: record the next furthest postion we can reach based on the current postion

    If prevDist < i, which means current position is unreachable. Then, we just update prevDist = curDist, in other words, we jump to the postion which help us move furthest. We keep moving util prevDist < n - 1.
    */
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;
        
        int prevDist = -1, curDist = nums[0], count = 0;
        for(int i = 0; i < n; i++) {
            if(i > prevDist) {
                prevDist = curDist;
                ++count;
            }
            
            if(prevDist >= n - 1)
                return count;
            
            int newPos = i + nums[i];
            if(newPos > curDist)
                curDist = newPos;
        }
        return count;
    }
};
