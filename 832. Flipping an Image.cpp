class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(image[i][j], image[i][n-j-1]);
                image[i][j] = helper(image[i][j]);
                image[i][n-j-1] = helper(image[i][n-j-1]);
            }
            if (n % 2) image[i][n/2] = helper(image[i][n/2]);
        }
        return image;
    }
    int helper (int x) {
        if (!x) return 1;
        return 0;
    }
};
