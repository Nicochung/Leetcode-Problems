class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hashTable(26,0);
        for (char a: magazine) {
            ++hashTable[a-'a'];
        }
        
        for (char b: ransomNote) {
            if (hashTable[b-'a'] == 0) return false;
            --hashTable[b-'a'];
        }
        return true;
    }
};
