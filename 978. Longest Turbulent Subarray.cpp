class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans{1}, maxVal{1};
        int nextSign{0};
        for (int i = 1; i < arr.size(); ++i) {
            if (nextSign == 0) {
                if (arr[i] == arr[i-1]) 
                    continue;
                if (arr[i] > arr[i-1]) {
                    nextSign = -1;
                } else {
                    nextSign = 1;
                }
                ++ans;
            } else if (nextSign >= 1) {
                if (arr[i] == arr[i-1]) {
                    ans = 1;
                    nextSign = 0;
                } else if (arr[i] < arr[i-1]) {
                    ans = 2;
                    nextSign = 1;
                } else {
                    ++ans;
                    nextSign = -1;
                }
            } else {
                if (arr[i] == arr[i-1]) {
                    ans = 1;
                    nextSign = 0;
                } else if (arr[i] > arr[i-1]) {
                    ans = 2;
                    nextSign = -1;
                } else {
                    ++ans;
                    nextSign = 1;
                }                
            }
            maxVal = max(maxVal, ans);
        }
        return maxVal;
    }
};
