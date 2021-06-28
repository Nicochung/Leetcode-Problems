class Solution {
public:
    int lengthOfLastWord(string s) {
        // Remove all trailing space
        size_t found = s.find_last_not_of(' ');
        if (found != string::npos)
            s.erase(found+1);
        else
            s.clear();            // s is all whitespace
        // Look for location of last space
        size_t lastSpace = s.find_last_of(' ');
        // No space char
        if (lastSpace == string::npos)
            return s.size();
        return s.size() - lastSpace - 1;
    }
};
