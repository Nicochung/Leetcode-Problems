class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        bool endFlag = false;
        for (int i = 0, m = haystack.size(), window = needle.size(); i < m - window + 1; ++i) {
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < window; ++j) {
                    if (haystack[i+j] != needle[j])
                        break;
                    if (j == window - 1)
                        endFlag = true;
                }
            }
            if (endFlag)
                return i;
        }
        return -1;
    }
};
