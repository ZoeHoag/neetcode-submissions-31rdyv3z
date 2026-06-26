class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 0 1 2 3 4 5 3 3 3 6
        vector<vector<int>> store(nums.size(), vector<int>(nums.size(), 1));
        int res = 1;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                store[i][j] = store[i - 1][j];
                if(nums[i] > nums[j]) {
                    store[i][i] = max(store[i - 1][j] + 1, store[i][i]);
                    res = max(res, store[i][i]);
                }
            }
        }
        return res;
    }
};
