// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         set<vector<int>> mySet;
//         for (int i = 0; i < nums.size(); ++i) {
//             int j = i + 1, k = nums.size() - 1;
//             while (j < k) {
//                 if (nums[i] + nums[j] + nums[k] == 0) {
//                     mySet.emplace(vector<int>{nums[i], nums[j], nums[k]});
//                     ++j;
//                     --k;
//                 } else if (nums[i] + nums[j] + nums[k] > 0) {
//                     --k;
//                 } else {
//                     ++j;
//                 }
//             }
//         }
//         return vector<vector<int>>(mySet.begin(),mySet.end());
//     }
// };
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            // if there is duplicate of an element in an array then simply go to the next element
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    // if nums[low] has a duplicate value the simply increment the value of low 
                    int val1 = nums[j];
                    while(j < k && nums[j] == val1) j++;
                
                    // if nums[high] has a duplicate value the simply decrement the value of high
                    int val2 = nums[k];
                    while(j < k && nums[k] == val2) k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
};
