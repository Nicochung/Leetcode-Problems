class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - ('A'-'a');
            }
        }
        return s;
    }
};
