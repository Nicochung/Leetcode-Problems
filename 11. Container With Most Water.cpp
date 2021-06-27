class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        while (i < j) {
            int minHeight = min(height[i], height[j]);
            int dist = j - i;
            ans = max(ans, minHeight * dist);
            if (height[i] < height[j])
                ++i;
            else
                --j;
        } 
        return ans;
    }
};
