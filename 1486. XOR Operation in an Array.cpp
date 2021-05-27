class Solution {
public:
    int xorOperation(int n, int start) {
        int answer = start;
        for (int i = 1; i < n; ++i) {
            answer ^= (start + i * 2);
        }
        return answer;
    }
};
