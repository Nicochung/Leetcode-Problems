class Solution {
public:
    static bool cmp(int a, int b) {
        if ((a%2) && !(b%2))
            return false;
        if (!(a%2) && (b%2))
            return true;
        // Can introduce the following to handle odd or even number ascending/decending order
        // if (a%2 && b%2)
        //     return a > b;
        return a < b;
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};
