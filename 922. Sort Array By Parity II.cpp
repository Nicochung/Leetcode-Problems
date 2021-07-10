class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            // Find the first number which is mismatch with the index from the start
            while (i < j && ((i%2) && (nums[i]%2) || !(i%2) && !(nums[i]%2))) {
                ++i;
            }
            // Now i is in the position where it is incorrect
            // Look for the first element from the back which can be swap with i
            if (i%2) {
                // Look for odd number
                while (j > i && !(nums[j]%2)) {
                    --j;
                }
            } else {
                // Look for even number
                while (j > i && (nums[j]%2)) {
                    --j;
                }
            }
            if (i < j) swap(nums[i], nums[j]);
            // Reset index j for searching from the back
            j = nums.size() - 1;
        }
        return nums;        
    }
};
