class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        // Compute the transpose of the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Swap Columns of the matrix
        for (int j = 0; j < n / 2; ++j) {
            for (int i = 0; i < n ; ++i) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};
