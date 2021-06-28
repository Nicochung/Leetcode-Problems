class Solution {
public:
    int romanToInt(string s) {
        int ans{};
        map<char, int> cache;
        cache['I'] = 1;
        cache['V'] = 5;
        cache['X'] = 10;
        cache['L'] = 50;
        cache['C'] = 100;
        cache['D'] = 500;
        cache['M'] = 1000;
        for (int i = 0; i < s.size(); ++i) {
            // Case for last digit
            if (i + 1 >= s.size()) {
                ans += cache[s[i]];
                break;
            }
            
            if (s[i] == 'I') {
                if (s[i+1] == 'V') {
                    ans += 4;
                    ++i;
                } else if (s[i+1] == 'X') {
                    ans += 9;
                    ++i;
                } else {
                    ans += 1;
                }
            } else if (s[i] == 'X') {
                if (s[i+1] == 'L') {
                    ans += 40;
                    ++i;
                } else if (s[i+1] == 'C') {
                    ans += 90;
                    ++i;
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'C') {
                if (s[i+1] == 'D') {
                    ans += 400;
                    ++i;
                } else if (s[i+1] == 'M') {
                    ans += 900;
                    ++i;
                } else {
                    ans += 100;
                }
            } else {
                ans += cache[s[i]];
            }
        }
        return ans;
    }
};
