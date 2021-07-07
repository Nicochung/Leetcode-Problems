class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cache(26,0);
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); ++i) {
            ++cache[s[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cache[i] == 1) {
                // Compare the index
                int temp = s.find(i+'a');
                ans = min(ans, temp);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
