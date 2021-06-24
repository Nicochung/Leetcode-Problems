class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carryOn = false;
        int n = digits.size() - 1;
        if (digits[n] + 1 >= 10) {
            carryOn = true;
            digits[n] = 0;
            --n;
        } else {
            digits[n] += 1;
        }
        while (carryOn && n >= 0) {
            if (digits[n] + 1 >= 10) {
                carryOn = true;
                digits[n] = 0;
                --n;
            } else{
                digits[n] += 1;
                carryOn = false;
            }
        }
        if (carryOn)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
