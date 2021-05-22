class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string answer (s.size(),' ');
        for (int i = 0 ; i < indices.size(); ++i) {
            answer[indices[i]] = s[i];
        }
        return answer;
    }
};

/* Inplace
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < indices.size();) {
            if (indices[i] == i) {
                ++i;
                continue;
            }
            swap(s[i],s[indices[i]]);
            swap(indices[i],indices[indices[i]]);
        }
        return s;
    }
};
*/
