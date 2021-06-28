class Solution {
// private:
//     int cache[46] = {0};
// public:
//     int climbStairs(int n) {
//         if (cache[n] != 0) return cache[n];
//         if (n <= 2) {
//             cache[n] = n;
//             return n;
//         }
//         cache[n] = climbStairs(n-1) + climbStairs(n-2);
//         return cache[n];
//     }
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int first{1}, second{2}, third{};
        for (int i = 3; i <= n; ++i) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};
