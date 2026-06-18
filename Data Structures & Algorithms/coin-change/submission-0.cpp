class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(int &c: coins) {
                if(i - c < 0) break;
                if(res[i - c] == INT_MAX) continue;
                res[i] = min(res[i], res[i - c] + 1);
            }
        }
        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};
