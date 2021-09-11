class Solution {
public:
    string reverseWords(string s) {
        int space{-1};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(next(s.begin(),space+1), next(s.begin(),i));
                space = i;
            }
        }
        reverse(next(s.begin(),space+1), s.end());
        return s;
    }
};
