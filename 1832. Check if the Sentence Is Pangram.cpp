class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alphabet (26, false);
        for (int i = 0; i < sentence.size(); ++i) {
            alphabet[sentence[i]-'a'] = true;
        }
        for (int i = 0; i < 26; ++i) {
            if (!alphabet[i])
                return false;
        }
        return true;
    }
};
