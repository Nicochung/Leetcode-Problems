class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {  
        int answer{};
        for (int window = 0; window < arr.size(); window += 2) {
            for (int j = 0; j + window < arr.size(); ++j) {
                for (int k = j; k - j <= window; ++k) {
                    answer += arr[k];
                }
            }
        }
        return answer;
    }
};
