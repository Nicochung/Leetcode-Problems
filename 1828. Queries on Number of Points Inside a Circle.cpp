class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer (queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int cnt{};
            for (int j = 0; j < points.size(); ++j) {
                int x_diff = queries[i][0] - points[j][0];
                int y_diff = queries[i][1] - points[j][1];
                int radius = queries[i][2];
                int distance = radius * radius - x_diff * x_diff - y_diff * y_diff;
                if (distance >= 0)
                    cnt++;
            }
            answer[i] = cnt;
        }
        return answer;
    }
};
