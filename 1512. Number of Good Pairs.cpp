class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        int answer = 0;
        int count[100] = { };
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]-1]++;
        }
        for (int i = 0; i < 100; ++i) {
            if (count[i] == 1 || count[i] == 0) continue;
            int times = (count[i] * (count[i]-1)) / 2;
            answer += times;
        }
        return answer;
    }
};
