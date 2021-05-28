class Solution {
public:
    bool isRobotBounded(string instructions) {
        int LRMove{}, FBMove{};
        bool L{false}, R{false}, F{true}, B{false};
        for (char instruction: instructions) {
            if (instruction == 'G') {
                if (L)
                    LRMove++;
                else if (R)
                    LRMove--;
                else if (F)
                    FBMove++;
                else if (B)
                    FBMove--;
            } else if (instruction == 'L') {
                if (L) {
                    L = false;
                    B = true;
                } else if (R) {
                    R = false;
                    F = true;
                } else if (F) {
                    F = false;
                    L = true;
                } else if (B) {
                    B = false;
                    R = true;
                }
            } else {
                if (L) {
                    L = false;
                    F = true;
                } else if (R) {
                    R = false;
                    B = true;
                } else if (F) {
                    F = false;
                    R = true;
                } else if (B) {
                    B = false;
                    L = true;
                }
            }
        }
        // The robot stays in the circle iff (looking at the final vector) it changes direction (ie. doesn't stay pointing north), or it moves 0.
        if (!LRMove && !FBMove || !F)
            return true;
        return false;
    }
};
