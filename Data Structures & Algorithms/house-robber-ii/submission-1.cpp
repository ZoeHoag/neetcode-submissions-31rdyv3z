class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<bool> hasFirst(nums.size(), false);
        vector<int> previous(nums.size(), 0);
        hasFirst[0] = true;
        previous[0] = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            int temp = nums[i];
            bool temp_b = false;
            if(i - 3 >= 0) {
                temp = nums[i] + previous[i - 3];
                if(i == nums.size() - 1 && hasFirst[i - 3]) {
                    temp -= min(nums[0], nums[i]);
                }
                temp_b = hasFirst[i - 3];
            }
            if(i - 2 >= 0) {
                int h2 = nums[i] + previous[i - 2];
                if(i == nums.size() - 1 && hasFirst[i - 2]) {
                    h2 -= min(nums[i], nums[0]);
                }
                if(h2 == temp) {
                    temp_b = hasFirst[i - 2] && hasFirst[i - 1];
                } else if(h2 > temp) {
                    temp = h2;
                    temp_b = hasFirst[i - 2];
                }
            }
            previous[i] = temp;
            hasFirst[i] = temp_b;
        }
        for(auto &a: previous) {
            cout << a << " ";
        }

        return max(previous[nums.size() - 1], previous[nums.size() - 2]);
        // if(hasFirst[nums.size() - 1]) {
        //     int tmp = previous[nums.size() - 1] - min(nums[0], nums[nums.size() - 1]);
        //     return max(tmp, previous[nums.size() - 2]);
        // } else {
        //     return max(previous[nums.size() - 1], previous[nums.size() - 2]);
        // }
    }
};
