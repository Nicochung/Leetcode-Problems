class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // Check if dimension is legal or not
        int m = mat.size(), n = mat[0].size();
        if (m * n  != r * c) return mat;
        vector<vector<int>> ans(r,vector<int>(c,0));
        int cnt{0},r2{-1}, c2{0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cnt % c == 0) {
                    ++r2;
                    c2 = 0;
                }
                ans[r2][c2++] = mat[i][j];
                ++cnt;
            }
        }
        return ans;
    }
};
