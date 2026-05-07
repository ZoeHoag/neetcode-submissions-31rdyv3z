class Solution {
public:
    bool isAvailable(int target, int days, vector<int>& weights) {
        int tmp = target;
        for(int i = 0; i < weights.size(); ++i) {
            if(tmp >= weights[i]) {
                tmp -= weights[i];
            } else {
                --days;
                --i;
                tmp = target;
            }
        }
        if(tmp != target) --days;
        return days >= 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1, right = 0;
        for(int &w: weights) {
            left = max(w,left);
            right += w;
        }
        int tar = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(isAvailable(mid, days, weights)) {
                cout << mid << endl;
                tar = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return tar;
    }
};