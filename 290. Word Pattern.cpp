class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mymap{};
        set<string> myset{};
        vector<string> words = splitString(s, " ");

        if (pattern.length() != words.size()) return false;
        
        for (int i = 0, length = pattern.length(); i < length; ++i) {
            char letter = pattern[i];
            if (mymap.find(letter) != mymap.end()) {
                // already exist, check if same as one store in map
                if (mymap[letter] != words[i]) return false;
                myset.insert(words[i]);
            } else {
                // Check if word is duplicate for different letter
                if (myset.find(words[i]) != myset.end()) return false;
                mymap[letter] = words[i];
                myset.insert(words[i]);
            }
        }
        return true;
    }
    
    vector<string> splitString(string s, string delimiter) {
        vector<string> words{};
        size_t pos = 0;
        while ((pos = s.find(delimiter)) != string::npos) {
            words.emplace_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.length());
        }
        words.emplace_back(s);
        return words;
    }
};
