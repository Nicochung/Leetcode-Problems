class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int>::iterator it = unique(nums.begin(), nums.end());
        // return it-nums.begin();
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1, n = nums.size(); j < n; ++j) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
