class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int answer = 0;
        if (accounts.empty()) return answer;
        
        for (vector<int> a: accounts) {
            int sum = 0;
            for (int b : a) {
                sum += b;
            }
            if (sum > answer)
                answer = sum;
        }
        return answer;
    }
};
