class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, res = nums[0];
        for(int &num: nums) {
            res = max(res, num);
            cur += num;
            if(cur < 0) cur = 0;
            else {
                res = max(res, cur);
            }
        }
        return res;
    }
};
