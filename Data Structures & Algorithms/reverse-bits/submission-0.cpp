class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; ++i) {
            int temp = n & 1;
            res <<= 1;
            res |= temp;
            n >>= 1;
        }
        return res;
    }
};
