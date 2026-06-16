class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step1 = cost[0], step2 = cost[1];
        for(int i = 2; i < cost.size(); ++i) {
            int tmp = min(step1, step2) + cost[i];
            step1 = step2;
            step2 = tmp;
        }
        return min(step1, step2);
    }
};
