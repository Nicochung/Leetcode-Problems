class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m + 1, vector<int> (n + 1, 0));
        return helper(m, n, cache);
    }
    int helper(int m,int n, vector<vector<int>> &cache) {
        if (cache[m][n] != 0) return cache[m][n];
        if (m == 1 || n == 1) return 1;
        int left = helper(m-1, n, cache);
        int right = helper(m, n-1, cache);
        cache[m][n] = left + right;
        return cache[m][n];        
    }
};
