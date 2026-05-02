class StockSpanner {
public:
    stack<pair<int,int>> pending;
    StockSpanner() {
    }
    
    int next(int price) {
        int count = 1;
        while(!pending.empty() && pending.top().first <= price) {
            count += pending.top().second;
            pending.pop();
        }
        pending.emplace(price, count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */