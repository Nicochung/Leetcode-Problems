class Solution {
public:
//     static bool cmp(int a, int b) {
//         if ((a%2) && !(b%2))
//             return false;
//         if (!(a%2) && (b%2))
//             return true;
//         // Can introduce the following to handle odd or even number ascending/decending order
//         // if (a%2 && b%2)
//         //     return a > b;
//         return a < b;
//     }
    
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), cmp);
//         return nums;
//     }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            // Find the first odd number from the start
            while (i < j && !(nums[i] % 2)) {
                ++i;
            }
            // Find the first even number from the end
            while (j > i && (nums[j] % 2)) {
                --j;
            }
            if (i < j)
                swap(nums[i], nums[j]);
        }
        return nums;
    }
};
