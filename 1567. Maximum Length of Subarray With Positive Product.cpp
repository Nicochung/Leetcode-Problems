class Solution {
public:
int getMaxLen(vector<int>& nums) {
        int pos{0}, neg{0}, ans{0};
        for(int x : nums) {
            if (x == 0){
                pos = 0;
                neg = 0;
            } else if (x < 0) {
				int temp = pos;
                pos = neg ? neg + 1 : 0;
                neg = temp + 1;
            } else {
                if (neg) neg++;
                pos++;
            }    
            ans = max(ans, pos);
        }
        return ans;
    }
};
