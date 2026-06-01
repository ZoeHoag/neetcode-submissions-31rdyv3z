class Solution {
public:
    bool ishaving(vector<string>& deadends, string str) {
        for(string &de: deadends) {
            if(de == str) return true;
        }
        return false;
    }

    int openLock(vector<string> deadends, string target) {
        vector store(10000, INT_MAX);
        vector directs {1, -1};
        queue<pair<string, int>> pending;
        if(ishaving(deadends, "0000") || ishaving(deadends, target)) return -1;
        pending.emplace("0000", 0);
        int res = INT_MAX;
        while(!pending.empty()) {
            pair<string,int> cur = pending.front();
            int cur_int = stoi(cur.first);
            pending.pop();
            if(cur.second >= store[cur_int]) continue;
            store[cur_int] = cur.second;
            if(cur.first == target) {
                res = min(res, store[cur_int]);
                continue;
            }
            for(int i = 0; i < 4; ++i) {
                for(int& d: directs) {
                    string tmp = cur.first;
                    tmp[i] = char((tmp[i] - '0' + d + 10) % 10 + '0');
                    if(cur.second + 1 >= store[stoi(tmp)] || ishaving(deadends, tmp)) continue;
                    pending.emplace(tmp, cur.second + 1);
                }
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};