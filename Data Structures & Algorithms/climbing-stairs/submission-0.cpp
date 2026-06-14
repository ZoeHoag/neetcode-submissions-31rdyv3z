class Solution {
public:
    int climbStairs(int n) {
        int n1 = 2, n2 = 3;
        if(n <= 3) return n;
        for(int i = 4; i < n; ++i) {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }
        return n1 + n2;
    }
};
