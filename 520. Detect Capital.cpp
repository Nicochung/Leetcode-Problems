class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCnt{};
        for (char a: word) {
            if (isupper(a))
                capCnt++;
        }
        if (!capCnt || capCnt == word.size() || capCnt == 1 && isupper(word[0])) return true;
        return false;
    }
};
