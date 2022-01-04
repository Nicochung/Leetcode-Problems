class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        
        bitset<32> binary(n);
        // Find the first 1 to get
        int firstOne = binary.to_string().find('1');
        binary.flip();
        // Get the complement in string form
        for (int i = 31; i > 31 - firstOne; --i) {
            binary.reset(i);
        }
        return binary.to_ulong();
    }
};
