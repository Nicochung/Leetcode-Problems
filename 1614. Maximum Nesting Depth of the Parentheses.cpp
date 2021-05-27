class Solution {
public:
    int maxDepth(string s) {
        int answer{}, cnt{};
        for (char a: s) {
            if (a == '(')
                cnt++;
            else if (a == ')')
                cnt--;
            if (cnt > answer)
                answer = cnt;
        }
        return answer;
    }
};
