class Solution {
public:
    bool isPalindrome(int x) {
        // Revert only half of the digits to avoid overflow
        // Edge case for x < 0, last digit being 0 (for non zero)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reverted{};
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        // For Even digits number / for odd digits number
        return reverted == x || x == reverted / 10;
    }
};
