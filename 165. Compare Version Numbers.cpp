class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = splitString(version1, '.');
        vector<string> v2 = splitString(version2, '.');
        int size1 = v1.size();
        int size2 = v2.size();
        int n = min(size1,size2);
        int i = 0;
        for (i = 0; i < n; ++i) {
            int i1 = stoi(v1[i]);
            int i2 = stoi(v2[i]);
            if (i1 > i2) return 1;
            else if (i1 < i2) return -1;
        }
        if (size1 > size2) {
            while (i < size1) {
                if (v1[i++] != "0")
                    return 1;
            }
        }
        if (size2 > size1) {
            while (i < size2) {
                if (v2[i++] != "0")
                    return -1;
            }
        }
        return 0;
    }
    
    vector<string> splitString(string s1, char delimiter) {
        vector<string> result;
        string temp = "";
        for (char s : s1) {
            if (s == delimiter && !temp.empty()) {
                result.emplace_back(removeLeadingZero(temp));
                temp = "";
            } else {
                temp += s;
            }
        }
        result.emplace_back(removeLeadingZero(temp));
        return result;
    }
    
    string removeLeadingZero(string s1) {
        if (s1.size() == 1) return s1;
        string temp = "";
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == '0' && temp.empty()) {
                continue;
            } else {
                temp += s1[i];
            }
        }
        if (temp.empty()) return "0";
        return temp;
    }
};
