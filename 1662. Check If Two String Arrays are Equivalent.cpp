class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp{};
        int index{};
        int len2{};
        for (int i = 0; i < word1.size(); ++i) {
            for (int j = 0; j < word1[i].size(); ++j) {
                temp += word1[i][j];
            }
        }
        for (int i = 0; i < word2.size(); ++i) {
            for (int j = 0; j < word2[i].size(); ++j) {
                if (word2[i][j] != temp[index++])
                    return false;
                len2++;
            }
        }
        if (len2 != temp.size())
            return false;
        return true;
    }
};
