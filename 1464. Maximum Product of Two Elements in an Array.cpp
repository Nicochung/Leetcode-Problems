class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x{0},y{1};  // x: second biggest index,  y: biggest index
        if (nums[x] > nums[y]){ // Ensure y holds the larger index
            swap(x,y);
        }
        for (int i = 2, n = nums.size(); i < n; ++i) {
            if (nums[i] >= nums[y]) { // If greater than biggest update biggest and second biggest
                x = y;
                y = i;
            } else if (nums[i] >= nums[x] && nums[i] <= nums[y]) { //else if in between 1st 2nd, update 2nd
                x = i;
            }
        }
        return (nums[x]-1) * (nums[y]-1);
    }
};
