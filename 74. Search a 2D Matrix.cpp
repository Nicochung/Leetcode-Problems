class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // locate the position of target
        int i{};
        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] > target) break;
        }
        // Smaller than the smallest number in the matrix, not found
        if (i == 0) return false;
        
        // B-search in row i - 1
        int start = 0;
        int end = matrix[i-1].size()-1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[i-1][mid] == target) return true;
            if (matrix[i-1][mid] > target) end = mid - 1;
            else start = mid + 1;
        }  
        return false;
    }
};
