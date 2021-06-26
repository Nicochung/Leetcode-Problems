// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> sorted_array (nums.begin(), nums.end());
//         sort(sorted_array.begin(),sorted_array.end());
//         int i{}, j = nums.size() - 1;
//         while (i < j) {
//             int temp = sorted_array[i] + sorted_array[j];
//             if (temp == target) {
//                 break;
//             } else if (temp > target) {
//                 --j;
//             } else {
//                 ++i;
//             }
//         }
        
//         // Find the index of the element in the original array
//         vector<int>::iterator index1;
//         index1 = find(nums.begin(), nums.end(), sorted_array[i]);
//         int i1 = index1 - nums.begin();
        
//         int i2 = 0;
//         for (int k = nums.size()-1; k >= 0; --k) {
//             if (nums[k] == sorted_array[j]) {
//                 i2 = k;
//                 break;
//             }
//         }
//         return vector<int>{i1, i2};
//     }
// };

// Hash Table method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        map<int,int> hash_table;
        map<int,int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = target - nums[i];
            it = hash_table.find(temp);
            // Not found in hash table
            if (it == hash_table.end()) {
                // Add the current number (nums[i]) to the hash table
                hash_table[nums[i]] = i;
            } else {
                // If found set the answer and break 
                ans[0] = i;
                ans[1] = hash_table[temp];
                break;
            }
        }
        return ans;
    }
};
