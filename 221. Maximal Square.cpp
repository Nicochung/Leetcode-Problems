class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int window_size = max(matrix.size(), matrix[0].size());
        for (int window = window_size; window >= 0; --window) {
            for (int i = 0; i + window <= matrix.size(); ++i) {
                for (int j = 0; j + window <= matrix[0].size(); ++j) {
                    bool allOne{true};
                    for (int k = i; k - i < window; ++k) {
                        for (int w = j; w - j < window; ++w) {
                            if (matrix[k][w] == '0') {
                                allOne = false;
                                break;
                            }
                        }
                        if (!allOne)
                            break;
                    }
                    if (allOne)
                        return window*window;
                }
            }
        }
        return 0;
    }
};
