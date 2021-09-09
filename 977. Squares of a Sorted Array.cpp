class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer {};
        int start{0}, end = nums.size()-1;
        while (start <= end) {
            int l = nums[start] * nums[start];
            int r = nums[end] * nums[end];
            if (l < r) {
                answer.emplace_back(r);
                --end;
            } else {
                answer.emplace_back(l);
                ++start;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
