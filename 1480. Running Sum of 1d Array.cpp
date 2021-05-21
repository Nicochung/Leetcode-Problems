class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> answer (n, 0);
        answer[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i-1] + nums[i];
        }
        return answer;
    }
};
