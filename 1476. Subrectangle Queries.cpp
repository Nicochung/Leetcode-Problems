class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        for (vector<int> a: rectangle) {
            this->answer.emplace_back(a);
        }
        this->rows = rectangle.size() - 1;
        this->cols = rectangle[0].size() - 1;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        if (row1 < 0 || row2 < 0 || col1 < 0 || col2 < 0 || newValue < 0 || row1 > row2 || col1 > col2) return;
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                answer[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        if (row > rows || row < 0 || col > cols || col < 0) return - 1;
        return answer[row][col];
    }
private:
    vector<vector<int>> answer{};
    int rows{}, cols{};
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
