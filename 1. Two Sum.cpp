class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_array (nums.begin(), nums.end());
        sort(sorted_array.begin(),sorted_array.end());
        int i{}, j = nums.size() - 1;
        while (i < j) {
            int temp = sorted_array[i] + sorted_array[j];
            if (temp == target) {
                break;
            } else if (temp > target) {
                --j;
            } else {
                ++i;
            }
        }
        
        // Find the index of the element in the original array
        vector<int>::iterator index1;
        index1 = find(nums.begin(), nums.end(), sorted_array[i]);
        int i1 = index1 - nums.begin();
        
        int i2 = 0;
        for (int k = nums.size()-1; k >= 0; --k) {
            if (nums[k] == sorted_array[j]) {
                i2 = k;
                break;
            }
        }
        return vector<int>{i1, i2};
    }
};
