class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        bool breakFlag = false;
        for (int i = 0; i < strs[0].size(); ++i) {
            string prefix = strs[0].substr(0,i+1);
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].find(prefix, 0) != 0) {
                    breakFlag = true;
                    break;
                }
            }
            if (breakFlag)
                break;
            ans = prefix;
        }
        return ans;
    }
};
