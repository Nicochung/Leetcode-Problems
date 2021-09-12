class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowBin(9,vector<bool>(9,false)), columnBin(9,vector<bool>(9,false)), boxBin(9,vector<bool>(9,false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int boxIndex = boxEncoding(i, j);
                if (rowBin[i][num] | columnBin[j][num] | boxBin[boxIndex][num]) return false;
                rowBin[i][num] = true;
                columnBin[j][num] = true;
                boxBin[boxIndex][num] = true;
            }
        } 
        return true;
    }
    
    int boxEncoding (int i, int j) {
        i /= 3;
        j /= 3;
        if (i == 0) {
            if (j == 0) return 0;
            if (j == 1) return 1;
            if (j == 2) return 2;
        }
        if (i == 1) {
            if (j == 0) return 3;
            if (j == 1) return 4;
            if (j == 2) return 5;
        }
        if (i == 2) {
            if (j == 0) return 6;
            if (j == 1) return 7;
            if (j == 2) return 8;
        }
        return -1;
    }
};
