class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashTable(26,0);
        for (char a: s) {
            ++hashTable[a-'a'];
        }
        
        for (char b: t) {
            --hashTable[b-'a'];
        }
        
        for (int occur:hashTable) {
            if (occur != 0) return false;
        }
        return true;        
    }
};
