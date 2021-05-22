class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if (jewels.empty() || stones.empty()) return 0;
        int answer{};
        for (int i = 0; i < jewels.size(); ++i) {
            answer += count(stones.begin(), stones.end(), jewels[i]);
        }
        return answer;
    }
};
