class Solution {
public:
    int mySqrt(int x) {
        int left{1}, right{x};
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid == mid) return mid;
            if (x / mid > mid) left = mid + 1;
            else right = mid -1;
        }
        return left-1;
    }
};
