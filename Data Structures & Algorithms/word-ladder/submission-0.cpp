class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> store;
        for(string &wl:wordList) {
            store[wl] = INT_MAX;
        }
        if(!store.contains(endWord)) return 0;
        priority_queue<pair<int,string>> pending;
        store[beginWord] = 1;
        pending.emplace(1, beginWord);
        while(!pending.empty()) {
            pair<int,string> cur = pending.top();
            pending.pop();
            if(cur.first > store[cur.second]) continue;
            cout << cur.second << endl;
            for(int i = 0; i < cur.second.size(); ++i) {
                string tmp = cur.second;
                for(char c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if(tmp == endWord) return cur.first + 1;
                    if(store.contains(tmp) && store[tmp] > cur.first + 1) {
                        cout << "-> " << tmp << endl;
                        store[tmp] = cur.first + 1;
                        pending.emplace(cur.first + 1, tmp);
                    }
                }
            }
            cout << cur.second << endl;
        }
        return store[endWord] == INT_MAX ? 0 : store[endWord];
    }
};
