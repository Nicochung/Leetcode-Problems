class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans{};
        int power = columnTitle.size()-1;
        for (int i = 0; i < columnTitle.size(); ++i, --power) {
            ans += pow(26,power) * (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};
