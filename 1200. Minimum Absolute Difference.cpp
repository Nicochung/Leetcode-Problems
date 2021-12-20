class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 1, curMin = INT_MAX; i < arr.size(); ++i) {
            int diff = arr.at(i) - arr.at(i-1);
            if (diff < curMin) {
                curMin = arr.at(i) - arr.at(i-1);
                ans.clear();
                ans.emplace_back(vector<int>{arr.at(i-1), arr.at(i)});
            } else if (diff == curMin) {
                ans.emplace_back(vector<int>{arr.at(i-1), arr.at(i)});
            }
        }
        return ans;
    }
};
