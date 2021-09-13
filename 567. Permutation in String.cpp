class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> hT1(26,0), hT2(26,0);
        
        for (char a: s1) {
            ++hT1[a-'a'];
        }
        
        for (int i = 0 ; i < s1.size(); ++i) {
            ++hT2[s2[i]-'a'];
        }
        if (helper(hT1,hT2)) return true;
        
        for (int i = 1; i < s2.size() - s1.size() + 1; ++i) {
            --hT2[s2[i-1]-'a'];
            ++hT2[s2[i+s1.size()-1]-'a'];
            if (helper(hT1,hT2)) return true; 
        }
        return false;
    }
    
    bool helper(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};
