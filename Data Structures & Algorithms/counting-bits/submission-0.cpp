class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int temp = i;
            while(temp > 0) {
                if(temp & 1) ++res[i];
                temp >>= 1;
            }
        }
        return res;
    }
};
 