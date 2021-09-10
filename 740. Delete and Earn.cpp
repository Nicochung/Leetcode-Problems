class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> bucket(10001,0);
        // Skip one if we pick M, similar to House robber problem
        for (int num: nums) {
            bucket[num] += num;
        }
        // nums[i] represent the maximum point possible at this index
        // nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < bucket.size() ; i++) {
            bucket[i] = max(bucket[i-1], bucket[i-2] + bucket[i]);
        }
        return bucket.back();
    }
};
