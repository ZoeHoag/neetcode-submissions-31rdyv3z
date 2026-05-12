class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int total = 0;
        bool inIncrease = true;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] < prices[i - 1]) {
                if(inIncrease) total += (prices[i - 1] - buy);
                inIncrease = false;
                buy = prices[i];
            } else {
                if(i == prices.size() - 1) total += (prices[i] - buy);
                inIncrease = true;
            }
        }
        return total;
    }
};