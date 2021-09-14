class Solution {
private:
    int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> cache(image.size(), vector<bool>(image[0].size(),false));
        dfs(image, sr, sc, image[sr][sc], newColor, cache);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc,  int oldColor, int newColor, vector<vector<bool>>& cache) {
        if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0) return;
        if (cache[sr][sc]) return;
        cache[sr][sc] = true;
        
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            for (auto [r, c]:dirs) {
                dfs(image, sr+r, sc+c, oldColor, newColor ,cache);
            }
        }
    }
};
