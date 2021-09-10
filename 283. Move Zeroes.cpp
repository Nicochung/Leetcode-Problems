class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroAt{0};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroAt++] = nums[i];
            }
        }
        for (int i = lastNonZeroAt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
    
    // void moveZeroes(vector<int>& nums) {
    //     for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
    //         if (nums[cur] != 0) {
    //             swap(nums[lastNonZeroFoundAt++], nums[cur]);
    //         }
    //     }
    // }
};
