class Solution {
private:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea{0}, area{0};
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    area = 0;
                    dfs(grid, i, j, area, maxArea, visited);
                }
            }
        }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& area, int& maxArea, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (grid[i][j] == 0) return;
        maxArea = max(++area,maxArea);
        for (auto [r,c]: dirs) {
            dfs(grid, i+r, j+c, area, maxArea, visited);
        }
    }
    
};
