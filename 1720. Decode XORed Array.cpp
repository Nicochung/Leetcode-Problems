class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> answer (encoded.size()+1, 0);
        answer[0] = first;
        for (int i = 1; i < answer.size(); ++i) {
            answer[i] = answer[i-1] ^ encoded[i-1];
        }
        return answer;
    }
};
