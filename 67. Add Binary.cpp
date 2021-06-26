class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = a.size() - 1;
        int m = b.size() - 1;
        bool carryOn = false;
        while (n >= 0 && m >= 0) {
            if (carryOn) {
                if (a[n] == '1' && b[m] == '1') {
                    ans += '1';
                } else if (a[n] == '1' || b[m] == '1') {
                    ans += '0';
                } else {
                    ans += '1';
                    carryOn = false;                    
                }
            } else {
                if (a[n] == '1' && b[m] == '1') {
                    ans += '0';
                    carryOn = true;
                } else if (a[n] == '1' || b[m] == '1') {
                    ans += '1';
                } else {
                    ans += '0';             
                }
            }
            --n;
            --m;
        }
        while (n >= 0) {
            if (carryOn) {
                if (a[n] == '0') {
                    ans += '1';
                    carryOn = false;
                } else {
                    ans += '0';
                }
            } else {
                if (a[n] == '0') {
                    ans += '0';
                } else {
                    ans += '1';
                }                
            }
            --n;
        }
        while (m >= 0) {
            if (carryOn) {
                if (b[m] == '0') {
                    ans += '1';
                    carryOn = false;
                } else {
                    ans += '0';
                }
            } else {
                if (b[m] == '0') {
                    ans += '0';
                } else {
                    ans += '1';
                }                
            }
            --m;
        }
        if (carryOn)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
