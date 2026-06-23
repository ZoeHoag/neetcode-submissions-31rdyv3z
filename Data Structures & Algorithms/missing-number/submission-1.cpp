class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size(); ++i) {
            pos ^= i ^ nums[i]; 
        }
        return pos^ (int)nums.size();
    }
};
