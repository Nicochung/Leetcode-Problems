class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int min = firstOccurrence(nums, target);
        int max = lastOccurrence(nums, target);
        return {min, max};
    }
    
    int firstOccurrence(vector<int>& nums, int target) {
        int start{0}, end = nums.size();
        int pos{-1};
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                pos = mid;
                end = mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return pos;
    }
    
    int lastOccurrence(vector<int>& nums, int target) {
        int start{0}, end = nums.size();
        int pos{-1};
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                pos = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return pos;        
    }
};
