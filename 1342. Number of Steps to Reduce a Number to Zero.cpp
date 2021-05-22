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

/* Counting bits
class Solution {
public:
    int numberOfSteps (int num) {
      return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
    }
};
*/
