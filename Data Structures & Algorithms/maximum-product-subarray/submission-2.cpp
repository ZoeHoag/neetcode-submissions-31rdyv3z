class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // [2,4,-3,5,6, -1]
        // [2,8,-18,-90,-540, 540]
        // -4 -4 12 12 -24 -240
        int res = nums[0], cur = 1, res1 = nums[0], bot = 0;
        for(int &n: nums) {
            res1 = max(res1, n);
            if(n == 0) {
                bot = 0;
                cur = 1;
                continue;
            }

            cur *= n;

            if(cur < 0) {
                if(bot == 0) bot = cur;
                else res = max(res, cur/bot);
            } else res = max(res, cur);
            
        }
        return max(res, res1);
    }
};
