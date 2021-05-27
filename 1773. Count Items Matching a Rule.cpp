class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key_index = 2;
        int answer = 0;
        if (ruleKey == "type") {
            key_index = 0;
        } else if (ruleKey == "color") {
            key_index = 1;
        }
        for (vector<string> item: items) {
            if (item[key_index] == ruleValue) {
                answer++;
            }
        }
        return answer;
    }
};
