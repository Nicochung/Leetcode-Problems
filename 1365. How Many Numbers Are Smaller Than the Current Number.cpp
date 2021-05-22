class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) return nums;
        vector<int> cache (101,0);
        vector<int> answer (nums.size(),0);
        for (int i = 0 ; i < nums.size(); ++i) {
            cache[nums[i]]++;
        }
        for (int i = 1; i < cache.size(); ++i) {
            cache[i] += cache[i-1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            answer[i] = cache[nums[i]-1];
        }
        return answer;
    }
};
