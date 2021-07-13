class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid == 0) {
                // Check rhs to see if peak
                if (nums[mid] > nums[mid+1])
                    return mid;
                start = mid + 1;
                continue;
            }
            if (mid == nums.size()-1) {
                // Check lhs to see if peak
                if (nums[mid] > nums[mid-1])
                    return mid;
                end = mid;
                continue;
            }
            // Identify the gradient. if positive one peak on the right, if negative one peak must on left, if Valley, doesnt matter move left or right
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
                start = mid + 1;
            else 
                end = mid;
        }
        return -1;
    }
};
