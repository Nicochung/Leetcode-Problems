class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int> op: ops) {
            int x = op[0];
            int y = op[1];
            if (x < m) m = x;
            if (y < n) n = y;
        }
        return m*n;
    }
};
