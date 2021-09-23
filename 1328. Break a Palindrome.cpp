class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        bool onlyA{true};
        int firstNonA{-1};
        int numNonA{0};
        for (int i = 0; i < n; ++i) {
            if (palindrome[i] != 'a' && firstNonA == -1) {
                firstNonA = i;
                ++numNonA;
            } else if(palindrome[i] != 'a') {
                ++numNonA;
            }
        }
        if (numNonA > 1) palindrome[firstNonA] = 'a';
        else palindrome[n-1] = 'b';
        return palindrome;
    }
};
