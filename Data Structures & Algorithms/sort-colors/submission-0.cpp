class Solution {
public:
// 2 1 0 1 2 0 1 1 0 0 1 2 2 2 => z = 0, o = 0
// 1 2 0 1 2 0 1 1 0 0 1 2 2 2 => z = 0, o = 1
// 0 1 2 1 2 0 1 1 0 0 1 2 2 2 => z = 1, o = 2
// 0 1 1 2 2 0 1 1 0 0 1 2 2 2 => z = 1, o = 3
// 0 0 1 1 2 2 1 1 0 0 1 2 2 2 => z = 2, o = 4
    void sortColors(vector<int>& nums) {
        int z = 0, o = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                if(z > o) o = z;
                swap(nums[i], nums[o++]);
            } else if(nums[i] == 0) {
                swap(nums[i], nums[z++]);
                if(o != 0) {
                    swap(nums[i], nums[o++]);
                }
            }
        }
    }
};