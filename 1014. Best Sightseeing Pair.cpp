class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = values[0] + values[1] - 1, maxVal{values[0] > values[1] + 1 ? values[0] : values[1] + 1};
        for (int k = 2 ; k < values.size(); ++k) {
            int tempScore = values[k] - k + maxVal;
            maxVal = max(maxVal, values[k] + k);
            maxScore = max(maxScore, tempScore);
        } 
        return maxScore;
    }
};
