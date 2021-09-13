class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int maxNum{INT_MAX};
        
        vector<int> hashTable (26,0);
    
        for (int i = 0; i < text.size(); ++i) {
            ++hashTable[text[i] - 'a'];
        }
        // balloon
        // b = 1, a = 1, l = 2, o = 2, n = 1
        for (int i = 0; i < 26; ++i) {
            if (i == 'b' - 'a' || i == 'a' - 'a' || i == 'n' - 'a') {
                maxNum = min(hashTable[i], maxNum);
            } else if (i == 'l' - 'a' || i == 'o' - 'a') {
                maxNum = min(hashTable[i]/2, maxNum);
            }
        }
        if (maxNum == INT_MAX) return 0;
        return maxNum;
        
        
    }
};
