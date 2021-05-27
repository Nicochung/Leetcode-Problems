class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt{}, answer{};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L') 
                cnt++;
            else 
                cnt--;
            if (cnt == 0) 
                answer++;
        }
        return answer;
    }
};
