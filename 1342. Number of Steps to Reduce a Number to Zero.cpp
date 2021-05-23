class Solution {
public:
    int numberOfSteps(int num) {
        int answer {};
        while (num > 0) {
            if (num % 2 == 1) {
                num -= 1;
            } else {
                num /= 2;
            }
            answer++;
        }
        return answer;
    }
};

// log2(num) gives the number of steps to shift the most significant bit to 2^0 (no. of / 2 operations), bitset<32>(num).count() gives the no.of 1s, and equal to the number of -1 operations
/* Counting bits
class Solution {
public:
    int numberOfSteps (int num) {
      return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
    }
};
*/
