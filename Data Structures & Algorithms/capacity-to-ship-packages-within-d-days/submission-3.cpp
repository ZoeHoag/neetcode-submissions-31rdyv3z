class Solution {
public:
    bool isEnable(vector<int>& weights, int days, int weight) {
        int total = 0;
        int tmp = weight;
        for(int &w: weights) {
            if(w <= tmp) {
                tmp -= w;
            } else {
                ++total;
                tmp = weight;
                tmp -= w;
            }
        }
        if(tmp != weight) ++total;
        return total <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = weights[0], right = 0;
        for(int &w: weights) {
            left = max(left, w);
            right += w;
        }

        while(left <= right) {
            int mid = (left + right) >> 1;
            if(isEnable(weights, days, mid)) {
                right = mid - 1;
                cout << mid << endl;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};