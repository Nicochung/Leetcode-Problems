class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
        while (cache.find(n) == cache.end()) {
            cache.emplace(n);
            int temp{};
            while (n) {
                int digit = n % 10;
                n /= 10;
                temp += digit*digit;
            }
            if (temp == 1) return true;
            n = temp;
        }
        return false;
    }
};
