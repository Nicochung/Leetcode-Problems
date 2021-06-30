class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start{0}, end = nums.size();
        while (start < end) {
            int mid = start + (end-start) / 2;
            if (target == nums[mid])
                return mid;
            // there exists rotation; the middle element is in the left part of the array
            if (nums[mid] > nums[end-1]) {
                // if target lies between the left region, update the end
                // else update the start
                if (target < nums[mid] && target >= nums[start])
                    end = mid;
                else
                    start = mid + 1;
            }
            // there exists rotation; the middle element is in the right part of the array
            else if (nums[mid] < nums[start]) {
                // if target lies between the right region, update the start
                // else update the end;
                if (target > nums[mid] && target <= nums[end-1])
                    start = mid + 1;
                else
                    end = mid;
            }
            // there is no rotation; just like normal binary search
            else {
                if (target < nums[mid])
                    end = mid;
                else
                    start = mid + 1;
            }
        }
        return -1;
        
    }
};
