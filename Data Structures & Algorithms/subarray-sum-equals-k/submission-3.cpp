class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        store[0] = 1;
        int total = 0;
        int res = 0;
        for(int &num: nums) {
            total += num;
            res += store[total - k];
            ++store[total];
        }
        return res;
    }

    // 0 2  1 2 4
    // 0 8 16, 24, 15 17
};