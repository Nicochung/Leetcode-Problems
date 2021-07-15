class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool first{false}, second{false}, third{false};
        for (int i = 0; i < arr.size(); ++i) {
            bool isOdd = arr[i] % 2;
            if (!first && isOdd) {
                first = true;
            } else if (!second && isOdd) {
                second = true;
            } else if (!third && isOdd) {
                return true;   
            } else {
                first = false;
                second = false;
            }   
        }
        return first && second && third;
    }
};
